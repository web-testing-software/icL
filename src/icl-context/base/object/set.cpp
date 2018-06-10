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

memory::SetObjPtr Set::ref(const QVariantList & row) {
	memory::SetPtr set = getValue().value<memory::SetPtr>();
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

void Set::runInsert(memory::ArgList & args) {}

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

Context * Set::runProperty(Prefix prefix, const QString & name) {}

Context * Set::runMethod(const QString & name, memory::ArgList & args) {}

memory::Type Set::type() const {}

bool Set::toBoolean() {}

int Set::toInt() {}

double Set::toDouble() {}

const QString Set::toString() {}

const QStringList Set::toList() {}

}  // namespace icL::context::object
