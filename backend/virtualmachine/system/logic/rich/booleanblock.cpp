#include "booleanblock.h"

vm::system::logic::rich::BooleanBlock::BooleanBlock (OperationType otype) :
	vm::system::logic::RichBlock (otype) {

}

bool vm::system::logic::rich::BooleanBlock::check (const QString &value) {
	return value == "true" || value == "false";
}

bool vm::system::logic::rich::BooleanBlock::calcResult () {
	bool	result	= false;
	bool	var1	= varNameToValue (this, var1name);
	bool	var2	= varNameToValue (this, var2name);

	switch (operationType) {
	case OperationType::EQUAL :
		result = ( var1 == var2 );
		break;

	case OperationType::NOT_EQUAL :
		result = ( var1 != var2 );
		break;

	default :
		resultValue = ResultValue::FAILED_CALCULATE;
		virtualMachine->setError (Error::COMMAND_EXECUTION_ERROR,
								  QObject::tr ("Wrong operator for operands boolean:%1 and boolean:%2.")
								  .arg (var1name)
								  .arg (var2name));
	}

	return result;
}

bool vm::system::logic::rich::BooleanBlock::varNameToValue (LogicBlock *block, const QString &varname) {
	DataState::Type type	= DataState::Type::BOOLEAN;
	bool			ret		= false; // = false -> exclude compiler warning

	if (varname == "true") {
		ret = true;
	}
	else if (varname == "false") {
		ret = false;
	}
	else if (!virtualMachine->checkType (varname, type)) {
		block->invalidate ();
		virtualMachine->setError (Error::DATA_CONVERSION_ERROR,
								  QObject::tr ("%1 is not a boolean variable or constant.")
								  .arg (varname));
	}
	else {
		ret = virtualMachine->getVar (varname).toBool ();
	}

	return ret;
}
