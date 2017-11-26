#include "andblock.h"

vm::main::logic::cross::AndBlock::AndBlock () {

}


bool vm::main::logic::cross::AndBlock::calcResult () {
	return block1->getResult () && block2->getResult ();
}
