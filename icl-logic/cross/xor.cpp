#include "xor.h"

namespace icL::logic::cross {

XOr::XOr(memory::InterLevel * il)
	: Cross(il){};

/**
 * @brief XOr::calcResult - append != operation to child blocks
 * @return bool
 */
bool XOr::calcResult() {
	return block1->getCachedResult() != block2->getCachedResult();
}

}  // namespace icL::logic::cross
