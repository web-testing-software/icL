#include "xorblock.h"

vm::main::logic::cross::XOrBlock::XOrBlock () {

}


bool vm::main::logic::cross::XOrBlock::calcResult () {
	return block1->getResult () != block2->getResult ();
}
