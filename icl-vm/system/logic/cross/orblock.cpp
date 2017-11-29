#include "orblock.h"


vm::main::logic::cross::OrBlock::OrBlock () {

}


bool vm::main::logic::cross::OrBlock::calcResult () {
	return block1->getResult () || block2->getResult ();
}
