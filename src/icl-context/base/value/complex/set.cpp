#include "set.h"

#include "../base/bool.h"
#include "../base/int.h"
#include "../base/void.h"
#include "setobject.h"

#include <icl-vm/errors.h>

#include <QHash>
#include <QStringBuilder>

namespace icL::context::value {

Set::Set(
  memory::InterLevel * il, memory::DataState * container,
  const QString & varName)
	: Value(il, container, varName) {}

Set::Set(memory::InterLevel * il, const QVariant & rvalue, bool readonly)
	: Value(il, rvalue, readonly) {}

const QHash<QString, void (Set::*)()> Set::properties = Set::initProperties();

const QHash<QString, void (Set::*)(memory::ArgList &)> Set::methods =
  Set::initMethods();

const QHash<QString, void (Set::*)()> Set::initProperties() {
	return {{{"length", &Set::runLength}, {"empty", &Set::runEmpty}}};
}

const QHash<QString, void (Set::*)(memory::ArgList &)> Set::initMethods() {
	return {{{"applicate", &Set::runApplicate},
			 {"insertField", &Set::runInsertField},
			 {"removeField", &Set::runRemoveField},
			 {"concatLists", &Set::runConcatLists},
			 {"insert", &Set::runInsert},
			 {"merge", &Set::runMerge},
			 {"remove", &Set::runRemove},
			 {"removeAt", &Set::runRemoveAt},
			 {"clear", &Set::runClear},
			 {"at", &Set::runAt}}};
}

int Set::length() {
	memory::SetPtr set = getValue().value<memory::SetPtr>();

	return set.table->count();
}

bool Set::empty() {
	memory::SetPtr set = getValue().value<memory::SetPtr>();

	return set.table->empty();
}

void Set::runLength() {
	newValue   = length();
	newContext = new Int(il, newValue, true);
}

void Set::runEmpty() {
	newValue   = length();
	newContext = new Bool(il, newValue == 0, true);
}

void Set::appplicate(const QList<QStringList> & list) {
	memory::SetPtr set = getValue().value<memory::SetPtr>();

	if (set.header->size() != list.size()) {
		il->vm->exception(
		  {-1211,
		   "Wrong applicate args (the number of fields are not matched)."});
		return;
	}

	int size = list[0].size();

	for (int i = 1; i < list.size(); i++) {
		int new_size = list[i].size();

		if (new_size > size) {
			size = new_size;
		}
	}

	int i, j;

	// Stop double loop on error
	auto stop = [&i, &j, &size, &list]() {
		i = size;
		j = list.size();
	};

	for (i = 0; i < size; i++) {
		QVariantList row = {};

		for (j = 0; j < list.size(); j++) {
			QString value;

			if (list[j].size() > 0) {
				value = list[j][i % list[j].size()];
			}

			std::pair<QVariant, bool> res = {{}, false};

			switch ((*set.header)[j].type) {
			case memory::Type::Bool:
				res = parseToBool(value.isEmpty() ? "false" : value);
				break;

			case memory::Type::Int:
				res = parseToInt(value.isEmpty() ? "0" : value);
				break;

			case memory::Type::Double:
				res = parseToDouble(value.isEmpty() ? "0.0" : value);
				break;

			case memory::Type::String:
				res = {value, true};
				break;

			case memory::Type::List:
				res = {value.isEmpty() ? QStringList{} : QStringList{} << value,
					   true};
				break;

			default:
				il->vm->exception(
				  {-1213,
				   "SetObj can contains values of type bool, Int, Double, "
				   "String, List. But given " +
					 memory::typeToString((*set.header)[j].type)});
			}

			if (res.second) {
				row.append(res.first);
			}
			else {
				stop();
			}
		}

		if (!set.table->contains(row)) {
			set.table->append(row);
		}
	}
}

void Set::insertField(const QString & name, const QVariant & value) {
	memory::SetPtr old_set = getValue().value<memory::SetPtr>();
	memory::SetPtr new_set = {};

	memory::Type value_type = memory::variantTypeToType(value);

	for (const memory::Parameter & param : *old_set.header) {
		if (param.name == name) {
			il->vm->exception(
			  {-1212, "A field with name `" % name % "` already exists."});
			return;
		}
	}

	if (!isSetType(value_type)) {
		return;
	}

	new_set.header =
	  std::make_shared<memory::ParamList>(memory::ParamList{*old_set.header});
	new_set.table = std::make_shared<memory::Table>(memory::Table{});

	new_set.header->append(memory::Parameter{name, value_type});

	for (QVariantList row : *old_set.table) {
		QString key;

		row.append(value);

		if (!new_set.table->contains(row)) {
			new_set.table->append(row);
		}
	}

	setValue(QVariant::fromValue(new_set));
}

void Set::removeField(const QString & name) {
	memory::SetPtr old_set = getValue().value<memory::SetPtr>();
	memory::SetPtr new_set = {};

	int index = indexOf(name, old_set);

	if (index == -1) {
		return;
	}

	if (old_set.header->size() == 1) {
		il->vm->exception({-1215, "The last field cannot be removed."});
		return;
	}

	new_set.header =
	  std::make_shared<memory::ParamList>(memory::ParamList{*old_set.header});
	new_set.table = std::make_shared<memory::Table>(memory::Table{});

	new_set.header->removeAt(index);

	for (QVariantList row : *old_set.table) {
		row.removeAt(index);
		new_set.table->append(row);
	}

	setValue(QVariant::fromValue(new_set));
}

void Set::concatLists(const QString & name, const QString & separator) {
	memory::SetPtr old_set = getValue().value<memory::SetPtr>();
	memory::SetPtr new_set = {};
	int            index   = indexOf(name, old_set);

	if (index == -1) {
		return;
	}

	if ((*old_set.header)[index].type != memory::Type::List) {
		il->vm->exception(
		  {-1216, "The field type must be List, given " %
					memory::typeToString((*old_set.header)[index].type) % '.'});
		return;
	}

	new_set.header =
	  std::make_shared<memory::ParamList>(memory::ParamList{*old_set.header});
	new_set.table = std::make_shared<memory::Table>(memory::Table{});

	(*new_set.header)[index].type = memory::Type::String;

	for (QVariantList row : *old_set.table) {
		row[index] = row.at(index).toStringList().join(separator);

		new_set.table->append(row);
	}

	setValue(QVariant::fromValue(new_set));
}

void Set::insert(const QVariantList & row) {
	memory::SetPtr set = getValue().value<memory::SetPtr>();

	if (!checkRow(set, row)) {
		return;
	}

	if (!set.table->contains(row)) {
		set.table->append(row);
	}
}

void Set::merge(const memory::SetPtr & set2) {
	memory::SetPtr            set1    = getValue().value<memory::SetPtr>();
	const memory::ParamList & params1 = *set1.header;
	const memory::ParamList & params2 = *set2.header;

	bool ok = true;

	if (params1.size() != params2.size()) {
		ok = false;
	}

	for (int i = 0; i < params1.size(); i++) {
		if (params1[i].type != params2[i].type) {
			ok = false;
		}
	}

	if (!ok) {
		il->vm->exception(
		  {-1209, "Failed to merge the sets, they are icompatible."});
		return;
	}

	for (const auto & it : *set2.table) {
		if (!set1.table->contains(it)) {
			set1.table->append(it);
		}
	}
}

void Set::remove(const QVariantList & row) {
	memory::SetPtr set = getValue().value<memory::SetPtr>();

	if (!checkRow(set, row)) {
		return;
	}

	set.table->removeOne(row);
}

void Set::removeAt(int index) {
	memory::SetPtr set = getValue().value<memory::SetPtr>();

	if (index < 0) {
		index = set.table->length() + index;  // index < 0 here
	}

	if (index < 0 && index >= set.table->length()) {
		il->vm->exception({errors::OutOfBounds, "Out of set bounds."});
	}
	else {
		set.table->removeAt(index);
	}
}

void Set::clear() {
	memory::SetPtr old_set = getValue().value<memory::SetPtr>();
	memory::SetPtr new_set = {};

	new_set.header =
	  std::make_shared<memory::ParamList>(memory::ParamList{*old_set.header});
	new_set.table = std::make_shared<memory::Table>(memory::Table{});

	setValue(QVariant::fromValue(new_set));
}

memory::SetObjPtr Set::at(int index) {
	memory::SetPtr    set = getValue().value<memory::SetPtr>();
	memory::SetObjPtr ret;

	if (index < 0 || index >= set.table->length()) {
		il->vm->exception({errors::OutOfBounds, "Out of set bounds."});
		return ret;
	}

	ret.set = set;
	ret.id  = index;

	return ret;
}

void Set::runApplicate(memory::ArgList & args) {
	for (const auto & arg : args) {
		if (arg.object->type() != memory::Type::List) {
			sendWrongArglist(args, "<list ...>");
			return;
		}
	}

	QList<QStringList> list;

	for (const auto & arg : args) {
		list.append(arg.object->getValue().toStringList());
	}

	appplicate(list);
	newContext = new Void{il};
}

void Set::runInsertField(memory::ArgList & args) {
	if (args.length() == 2 && args[0].object->type() == memory::Type::String) {
		if (isSetType(args[1].object->type())) {
			insertField(
			  args[0].object->getValue().toString(),
			  args[1].object->getValue());
			newContext = new Void{il};
		}
	}
	else {
		sendWrongArglist(args, "<string, bool|int|double|string|list>");
	}
}

void Set::runRemoveField(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		removeField(args[0].object->getValue().toString());
		newContext = new Void{il};
	}
	else {
		sendWrongArglist(args, "<string>");
	}
}

