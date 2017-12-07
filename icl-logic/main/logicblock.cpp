#include "logicblock.h"

namespace vm::main::logic {

LogicBlock::LogicBlock () {

}

bool LogicBlock::getResult () {
	bool result = this->calcResult ();

	if (resultValue == ResultValue::NOT_CALCULATED) {
		resultValue = result ? ResultValue::TRUE_VALUE : ResultValue::FALSE_VALUE;
	}

	return result;
}

void LogicBlock::resetResultValue () {
	resultValue = ResultValue::NOT_CALCULATED;
}

void LogicBlock::invalidate () {
	resultValue = ResultValue::WRONG_INPUT_DATA;
}

LogicBlock * LogicBlock::getParent () {
	return m_parent;
}

void LogicBlock::setParent (LogicBlock *parent) {
	m_parent = parent;
}

}
