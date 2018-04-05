#include "andblock.h"

namespace vm::logic::cross {

AndBlock::AndBlock () {

}

/**
 * @brief AndBlock::calcResult - append operation && to child blocks
 * @return bool
 */
bool AndBlock::calcResult () {
	return block1->getCachedResult () && block2->getCachedResult ();
}

}
