#include "doubleblock.h"


vm::system::logic::rich::DoubleBlock::DoubleBlock (OperationType otype) :
	vm::system::logic::RichBlock (otype) {

}

QRegExp vm::system::logic::rich::DoubleBlock::exp = QRegExp ("\\d+\\.\\d+");

bool vm::system::logic::rich::DoubleBlock::check (const QString &value) {
	return exp.exactMatch (value);
}


bool vm::system::logic::rich::DoubleBlock::calcResult () {
	bool	result	= false;
	double	var1	= varNameToValue (var1name);
	double	var2	= varNameToValue (var2name);

	switch (operationType) {
	case OperationType::EQUAL :
		result = ( var1 == var2 );
		break;

	case OperationType::NOT_EQUAL :
		result = ( var1 != var2 );
		break;

	default :
		virtualMachine->setError (Error::COMMAND_EXECUTION_ERROR,
								  QObject::tr ("Wrong operator for operands double:%1 and double:%2.")
								  .arg (var1name)
								  .arg (var2name));
	}

	return result;
}

double vm::system::logic::rich::DoubleBlock::varNameToValue (const QString &varname) {
	DataState::Type type	= DataState::Type::DOUBLE;
	double			ret		= 0.0; // = 0.0 -> exclude compiler warning

	if (check (varname)) {
		ret = varname.toDouble ();
	}
	else if (!virtualMachine->checkType (varname, type)) {
		virtualMachine->setError (Error::DATA_CONVERSION_ERROR,
								  QObject::tr ("%1 is not a double variable or constant.")
								  .arg (varname));
	}
	else {
		ret = virtualMachine->getVar (varname).toDouble ();
	}

	return ret;
}
