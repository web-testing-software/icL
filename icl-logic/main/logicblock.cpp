#include "logicblock.h"

namespace vm::main::logic {

LogicBlock::LogicBlock () {

}

LogicBlock::~LogicBlock () {

}

/**
 * @brief LogicBlock::getResult - calculate the result and save it to the resultValue
 * @return calcResult()
 */
bool LogicBlock::getResult () {
	bool result = false;

	if (resultValue == ResultValue::NOT_CALCULATED) {
		result		= this->calcResult ();
		resultValue = result ? ResultValue::TRUE_VALUE : ResultValue::FALSE_VALUE;
	}

	return result;
}

/**
 * @brief LogicBlock::resetResultValue - set the resultValue to "not calculated"
 */
void LogicBlock::resetResultValue () {
	resultValue = ResultValue::NOT_CALCULATED;
}

/**
 * @brief LogicBlock::invalidate - set the
 */
void LogicBlock::invalidate () {
	resultValue = ResultValue::WRONG_INPUT_DATA;
}

/**
 * @brief LogicBlock::getParent - node parent getter
 * @return pointer to the parent node
 */
LogicBlock * LogicBlock::getParent () {
	return m_parent;
}

/**
 * @brief LogicBlock::setParent - node parent setter
 * @param pointer to the parent node
 */
void LogicBlock::setParent (LogicBlock *parent) {
	m_parent = parent;
}

}
