#include "orblock.h"


vm::system::logic::cross::OrBlock::OrBlock () {

}


bool vm::system::logic::cross::OrBlock::getResult () {
	return block1->getResult () || block2->getResult ();
}
