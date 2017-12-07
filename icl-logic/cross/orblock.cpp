#include "orblock.h"

namespace vm::main::logic::cross {

OrBlock::OrBlock () {

}


bool OrBlock::calcResult () {
	return block1->getResult () || block2->getResult ();
}

}
