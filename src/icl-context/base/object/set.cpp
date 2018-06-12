#include "set.h"

#include "boolean.h"
#include "int.h"

#include <QHash>
#include <QStringBuilder>

namespace icL::context::object {

Set::Set(
  memory::InterLevel * il, memory::DataState * container,
  const QString & varName)
	: Object(il, container, varName) {}

Set::Set(memory::InterLevel * il, const QVariant & rvalue, bool readonly)
	: Object(il, rvalue, readonly) {}

const QHash<QString, void (Set::*)()> Set::properties = Set::initProperties();

const QHash<QString, void (Set::*)(memory::ArgList &)> Set::methods =
  Set::initMethods();

const QHash<QString, void (Set::*)()> Set::initProperties() {
	return {{{"Length", &Set::runLength}, {"Empty", &Set::runEmpty}}};
}

const QHash<QString, void (Set::*)(memory::ArgList &)> Set::initMethods() {
	return {{{"Insert", &Set::runInsert},
			 {"Merge", &Set::runMerge},
			 {"Remove", &Set::runRemove},
			 {"Ref", &Set::runRef}}};
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
	newContext = new Boolean(il, newValue, true);
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

	set.table->reserve(set.table->count() + size * 1.1f);

	for (i = 0; i < size; i++) {
		QVariantList row = {};

		for (j = 0; j < list.size(); j++) {
			QString value;

			if (list[j].size() > 0) {
				value = list[j][i % list[j].size()];
			}

			std::pair<QVariant, bool> res = {{}, false};

			switch ((*set.header)[j].type) {
			case memory::Type::Boolean:
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
				   "SetObj can contains values of type Boolean, Int, Double, "
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

		QString key = getId(row);

		set.table->insert(key, row);
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

	if (
	  value_type != memory::Type::Boolean && value_type != memory::Type::Int &&
	  value_type != memory::Type::Double &&
	  value_type != memory::Type::String && value_type != memory::Type::List) {
		il->vm->exception({-1213,
						   "SetObj can contains values of type Boolean, Int, "
						   "Double, String, List. But given " +
							 memory::typeToString(value_type)});
	}

	new_set.header =
	  std::make_shared<memory::ParamList>(memory::ParamList{*old_set.header});
	new_set.table = std::make_shared<memory::Table>(memory::Table{});

	new_set.header->append(memory::Parameter{name, value_type});
	new_set.table->reserve(old_set.table->count() * 1.1f);

	for (QVariantList row : *old_set.table) {
		QString key;

		row.append(value);
		key = getId(row);

		new_set.table->insert(key, row);
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
	new_set.table->reserve(old_set.table->count() * 1.1f);

	for (QVariantList row : *old_set.table) {
		QString key;

		row.removeAt(index);
		key = getId(row);

		new_set.table->insert(key, row);
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
	new_set.table->reserve(old_set.table->count() * 1.1f);

	for (QVariantList row : *old_set.table) {
		row[index] = row.at(index).toStringList().join(separator);

		QString key = getId(row);

		new_set.table->insert(key, row);
	}

	setValue(QVariant::fromValue(new_set));
}

void Set::insert(const QVariantList & row) {
	memory::SetPtr set = getValue().value<memory::SetPtr>();

	if (!checkRow(set, row)) {
		return;
	}

	QString id = getId(row);

	set.table->insert(id, row);
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
	}

	for (auto it = set2.table->begin(); it != set2.table->end(); ++it) {
		if (!set1.table->contains(it.key())) {
			set1.table->insert(it.key(), it.value());
		}
	}
}

void Set::remove(const QVariantList & row) {
	memory::SetPtr set = getValue().value<memory::SetPtr>();

	if (!checkRow(set, row)) {
		return;
	}
	QString id = getId(row);

	set.table->remove(id);
}

void Set::clear() {
	memory::SetPtr old_set = getValue().value<memory::SetPtr>();
	memory::SetPtr new_set = {};

	new_set.header =
	  std::make_shared<memory::ParamList>(memory::ParamList{*old_set.header});
	new_set.table = std::make_shared<memory::Table>(memory::Table{});

	setValue(QVariant::fromValue(new_set));
}

memory::SetObjPtr Set::ref(const QVariantList & row) {
	memory::SetPtr    set = getValue().value<memory::SetPtr>();
	memory::SetObjPtr ret;

	if (!checkRow(set, row)) {
		return ret;
	}
	QString id = getId(row);

	if (set.table->contains(id)) {
		il->vm->exception({-1210, "No such value in the set."});
		return ret;
	}

	ret.set = set;
	ret.key = id;

	return ret;
}

void Set::runApplicate(memory::ArgList & args) {}

void Set::runInsertField(memory::ArgList & args) {}

void Set::runRemoveField(memory::ArgList & args) {}

void Set::runConcatFields(memory::ArgList & args) {}

void Set::runLists(memory::ArgList & args) {}

void Set::runInsert(memory::ArgList & args) {
	//
}

void Set::runMerge(memory::ArgList & args) {}

void Set::runRemove(memory::ArgList & args) {}

void Set::runRef(memory::ArgList & args) {}

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

QString Set::getId(const QVariantList & row) {
	QStringList strlist;

	strlist.reserve(row.length());

	for (const QVariant & var : row) {
		if (var.type() == var.StringList) {
			strlist.append(var.toStringList().join("|"));
		}
		else {
			strlist.append(var.toString());
		}
	}

	return strlist.join(",");
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

Context * Set::runProperty(Prefix prefix, const QString & name) {}

Context * Set::runMethod(const QString & name, memory::ArgList & args) {}

memory::Type Set::type() const {}

bool Set::toBoolean() {}

int Set::toInt() {}

double Set::toDouble() {}

const QString Set::toString() {}

const QStringList Set::toList() {}

}  // namespace icL::context::object
