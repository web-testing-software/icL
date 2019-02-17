#include "and.h"

namespace icL::logic::cross {

And::And(memory::InterLevel * il)
    : Cross(il){};

/**
 * @brief And::calcResult - append operation && to child blocks
 * @return bool
 */
bool And::calcResult() {
	return block1->getCachedResult() && block2->getCachedResult();
}

bool And::canResultPreliminarily() {
	return value1 == false;
}

}  // namespace icL::logic::cross
