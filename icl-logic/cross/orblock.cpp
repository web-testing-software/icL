#include "orblock.h"

namespace icL::logic::cross {

OrBlock::OrBlock(memory::InterLevel * il)
	: CrossBlock(il){};

/**
 * @brief OrBlock::calcResult - append || operation to child blocks
 * @return bool
 */
bool OrBlock::calcResult() {
	return block1->getCachedResult() || block2->getCachedResult();
}

bool OrBlock::canResultPreliminarily() {
	return value1 == true;
}

}  // namespace icL::logic::cross
