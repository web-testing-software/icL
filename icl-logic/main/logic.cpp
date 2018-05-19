#include "logic.h"

namespace icL::logic {

LogicBlock::LogicBlock(memory::InterLevel * il)
	: memory::Node(il){};


/**
 * @brief LogicBlock::getResult - calculate the result and save it to the
 * resultValue
 * @return calcResult()
 */
bool LogicBlock::getResult() {
	bool result = false;

	if (resultValue == ResultValue::NOT_CALCULATED) {
		result = this->calcResult();
		resultValue =
		  result ? ResultValue::TRUE_VALUE : ResultValue::FALSE_VALUE;
	}

	return result;
}

bool LogicBlock::getCachedResult() {
	if (resultCalculed) {
		return result;
	}

	return getResult();
}

/**
 * @brief LogicBlock::resetResultValue - set the resultValue to "not calculated"
 */
void LogicBlock::resetResultValue() {
	resultValue = ResultValue::NOT_CALCULATED;
}

/**
 * @brief LogicBlock::invalidate - set the
 */
void LogicBlock::invalidate() {
	resultValue = ResultValue::WRONG_INPUT_DATA;
}

bool LogicBlock::canResultPreliminarily() {
	return false;
}

/**
 * @brief LogicBlock::getParent - node parent getter
 * @return pointer to the parent node
 */
LogicBlock * LogicBlock::getParent() {
	return m_parent;
}

/**
 * @brief LogicBlock::setParent - parent node setter
 * @param pointer to the parent node
 */
void LogicBlock::setParent(LogicBlock * parent) {
	m_parent = parent;
}

/**
 * @brief LogicBlock::typeToString - Convert types to string, special for errors
 * messages.
 * @param type - the result of QVariant.type()
 * @return a string with icL type name
 */
QString LogicBlock::typeToString(QVariant::Type type) {
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
