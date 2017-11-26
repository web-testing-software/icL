#include "datastate.h"

vm::main::DataState::DataState () {

}

void vm::main::DataState::setBoolean (const QString &name, bool &value) {
	boolMap [name] = value;
}

void vm::main::DataState::setInt (const QString &name, int &value) {
	intMap [name] = value;
}

void vm::main::DataState::setDouble (const QString &name, double &value) {
	doubleMap [name] = value;
}

void vm::main::DataState::setString (const QString &name, QString &value) {
	stringMap [name] = value;
}

void vm::main::DataState::setStringList (const QString &name, QStringList &value) {
	stringListMap [name] = value;
}

void vm::main::DataState::addToStringList (const QString &name, QString &value) {
	if (stringListMap.contains (name)) {
		stringListMap [name].append (value);
	}
}

bool vm::main::DataState::contains (const QString &name) {
	return boolMap.contains (name) ||
		   intMap.contains (name) ||
		   doubleMap.contains (name) ||
		   stringMap.contains (name) ||
		   stringListMap.contains (name);
}

vm::main::DataState::Type vm::main::DataState::getType (const QString &name) {
	Type ret = Type::INVALID;

	if (boolMap.contains (name)) {
		ret = Type::BOOLEAN;
	}
	else if (intMap.contains (name)) {
		ret = Type::INT;
	}
	else if (doubleMap.contains (name)) {
		ret = Type::DOUBLE;
	}
	else if (stringMap.contains (name)) {
		ret = Type::STRING;
	}
	else if (stringListMap.contains (name)) {
		ret = Type::STRING_LIST;
	}

	return ret;
}

bool vm::main::DataState::checkType (const QString &name, vm::main::DataState::Type &type) {
	bool ret;

	switch (type) {
	case Type::BOOLEAN :
		ret = boolMap.contains (name);
		break;

	case Type::INT :
		ret = intMap.contains (name);
		break;

	case Type::DOUBLE :
		ret = doubleMap.contains (name);
		break;

	case Type::STRING :
		ret = stringMap.contains (name);
		break;

	case Type::STRING_LIST :
		ret = stringListMap.contains (name);
		break;

	default :
		ret = false;
	}

	return ret;
}

QVariant vm::main::DataState::getValue (const QString &name) {
	QVariant ret;

	if (boolMap.contains (name)) {
		ret = QVariant(boolMap[name]);
	}
	else if (intMap.contains (name)) {
		ret = QVariant(intMap[name]);
	}
	else if (doubleMap.contains (name)) {
		ret = QVariant(doubleMap[name]);
	}
	else if (stringMap.contains (name)) {
		ret = QVariant(stringMap[name]);
	}
	else if (stringListMap.contains (name)) {
		ret = QVariant(stringListMap[name]);
	}

	return ret;
}
