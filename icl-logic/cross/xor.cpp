#include "xor.h"

namespace icL::logic::cross {

XOrBlock::XOrBlock(memory::InterLevel * il)
	: CrossBlock(il){};

/**
 * @brief XOrBlock::calcResult - append != operation to child blocks
 * @return bool
 */
bool XOrBlock::calcResult() {
	return block1->getCachedResult() != block2->getCachedResult();
}

}  // namespace icL::logic::cross
