#include "xorblock.h"

namespace vm::main::logic::cross {

XOrBlock::XOrBlock () {

}


bool XOrBlock::calcResult () {
	return block1->getResult () != block2->getResult ();
}

}
