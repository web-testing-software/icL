#include "or.h"

namespace old::logic::cross {

Or::Or(memory::InterLevel * il)
    : Cross(il){};

/**
 * @brief Or::calcResult - append || operation to child blocks
 * @return bool
 */
bool Or::calcResult() {
	return block1->getCachedResult() || block2->getCachedResult();
}

bool Or::canResultPreliminarily() {
	return value1 == true;
}

}  // namespace old::logic::cross
