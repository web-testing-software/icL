#include "eq.h"

namespace old::logic::cross {

Eq::Eq(memory::InterLevel * il)
    : Cross(il){};

/**
 * @brief Eq::calcResult - append == operation to child blocks
 * @return bool
 */
bool Eq::calcResult() {
	return block1->getCachedResult() == block2->getCachedResult();
}

}  // namespace old::logic::cross