void Set::runConcatLists(memory::ArgList & args) {
	if (
	  args.length() == 2 && args[0].object->type() == memory::Type::String &&
	  args[1].object->type() == memory::Type::String) {
		concatLists(
		  args[0].object->getValue().toString(),
		  args[1].object->getValue().toString());
		newContext = new Void{il};
	}
}

void Set::runInsert(memory::ArgList & args) {
	for (const auto & arg : args) {
		if (!isSetType(arg.object->type())) {
			return;
		}
	}

	QVariantList list;

	for (const auto & arg : args) {
		list.append(arg.object->getValue());
	}

	insert(list);
	newContext = new Void{il};
}

void Set::runMerge(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::Set) {
		merge(args[0].object->getValue().value<memory::SetPtr>());
		newContext = new Void{il};
	}
	else {
		sendWrongArglist(args, "<set>");
	}
}

void Set::runRemove(memory::ArgList & args) {
	for (const auto & arg : args) {
		if (!isSetType(arg.object->type())) {
			return;
		}
	}

	QVariantList list;

	for (const auto & arg : args) {
		list.append(arg.object->getValue());
	}

	remove(list);
	newContext = new Void{il};
}

void Set::runRemoveAt(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::Int) {
		removeAt(args[0].object->getValue().toInt());
		newContext = new Void{il};
	}
	else {
		sendWrongArglist(args, "<int>");
	}
}

