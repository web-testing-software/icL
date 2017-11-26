#include "crossblock.h"

vm::main::logic::CrossBlock::CrossBlock () {

}

bool vm::main::logic::CrossBlock::canAcceptBlock () {
	return block2 == nullptr;
}

void vm::main::logic::CrossBlock::giveBlock (vm::main::logic::LogicBlock *block) {
	if (block1 == nullptr) {
		block1 = block;
	}
	else if (block2 == nullptr) {
		block2 = block;
	}
}

bool vm::main::logic::CrossBlock::isCross () {
	return true;
}


bool vm::main::logic::CrossBlock::checkIntegrity () {
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

void vm::main::logic::CrossBlock::resetResultValue () {
	block1->resetResultValue ();
	block2->resetResultValue ();
}


