#include "logic.h"

namespace icL::logic {

Logic::Logic(memory::InterLevel * il)
	: memory::Node(il){};


/**
 * @brief Logic::getResult - calculate the result and save it to the
 * resultValue
 * @return calcResult()
 */
bool Logic::getResult() {
	bool result = false;

	if (resultValue == ResultValue::NOT_CALCULATED) {
		result = this->calcResult();
		resultValue =
		  result ? ResultValue::TRUE_VALUE : ResultValue::FALSE_VALUE;
	}

	return result;
}

bool Logic::getCachedResult() {
	if (resultCalculed) {
		return result;
	}

	return getResult();
}

/**
 * @brief Logic::resetResultValue - set the resultValue to "not calculated"
 */
void Logic::resetResultValue() {
	resultValue = ResultValue::NOT_CALCULATED;
}

/**
 * @brief Logic::invalidate - set the
 */
void Logic::invalidate() {
	resultValue = ResultValue::WRONG_INPUT_DATA;
}

bool Logic::canResultPreliminarily() {
	return false;
}

/**
 * @brief Logic::getParent - node parent getter
 * @return pointer to the parent node
 */
Logic * Logic::getParent() {
	return m_parent;
}

/**
 * @brief Logic::setParent - parent node setter
 * @param pointer to the parent node
 */
void Logic::setParent(Logic * parent) {
	m_parent = parent;
}

/**
 * @brief Logic::typeToString - Convert types to string, special for errors
 * messages.
 * @param type - the result of QVariant.type()
 * @return a string with icL type name
 */
QString Logic::typeToString(QVariant::Type type) {
	QString ret;

	switch (type) {
	case QVariant::Bool:
		ret = QStringLiteral("Boolean");
		break;

	case QVariant::Int:
		ret = QStringLiteral("Int");
		break;

	case QVariant::Double:
		ret = QStringLiteral("Double");
		break;

	case QVariant::String:
		ret = QStringLiteral("String");
		break;

	case QVariant::StringList:
		ret = QStringLiteral("List");
		break;

	case QVariant::UserType:
		ret = QStringLiteral("Element");
		break;

	default:
		ret = QStringLiteral("Void");
	}

	return ret;
}

}  // namespace icL::logic
