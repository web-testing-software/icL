#include "stringblock.h"

namespace vm::main::logic::rich {

StringBlock::StringBlock (OperationType otype) :
	vm::main::logic::RichBlock (otype) {

}

/**
 * @brief StringBlock::exp - a reg exp which describe a <string> const
 */
QRegExp StringBlock::exp = QRegExp ("\".*[^\\\\]\"");

/**
 * @brief StringBlock::check - check if is a valid string const
 * @param value - the value to check
 * @return valid - true, invalid - false
 */
bool StringBlock::check (const QString &value) {
	return exp.exactMatch (value);
}

/**
 * @brief StringBlock::calcResult - compare values
 * @return the result of comparation
 */
bool StringBlock::calcResult () {
	bool	result	= false;
	QString var1	= varNameToString (var1name);
	QString var2	= varNameToString (var2name);

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
								  QObject::tr ("Wrong operator for operands string:%1 and string:%2.")
								  .arg (var1name)
								  .arg (var2name));
	}

	return result;
}

/**
 * @brief StringBlock::varNameToString convert var name to string value
 * @param varname - name of variable or string const
 * @return the parsed value or "" on fail
 */
QString StringBlock::varNameToString (const QString &varname) {
	memory::DataState::Type type = memory::DataState::Type::STRING;
	QString			ret;

	if (check (varname)) {
		ret = varname.mid (1, -2);
	}
	else if (!dataContainer->checkType (varname, type)) {
		invalidate ();
		dataContainer->setError (Error::DATA_CONVERSION_ERROR,
								  QObject::tr ("%1 is not a string variable or constant.")
								  .arg (varname));
	}
	else {
		ret = dataContainer->getVar (varname).toString ();
	}

	return ret;
}

}
