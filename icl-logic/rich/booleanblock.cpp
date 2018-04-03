#include "booleanblock.h"

namespace vm::logic::rich {

BooleanBlock::BooleanBlock (OperationType otype) :
	vm::logic::RichBlock (otype) {

}

/**
 * @brief BooleanBlock::check - check if is a valid bool const
 * @param value - value to check
 * @return valid - true, invalid - false
 */
bool BooleanBlock::check (const QString &value) {
	return value == "true" || value == "false";
}

/**
 * @brief BooleanBlock::calcResult - compare values
 * @return the result of comparation
 */
bool BooleanBlock::calcResult () {
	bool	result	= false;
	bool	var1	= value1.toBool();
	bool	var2	= value2.toBool();

	switch (operationType) {
	case OperationType::EQUAL :
		result = ( var1 == var2 );
		break;

	case OperationType::NOT_EQUAL :
		result = ( var1 != var2 );
		break;

	default :
		resultValue = ResultValue::FAILED_CALCULATE;
//		dataContainer->setError (Error::COMMAND_EXECUTION_ERROR,
//								  QObject::tr ("Wrong operator for operands boolean:%1 and boolean:%2.")
//								  .arg (var1name)
//								  .arg (var2name));
	}

	return result;
}

/**
 * @brief BooleanBlock::varNameToBoolean - convert varname to bool value
 * @param varname - name of variable or const value
 * @return the parsed value
 */
//bool BooleanBlock::varNameToBoolean (const QString &varname) {
//	memory::DataState::Type type	= memory::DataState::Type::BOOLEAN;
//	bool			ret		= false; // = false -> exclude compiler warning

//	if (varname == "true") {
//		ret = true;
//	}
//	else if (varname == "false") {
//		ret = false;
//	}
//	else if (!dataContainer->checkType (varname, type)) {
//		invalidate ();
//		dataContainer->setError (Error::DATA_CONVERSION_ERROR,
//								  QObject::tr ("%1 is not a boolean variable or constant.")
//								  .arg (varname));
//	}
//	else {
//		ret = dataContainer->getVar (varname).toBool ();
//	}

//	return ret;
//}

}
