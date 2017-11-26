#include "logicblock.h"

vm::main::logic::LogicBlock::LogicBlock () {

}

bool vm::main::logic::LogicBlock::getResult () {
	bool result = this->calcResult ();

	if (resultValue == ResultValue::NOT_CALCULATED) {
		resultValue = result ? ResultValue::TRUE_VALUE : ResultValue::FALSE_VALUE;
	}

	return result;
}

void vm::main::logic::LogicBlock::resetResultValue () {
	resultValue = ResultValue::NOT_CALCULATED;
}

void vm::main::logic::LogicBlock::invalidate () {
	resultValue = ResultValue::WRONG_INPUT_DATA;
}

vm::main::logic::LogicBlock * vm::main::logic::LogicBlock::getParent () {
	return m_parent;
}

void vm::main::logic::LogicBlock::setParent (vm::main::logic::LogicBlock *parent) {
	m_parent = parent;
}


