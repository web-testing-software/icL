#include "orblock.h"

namespace vm::logic::cross {

OrBlock::OrBlock () = default;

/**
 * @brief OrBlock::calcResult - append || operation to child blocks
 * @return bool
 */
bool OrBlock::calcResult () {
	return block1->getCachedResult () || block2->getCachedResult ();
}

}
