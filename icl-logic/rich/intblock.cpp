#include "intblock.h"

vm::main::logic::rich::IntBlock::IntBlock (OperationType otype) :
	vm::main::logic::RichBlock (otype) {

}

QRegExp vm::main::logic::rich::IntBlock::exp = QRegExp ("-?\\d+");

bool vm::main::logic::rich::IntBlock::check (const QString &value) {
	return exp.exactMatch (value);
}


bool vm::main::logic::rich::IntBlock::calcResult () {
	bool	result	= false;
	int		var1	= varNameToInt (var1name);
	int		var2	= varNameToInt (var2name);

	switch (operationType) {
	case OperationType::EQUAL :
		result = ( var1 == var2 );
		break;

	case OperationType::NOT_EQUAL :
		result = ( var1 != var2 );
		break;

	default :
		resultValue = ResultValue::FAILED_CALCULATE;
		dataContainer->setError (Error::COMMAND_EXECUTION_ERROR,
								  QObject::tr ("Wrong operator for operands int:%1 and int:%2.")
								  .arg (var1name)
								  .arg (var2name));
	}

	return result;
}

int vm::main::logic::rich::IntBlock::varNameToInt (const QString &varname) {
	memory::DataState::Type type	= memory::DataState::Type::INT;
	int				ret		= 0; // = 0 -> exclude compiler warning

	if (check (varname)) {
		ret = varname.toInt ();
	}
	else if (!dataContainer->checkType (varname, type)) {
		invalidate ();
		dataContainer->setError (Error::DATA_CONVERSION_ERROR,
								  QObject::tr ("%1 is not a boolean variable or constant.")
								  .arg (varname));
	}
	else {
		ret = dataContainer->getVar (varname).toInt ();
	}

	return ret;
}
