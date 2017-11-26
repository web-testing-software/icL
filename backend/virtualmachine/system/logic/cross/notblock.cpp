#include "notblock.h"


vm::main::logic::cross::NotBlock::NotBlock () {

}


bool vm::main::logic::cross::NotBlock::calcResult () {
	return !block2->getResult ();
}

bool vm::main::logic::cross::NotBlock::checkIntegrity () {
	bool integrity = block2 != nullptr && block2->checkIntegrity ();

	if (!integrity) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
	}

	return integrity;
}

void vm::main::logic::cross::NotBlock::resetResultValue () {
	block2->resetResultValue ();
}
