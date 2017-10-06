#include "crossblock.h"

vm::system::logic::CrossBlock::CrossBlock () {

}

bool vm::system::logic::CrossBlock::canAcceptBlock () {
	return block2 == nullptr;
}

void vm::system::logic::CrossBlock::giveBlock (vm::system::logic::LogicBlock *block) {
	if (block1 == nullptr) {
		block1 = block;
	}
	else if (block2 == nullptr) {
		block2 = block;
	}
}

bool vm::system::logic::CrossBlock::isCross () {
	return true;
}


bool vm::system::logic::CrossBlock::checkIntegrity()
{
	if (block1 == nullptr || block2 == nullptr) {
		return false;
	}
	return block1->checkIntegrity () && block2->checkIntegrity ();
}
