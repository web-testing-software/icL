#include "orblock.h"

namespace vm::main::logic::cross {

OrBlock::OrBlock () {

}

/**
 * @brief OrBlock::calcResult - append || operation to child blocks
 * @return bool
 */
bool OrBlock::calcResult () {
	return block1->getResult () || block2->getResult ();
}

}
