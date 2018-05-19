#include "not.h"

namespace icL::logic::cross {

NotBlock::NotBlock(memory::InterLevel * il)
	: CrossBlock(il){};

/**
 * @brief NotBlock::calcResult - invert the result of the secound block
 * @return bool
 */
bool NotBlock::calcResult() {
	return !block2->getCachedResult();
}

/**
 * @brief NotBlock::checkIntegrity - check the integrity of the second block,
 * the first is useless
 * @return
 */
bool NotBlock::checkIntegrity() {
	bool integrity = block2 != nullptr && block2->checkIntegrity();

	if (!integrity) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
	}

	return integrity;
}

/**
 * @brief NotBlock::resetResultValue - reset the socund block, the first is
 * useless
 */
void NotBlock::resetResultValue() {
	block2->resetResultValue();
}

}  // namespace icL::logic::cross
