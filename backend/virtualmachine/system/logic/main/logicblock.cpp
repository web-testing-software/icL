#include "logicblock.h"

vm::system::logic::LogicBlock::LogicBlock () {

}

vm::system::logic::LogicBlock * vm::system::logic::LogicBlock::getParent () {
	return m_parent;
}

void vm::system::logic::LogicBlock::setParent (vm::system::logic::LogicBlock *parent) {
	m_parent = parent;
}
