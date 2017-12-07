#include "andblock.h"

namespace vm::main::logic::cross {

AndBlock::AndBlock () {

}


bool AndBlock::calcResult () {
	return block1->getResult () && block2->getResult ();
}

}
