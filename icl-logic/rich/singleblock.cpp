#include "singleblock.h"

namespace vm::logic::rich {

SingleBlock::SingleBlock (OperationType otype)
	: vm::logic::RichBlock (otype) {
	casted = true;
}

/**
 * @brief SingleBlock::calcResult - compare the <bool> value
 * @return the result of comparation
 */
bool SingleBlock::calcResult () {
	bool value, ret = false;

	if (value1.canConvert <memory::WebElement>() ) {
		value = value1.value <memory::WebElement>().count > 0;
	}
	else {
		value = value1.toBool ();
	}

	switch (operationType) {
	case OperationType::NotNot :
		ret = value;
		break;

	case OperationType::Not :
		ret = !value;
		break;

	default :
		resultValue = ResultValue::FAILED_CALCULATE;
		// Never called
	}

	return ret;
}

/**
 * @brief SingleBlock::checkIntegrity - it need to be setted just the first varname
 * @return the first varname is setted
 */
bool SingleBlock::checkIntegrity () {
	if (frag1.source == nullptr) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
		return false;
	}
	return true;
}

bool SingleBlock::needCast () {
	return false;
}

bool SingleBlock::canResultPreliminarily () {
	return true;
}

}
