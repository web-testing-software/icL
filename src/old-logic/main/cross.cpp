#include "cross.h"

namespace old::logic::cross {

Cross::Cross(memory::InterLevel * il)
    : Logic(il){};

/**
 * @brief Cross::canAcceptBlock - the block can accept a child if the first
 * or the second child is null (the second is always null when the first is
 * null)
 * @return bool
 */
Cross::~Cross() {
	if (block1 != nullptr) {
		delete block1;
	}
	if (block2 != nullptr) {
		delete block2;
	}
}

bool Cross::canAcceptBlock() {
	return block2 == nullptr;
}

/**
 * @brief Cross::giveBlock - set the block to the first free position
 * @param block - any free block
 */
void Cross::giveBlock(Logic * block) {
	if (block1 == nullptr) {
		block1 = block;
	}
	else if (block2 == nullptr) {
		block2 = block;
	}
}

/**
 * @brief Cross::isCross - if the block is a cross type and accept blocks
 * like child
 * @return bool
 */
bool Cross::isCross() {
	return true;
}

/**
 * @brief Cross::checkIntegrity - if both block are already setted
 * @return bool
 */
bool Cross::checkIntegrity() {
	bool integrity;

	if (block1 == nullptr || block2 == nullptr) {
		integrity = false;
	}
	else {
		integrity = block1->checkIntegrity() && block2->checkIntegrity();
	}

	if (!integrity) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
	}

	return integrity;
}

/**
 * @brief Cross::resetResultValue - reset the resultValue value to default
 */
void Cross::resetResultValue() {
	block1->resetResultValue();
	block2->resetResultValue();

	value1getted = false;
	value2getted = false;
}

bool Cross::needCast() {
	return false;
}

Logic * Cross::castNow() {
	return nullptr;
}

bool Cross::step() {
	if (!value1getted) {
		if (block1->step()) {
			value1       = block1->getCachedResult();
			value1getted = true;
		}
		else {
			if (block1->needCast()) {
				Logic * newBlock = block1->castNow();

				delete block1;
				block1 = newBlock;
			}
		}

		return false;
	}
	else if (!value2getted && !canResultPreliminarily()) {
		if (block2->step()) {
			value2       = block2->getCachedResult();
			value2getted = true;
		}

		return false;
	}
	else {
		result         = calcResult();
		resultCalculed = true;

		return true;
	}
}

bool Cross::calcResult() {
	return false;
}

}  // namespace old::logic::cross
