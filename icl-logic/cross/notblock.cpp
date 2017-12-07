#include "notblock.h"

namespace vm::main::logic::cross {

NotBlock::NotBlock () {

}


bool NotBlock::calcResult () {
	return !block2->getResult ();
}

bool NotBlock::checkIntegrity () {
	bool integrity = block2 != nullptr && block2->checkIntegrity ();

	if (!integrity) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
	}

	return integrity;
}

void NotBlock::resetResultValue () {
	block2->resetResultValue ();
}

}
