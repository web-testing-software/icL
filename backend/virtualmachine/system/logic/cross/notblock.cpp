#include "notblock.h"


vm::system::logic::cross::NotBlock::NotBlock () {

}


bool vm::system::logic::cross::NotBlock::getResult () {
	return !block2->getResult ();
}

bool vm::system::logic::cross::NotBlock::checkIntegrity () {
	return block2 != nullptr && block2->checkIntegrity ();
}
