#include "xorblock.h"

vm::system::logic::cross::XOrBlock::XOrBlock () {

}


bool vm::system::logic::cross::XOrBlock::getResult () {
	return  block1->getResult () != block2->getResult ();
}
