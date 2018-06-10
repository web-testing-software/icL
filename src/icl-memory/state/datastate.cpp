#include "datastate.h"

#include "../structures/element.h"

namespace icL::memory {

DataState::DataState() = default;

/**
 * @brief DataState::setValue
 * @param name - the name of variable
 * @param value - the value of variable
 */
void DataState::setValue(const QString & name, const QVariant & value) {
	dataMap.insert(name, value);
}

/**
 * @brief DataState::contains
 * @param name - the name of variable
 * @return if the data unit contains the needed variables
 */
bool DataState::contains(const QString & name) {
	return dataMap.contains(name);
}

/**
 * @brief DataState::getType
 * @param name - the name of variable
 * @return the type of variable (js types need aditional checking)
 */
Type DataState::getType(const QString & name) {
	return variantTypeToType(dataMap[name].type());
}

/**
 * @brief DataState::checkType
 * @param name - the name of varible
 * @param type - the type
 * @return the variable type check the type
 */
bool DataState::checkType(const QString & name, Type & type) {
	bool ret;

	switch (type) {
	case Type::Boolean:
		ret = dataMap[name].type() == QVariant::Bool;
		break;

	case Type::Int:
		ret = dataMap[name].type() == QVariant::Int;
		break;

	case Type::Double:
		ret = dataMap[name].type() == QVariant::Double;
		break;

	case Type::String:
		ret = dataMap[name].type() == QVariant::String;
		break;

	case Type::List:
		ret = dataMap[name].type() == QVariant::StringList;
		break;

	case Type::Element:
		ret = dataMap[name].canConvert<Element>();
		break;

	default:
		ret = false;
	}

	return ret;
}

/**
 * @brief DataState::getValue
 * @param name - the variable name
 * @return the variable value
 */
QVariant DataState::getValue(const QString & name) {
	return dataMap[name];
}

}  // namespace icL::memory
