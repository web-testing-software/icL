#include "orblock.h"


vm::system::logic::cross::OrBlock::OrBlock () {

}


bool vm::system::logic::cross::OrBlock::calcResult () {
	return block1->getResult () || block2->getResult ();
}
