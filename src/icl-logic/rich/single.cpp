#include "single.h"

namespace icL::logic::rich {

Single::Single(memory::InterLevel * il, OperationType otype)
	: Rich(il, otype) {
	casted = true;
}

/**
 * @brief Single::calcResult - compare the <bool> value
 * @return the result of comparation
 */
bool Single::calcResult() {
	bool value, ret = false;

	if (value1.canConvert<memory::Element>()) {
		value = value1.value<memory::Element>().count > 0;
	}
	else {
		value = value1.toBool();
	}

	switch (operationType) {
	case OperationType::NotNot:
		ret = value;
		break;

	case OperationType::Not:
		ret = !value;
		break;

	default:
		resultValue = ResultValue::FAILED_CALCULATE;
		// Never called
	}

	return ret;
}

/**
 * @brief Single::checkIntegrity - it need to be setted just the first
 * varname
 * @return the first varname is setted
 */
bool Single::checkIntegrity() {
	if (frag1.source == nullptr) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
		return false;
	}
	return true;
}

bool Single::needCast() {
	return false;
}

bool Single::canResultPreliminarily() {
	return true;
}

}  // namespace icL::logic::rich
