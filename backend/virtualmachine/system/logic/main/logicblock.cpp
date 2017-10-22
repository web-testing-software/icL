#include "logicblock.h"

vm::system::logic::LogicBlock::LogicBlock () {

}

bool vm::system::logic::LogicBlock::getResult () {
	bool result = this->calcResult ();

	if (resultValue == ResultValue::NOT_CALCULATED) {
		resultValue = result ? ResultValue::TRUE : ResultValue::FALSE;
	}

	return result;
}

void vm::system::logic::LogicBlock::resetResultValue () {
	resultValue = ResultValue::NOT_CALCULATED;
}

void vm::system::logic::LogicBlock::invalidate () {
	resultValue = ResultValue::WRONG_INPUT_DATA;
}

vm::system::logic::LogicBlock * vm::system::logic::LogicBlock::getParent () {
	return m_parent;
}

void vm::system::logic::LogicBlock::setParent (vm::system::logic::LogicBlock *parent) {
	m_parent = parent;
}