void Set::runClear(memory::ArgList & args) {
	if (args.length() == 0) {
		clear();
		newContext = new Void{il};
	}
	else {
		sendWrongArglist(args, "<>");
	}
}

void Set::runAt(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::Int) {
		newValue = QVariant::fromValue(at(args[0].object->getValue().toInt()));
		newContext = new SetObject{il, newValue};
	}
	else {
		sendWrongArglist(args, "<int>");
	}
}

bool Set::checkRow(const memory::SetPtr & set, const QVariantList & row) {
	const memory::ParamList & params = *set.header;

	if (params.size() != row.size()) {
		il->vm->exception(
		  {-1207, "Wrong set value (the number of filds are not matching)."});
		return false;
	}

	for (int i = 0; i < params.size(); i++) {
		if (params[i].type != memory::variantTypeToType(row[i])) {
			il->vm->exception(
			  {-1208,
			   "Wrong set value (the field " % params[i].name %
				 " has the type " % memory::typeToString(params[i].type) %
				 ", but the assigned value has the type " %
				 memory::typeToString(memory::variantTypeToType(row[i])) %
				 ")"});
			return false;
		}
	}

	return true;
}

int Set::indexOf(const QString & name, const memory::SetPtr & set) {
	int index = -1;

	for (int i = 0; i < set.header->size(); i++) {
		if ((*set.header)[i].name == name) {
			index = i;
		}
	}

	if (index == -1) {
		il->vm->exception({-1214, "The field `" % name % "` not found."});
	}

	return index;
}

bool Set::isSetType(memory::Type type) {
	if (
	  type != memory::Type::Bool && type != memory::Type::Int &&
	  type != memory::Type::Double && type != memory::Type::String &&
	  type != memory::Type::List) {
		return true;
	}

	il->vm->exception({-1213,
					   "<set> can contains values of type <bool>, <int>, "
					   "<double>, <string> and <list>. But given " %
						 memory::typeToString(type)});
	return false;
}

Context * Set::runProperty(Prefix prefix, const QString & name) {
	newContext = nullptr;

	if (prefix != Prefix::None) {
		il->vm->exception(
		  {-405, "<set> objects are not support for prefixed properties"});
	}
	else {
		auto it = properties.find(name);

		if (it != properties.end()) {
			(this->*it.value())();
		}
		else {
			Value::runProperty(prefix, name);
		}
	}

	return newContext;
}

Context * Set::runMethod(const QString & name, memory::ArgList & args) {
	auto it = methods.find(name);

	newContext = nullptr;
	if (it != methods.end()) {
		(this->*it.value())(args);
	}
	else {
		Value::runMethod(name, args);
	}

	return newContext;
}

memory::Type Set::type() const {
	return memory::Type::Set;
}

bool Set::toBool() {
	sendWrongCast("bool");
	return false;
}

int Set::toInt() {
	sendWrongCast("int");
	return 0;
}

double Set::toDouble() {
	sendWrongCast("double");
	return 0;
}

const QString Set::toString() {
	sendWrongCast("string");
	return {};
}

const QStringList Set::toList() {
	sendWrongCast("list");
	return {};
}

}  // namespace icL::context::value
