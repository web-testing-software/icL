#include "intblock.h"

vm::system::logic::rich::IntBlock::IntBlock (OperationType otype) :
	vm::system::logic::RichBlock (otype) {

}

QRegExp vm::system::logic::rich::IntBlock::exp = QRegExp ("-?\\d+");

bool vm::system::logic::rich::IntBlock::check (const QString &value) {
	return exp.exactMatch (value);
}


bool vm::system::logic::rich::IntBlock::calcResult () {
	bool	result	= false;
	int	var1	= varNameToValue (var1name);
	int	var2	= varNameToValue (var2name);

	switch (operationType) {
	case OperationType::EQUAL :
		result = ( var1 == var2 );
		break;

	case OperationType::NOT_EQUAL :
		result = ( var1 != var2 );
		break;

	default :
		virtualMachine->setError (Error::COMMAND_EXECUTION_ERROR,
								  QObject::tr ("Wrong operator for operands int:%1 and int:%2.")
								  .arg (var1name)
								  .arg (var2name));
	}

	return result;
}

int vm::system::logic::rich::IntBlock::varNameToValue (const QString &varname) {
	DataState::Type type	= DataState::Type::INT;
	int				ret		= 0; // = 0 -> exclude compiler warning

	if (check (varname)) {
		ret = varname.toInt ();
	}
	else if (!virtualMachine->checkType (varname, type)) {
		virtualMachine->setError (Error::DATA_CONVERSION_ERROR,
								  QObject::tr ("%1 is not a boolean variable or constant.")
								  .arg (varname));
	}
	else {
		ret = virtualMachine->getVar (varname).toInt ();
	}

	return ret;
}
