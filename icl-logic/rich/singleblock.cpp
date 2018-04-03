#include "singleblock.h"

namespace vm::logic::rich {

SingleBlock::SingleBlock (OperationType otype)
	: vm::logic::RichBlock (otype) {

}

/**
 * @brief SingleBlock::checkIntegrity - it need to be setted just the first varname
 * @return the first varname is setted
 */
bool SingleBlock::checkIntegrity () {
	if (code1 == nullptr) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
		return false;
	}
	return true;
}

/**
 * @brief SingleBlock::calcResult - compare the <bool> value
 * @return the result of comparation
 */
bool SingleBlock::calcResult () {
//	memory::DataState::Type type = memory::DataState::Type::BOOLEAN;
	bool			value, ret = false;

//	if () {
//		invalidate ();
//		dataContainer->setError (Error::DATA_CONVERSION_ERROR,
//						 QObject::tr ("%1 is not a boolean variable.")
//						 .arg (var1name));
//	}

	value = value1.toBool();

	switch (operationType) {
	case OperationType::NOT_NOT :
		ret = value;
		break;

	case OperationType::NOT :
		ret = !value;
		break;

	default :
		resultValue = ResultValue::FAILED_CALCULATE;
//		dataContainer->setError (Error::COMMAND_EXECUTION_ERROR,
//						 QObject::tr ("Wrong operator for bool operand: %1")
//						 .arg (var1name));
	}

	return ret;
}

}
