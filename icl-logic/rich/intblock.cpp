#include "intblock.h"

namespace vm::main::logic::rich {

IntBlock::IntBlock (OperationType otype) :
	vm::main::logic::RichBlock (otype) {

}

/**
 * @brief IntBlock::exp - a regular expression which describe a int value
 */
QRegExp IntBlock::exp = QRegExp ("-?\\d+");

/**
 * @brief IntBlock::check - check if is a valid <int> value
 * @param value - value to check
 * @return valid - true, invalid - false
 */
bool IntBlock::check (const QString &value) {
	return exp.exactMatch (value);
}

/**
 * @brief IntBlock::calcResult - compare values
 * @return the result of comparation
 */
bool IntBlock::calcResult () {
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

/**
 * @brief IntBlock::varNameToInt - convert varname to <int> value
 * @param varname - name of variable or const value
 * @return the parsed value
 */
int IntBlock::varNameToInt (const QString &varname) {
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

}
