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


bool vm::system::logic::CrossBlock::checkIntegrity () {
	bool integrity;

	if (block1 == nullptr || block2 == nullptr) {
		integrity = false;
	}
	else {
		integrity = block1->checkIntegrity () && block2->checkIntegrity ();
	}

	if (!integrity) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
	}

	return integrity;
}

void vm::system::logic::CrossBlock::resetResultValue () {
	block1->resetResultValue ();
	block2->resetResultValue ();
}


