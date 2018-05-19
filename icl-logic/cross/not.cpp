#include "not.h"

namespace icL::logic::cross {

Not::Not(memory::InterLevel * il)
	: Cross(il){};

/**
 * @brief Not::calcResult - invert the result of the secound block
 * @return bool
 */
bool Not::calcResult() {
	return !block2->getCachedResult();
}

/**
 * @brief Not::checkIntegrity - check the integrity of the second block,
 * the first is useless
 * @return
 */
bool Not::checkIntegrity() {
	bool integrity = block2 != nullptr && block2->checkIntegrity();

	if (!integrity) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
	}

	return integrity;
}

/**
 * @brief Not::resetResultValue - reset the socund block, the first is
 * useless
 */
void Not::resetResultValue() {
	block2->resetResultValue();
}

}  // namespace icL::logic::cross
