#include "doubleblock.h"

namespace vm::main::logic::rich {

DoubleBlock::DoubleBlock (OperationType otype) :
	vm::main::logic::RichBlock (otype) {

}

QRegExp DoubleBlock::exp = QRegExp ("\\d+\\.\\d+");

bool DoubleBlock::check (const QString &value) {
	return exp.exactMatch (value);
}


bool DoubleBlock::calcResult () {
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
		dataContainer->setError (Error::COMMAND_EXECUTION_ERROR,
								  QObject::tr ("Wrong operator for operands double:%1 and double:%2.")
								  .arg (var1name)
								  .arg (var2name));
	}

	return result;
}

double DoubleBlock::varNameToDouble (const QString &varname) {
	memory::DataState::Type type	= memory::DataState::Type::DOUBLE;
	double			ret		= 0.0; // = 0.0 -> exclude compiler warning

	if (check (varname)) {
		ret = varname.toDouble ();
	}
	else if (!dataContainer->checkType (varname, type)) {
		invalidate ();
		dataContainer->setError (Error::DATA_CONVERSION_ERROR,
								  QObject::tr ("%1 is not a double variable or constant.")
								  .arg (varname));
	}
	else {
		ret = dataContainer->getVar (varname).toDouble ();
	}

	return ret;
}

}
