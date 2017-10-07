#include "andblock.h"

vm::system::logic::cross::AndBlock::AndBlock () {

}


bool vm::system::logic::cross::AndBlock::getResult () {
	return block1->getResult () && block2->getResult ();
}
