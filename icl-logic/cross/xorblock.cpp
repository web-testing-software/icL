#include "xorblock.h"

namespace vm::logic::cross {

XOrBlock::XOrBlock () {

}

/**
 * @brief XOrBlock::calcResult - append != operation to child blocks
 * @return bool
 */
bool XOrBlock::calcResult () {
	return block1->getCachedResult () != block2->getCachedResult ();
}

}
