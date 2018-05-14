#include "eqblock.h"

namespace icL::logic::cross {

EqBlock::EqBlock() = default;

/**
 * @brief EqBlock::calcResult - append == operation to child blocks
 * @return bool
 */
bool EqBlock::calcResult() {
	return block1->getCachedResult() == block2->getCachedResult();
}

}  // namespace icL::logic::cross
