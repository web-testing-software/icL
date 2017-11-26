#include "doubleblock.h"


vm::main::logic::rich::DoubleBlock::DoubleBlock (OperationType otype) :
	vm::main::logic::RichBlock (otype) {

}

QRegExp vm::main::logic::rich::DoubleBlock::exp = QRegExp ("\\d+\\.\\d+");

bool vm::main::logic::rich::DoubleBlock::check (const QString &value) {
	return exp.exactMatch (value);
}


bool vm::main::logic::rich::DoubleBlock::calcResult () {
	bool	result	= false;
	double	var1	= varNameToDouble (var1name);
	double	var2	= varNameToDouble (var2name);

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
								  QObject::tr ("Wrong operator for operands double:%1 and double:%2.")
								  .arg (var1name)
								  .arg (var2name));
	}

	return result;
}

double vm::main::logic::rich::DoubleBlock::varNameToDouble (const QString &varname) {
	DataState::Type type	= DataState::Type::DOUBLE;
	double			ret		= 0.0; // = 0.0 -> exclude compiler warning

	if (check (varname)) {
		ret = varname.toDouble ();
	}
	else if (!drive->checkType (varname, type)) {
		invalidate ();
		drive->setError (Error::DATA_CONVERSION_ERROR,
								  QObject::tr ("%1 is not a double variable or constant.")
								  .arg (varname));
	}
	else {
		ret = drive->getVar (varname).toDouble ();
	}

	return ret;
}
