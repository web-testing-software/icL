#include "andblock.h"

namespace icL::logic::cross {

AndBlock::AndBlock(memory::InterLevel * il)
	: CrossBlock(il){};

/**
 * @brief AndBlock::calcResult - append operation && to child blocks
 * @return bool
 */
bool AndBlock::calcResult() {
	return block1->getCachedResult() && block2->getCachedResult();
}

bool AndBlock::canResultPreliminarily() {
	return value1 == false;
}

}  // namespace icL::logic::cross
