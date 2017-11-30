#include "datastate.h"

#include <system/functions/webelement.h>

vm::main::DataState::DataState () {

}

void vm::main::DataState::addToStringList (const QString &name, QString &value) {
	if (dataMap.contains (name)) {
		QStringList tmp = dataMap [name].toStringList ();
		tmp.append (value);
		dataMap [name] = QVariant (tmp);
	}
	else {
		// TODO: Set driver to error state
	}
}

void vm::main::DataState::setValue (const QString &name, QVariant value) {
	dataMap [name] = value;
}

bool vm::main::DataState::contains (const QString &name) {
	return dataMap.contains (name);
}

vm::main::DataState::Type vm::main::DataState::getType (const QString &name) {
	Type ret = Type::INVALID;

	switch (dataMap[name].type ()) {
	case QVariant::Bool:
		ret = Type::BOOLEAN;
		break;

	case QVariant::Int:
		ret = Type::INT;
		break;

	case QVariant::Double:
		ret = Type::DOUBLE;
		break;

	case QVariant::String:
		ret = Type::STRING;
		break;

	case QVariant::StringList:
		ret = Type::STRING_LIST;
		break;

	case QVariant::UserType:
		ret = Type::WEB_ELEMENT;
		break;

	default:
		break;
	}

	return ret;
}

bool vm::main::DataState::checkType (const QString &name, vm::main::DataState::Type &type) {
	bool ret;

	switch (type) {
	case Type::BOOLEAN :
		ret = dataMap [name].type () == QVariant::Bool;
		break;

	case Type::INT :
		ret = dataMap [name].type () == QVariant::Int;
		break;

	case Type::DOUBLE :
		ret = dataMap [name].type () == QVariant::Double;
		break;

	case Type::STRING :
		ret = dataMap [name].type () == QVariant::String;
		break;

	case Type::STRING_LIST :
		ret = dataMap [name].type () == QVariant::StringList;
		break;

	case Type::WEB_ELEMENT :
		ret = dataMap [name].canConvert <WebElement> ();
		break;

	default :
		ret = false;
	}

	return ret;
}

QVariant vm::main::DataState::getValue (const QString &name) {
	return dataMap [name];
}
