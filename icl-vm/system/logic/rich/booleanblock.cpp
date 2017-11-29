#include "booleanblock.h"

vm::main::logic::rich::BooleanBlock::BooleanBlock (OperationType otype) :
	vm::main::logic::RichBlock (otype) {

}

bool vm::main::logic::rich::BooleanBlock::check (const QString &value) {
	return value == "true" || value == "false";
}

bool vm::main::logic::rich::BooleanBlock::calcResult () {
	bool	result	= false;
	bool	var1	= varNameToBoolean (var1name);
	bool	var2	= varNameToBoolean (var2name);

	switch (operationType) {
	case OperationType::EQUAL :
		result = ( var1 == var2 );
		break;

	case OperationType::NOT_EQUAL :
		result = ( var1 != var2 );
		break;

	default :
		resultValue = ResultValue::FAILED_CALCULATE;
		drive->setError (Error::COMMAND_EXECUTION_ERROR,
								  QObject::tr ("Wrong operator for operands boolean:%1 and boolean:%2.")
								  .arg (var1name)
								  .arg (var2name));
	}

	return result;
}

bool vm::main::logic::rich::BooleanBlock::varNameToBoolean (const QString &varname) {
	DataState::Type type	= DataState::Type::BOOLEAN;
	bool			ret		= false; // = false -> exclude compiler warning

	if (varname == "true") {
		ret = true;
	}
	else if (varname == "false") {
		ret = false;
	}
	else if (!drive->checkType (varname, type)) {
		invalidate ();
		drive->setError (Error::DATA_CONVERSION_ERROR,
								  QObject::tr ("%1 is not a boolean variable or constant.")
								  .arg (varname));
	}
	else {
		ret = drive->getVar (varname).toBool ();
	}

	return ret;
}
