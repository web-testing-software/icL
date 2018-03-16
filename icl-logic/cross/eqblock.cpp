#include "eqblock.h"

namespace vm::main::logic::cross {

EqBlock::EqBlock () {

}

/**
 * @brief EqBlock::calcResult - append == operation to child blocks
 * @return bool
 */
bool EqBlock::calcResult () {
	return block1->getResult () == block2->getResult ();
}

}
