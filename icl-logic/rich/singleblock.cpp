#include "singleblock.h"


vm::main::logic::rich::SingleBlock::SingleBlock (OperationType otype)
	: vm::main::logic::RichBlock (otype) {

}

bool vm::main::logic::rich::SingleBlock::checkIntegrity () {
	if (var1name.isEmpty ()) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
		return false;
	}
	return true;
}

bool vm::main::logic::rich::SingleBlock::calcResult () {
	memory::DataState::Type type = memory::DataState::Type::BOOLEAN;
	bool			value, ret = false;

	if (!dataContainer->checkType (var1name, type)) {
		invalidate ();
		dataContainer->setError (Error::DATA_CONVERSION_ERROR,
						 QObject::tr ("%1 is not a boolean variable.")
						 .arg (var1name));
	}

	value = dataContainer->getVar (var1name).toBool ();

	switch (operationType) {
	case OperationType::NOT_NOT :
		ret = value;
		break;

	case OperationType::NOT :
		ret = !value;
		break;

	default :
		resultValue = ResultValue::FAILED_CALCULATE;
		dataContainer->setError (Error::COMMAND_EXECUTION_ERROR,
						 QObject::tr ("Wrong operator for bool operand: %1")
						 .arg (var1name));
	}

	return ret;
}
