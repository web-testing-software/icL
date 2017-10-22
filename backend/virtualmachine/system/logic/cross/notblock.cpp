#include "notblock.h"


vm::system::logic::cross::NotBlock::NotBlock () {

}


bool vm::system::logic::cross::NotBlock::calcResult () {
	return !block2->getResult ();
}

bool vm::system::logic::cross::NotBlock::checkIntegrity () {
	bool integrity = block2 != nullptr && block2->checkIntegrity ();

	if (!integrity) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
	}

	return integrity;
}

void vm::system::logic::cross::NotBlock::resetResultValue()
{
	block2->resetResultValue ();
}
