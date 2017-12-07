#include "crossblock.h"

namespace vm::main::logic {

CrossBlock::CrossBlock () {

}

bool CrossBlock::canAcceptBlock () {
	return block2 == nullptr;
}

void CrossBlock::giveBlock (LogicBlock *block) {
	if (block1 == nullptr) {
		block1 = block;
	}
	else if (block2 == nullptr) {
		block2 = block;
	}
}

bool CrossBlock::isCross () {
	return true;
}


bool CrossBlock::checkIntegrity () {
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

void CrossBlock::resetResultValue () {
	block1->resetResultValue ();
	block2->resetResultValue ();
}

}
