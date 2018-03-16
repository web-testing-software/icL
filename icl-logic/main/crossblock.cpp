#include "crossblock.h"

namespace vm::main::logic {

CrossBlock::CrossBlock () {

}

/**
 * @brief CrossBlock::canAcceptBlock - the block can accept a child if the first or the second child is null (the second is always null when the first is null)
 * @return bool
 */
bool CrossBlock::canAcceptBlock () {
	return block2 == nullptr;
}

/**
 * @brief CrossBlock::giveBlock - set the block to the first free position
 * @param block - any free block
 */
void CrossBlock::giveBlock (LogicBlock *block) {
	if (block1 == nullptr) {
		block1 = block;
	}
	else if (block2 == nullptr) {
		block2 = block;
	}
}

/**
 * @brief CrossBlock::isCross - if the block is a cross type and accept blocks like child
 * @return bool
 */
bool CrossBlock::isCross () {
	return true;
}

/**
 * @brief CrossBlock::checkIntegrity - if both block are already setted
 * @return bool
 */
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

/**
 * @brief CrossBlock::resetResultValue - reset the resultValue value to default
 */
void CrossBlock::resetResultValue () {
	block1->resetResultValue ();
	block2->resetResultValue ();
}

}
