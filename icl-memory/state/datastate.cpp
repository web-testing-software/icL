#include "datastate.h"
#include "../structures/webelement.h"

namespace vm::memory {

DataState::DataState () = default;


/**
 * @brief DataState::addToStringList - despercated
 * @param name
 * @param value
 */
void DataState::addToStringList (const QString &name, QString &value) {
	if (dataMap.contains (name)) {
		QStringList tmp = dataMap [name].toStringList ();
		tmp.append (value);
		dataMap [name] = QVariant (tmp);
	}
	else {
		// TODO: Set driver to error state
	}
}

/**
 * @brief DataState::setValue
 * @param name - the name of variable
 * @param value - the value of variable
 */
void DataState::setValue (const QString &name, QVariant &value) {
	dataMap [name] = value;
}

/**
 * @brief DataState::contains
 * @param name - the name of variable
 * @return if the data unit contains the needed variables
 */
bool DataState::contains (const QString &name) {
	return dataMap.contains (name);
}

/**
 * @brief DataState::getType
 * @param name - the name of variable
 * @return the type of variable (js types need aditional checking)
 */
Type DataState::getType (const QString &name) {
	Type ret = Type::NODATA;

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
		ret = Type::LIST;
		break;

	case QVariant::UserType:
		ret = Type::ELEMENT;
		break;

	default:
		break;
	}

	return ret;
}

/**
 * @brief DataState::checkType
 * @param name - the name of varible
 * @param type - the type
 * @return the variable type check the type
 */
bool DataState::checkType (const QString &name, Type &type) {
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

	case Type::LIST :
		ret = dataMap [name].type () == QVariant::StringList;
		break;

	case Type::ELEMENT :
		ret = dataMap [name].canConvert <WebElement> ();
		break;

	default :
		ret = false;
	}

	return ret;
}

/**
 * @brief DataState::getValue
 * @param name - the variable name
 * @return the variable value
 */
QVariant DataState::getValue (const QString &name) {
	return dataMap [name];
}

}
