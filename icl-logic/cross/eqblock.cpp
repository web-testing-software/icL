#include "eqblock.h"

namespace vm::logic::cross {

EqBlock::EqBlock () {

}

/**
 * @brief EqBlock::calcResult - append == operation to child blocks
 * @return bool
 */
bool EqBlock::calcResult () {
	return block1->getCachedResult () == block2->getCachedResult ();
}

}
