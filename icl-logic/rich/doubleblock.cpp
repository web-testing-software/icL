#include "doubleblock.h"

namespace vm::logic::rich {

DoubleBlock::DoubleBlock (OperationType otype) :
	vm::logic::RichBlock (otype) {

}

/**
 * @brief DoubleBlock::exp - regular expression which describe a double value
 */
//QRegExp DoubleBlock::exp = QRegExp ("\\d+\\.\\d+");

/**
 * @brief DoubleBlock::check - check if is a valid double const
 * @param value - value to check
 * @return valid - true, invalid - false
 */
bool DoubleBlock::check (const QString &value) {
	return exp.exactMatch (value);
}

/**
 * @brief DoubleBlock::calcResult - compare values
 * @return the result of comparation
 */
bool DoubleBlock::calcResult () {
	bool	result	= false;
	double	var1	= value1.toDouble();
	double	var2	= value2.toDouble();

	switch (operationType) {
	case OperationType::EQUAL :
		result = qFuzzyCompare(var1, var2);
		break;

	case OperationType::NOT_EQUAL :
		result = !qFuzzyCompare(var1, var2);
		break;

	default :
		resultValue = ResultValue::FAILED_CALCULATE;
//		dataContainer->setError (Error::COMMAND_EXECUTION_ERROR,
//								  QObject::tr ("Wrong operator for operands double:%1 and double:%2.")
//								  .arg (var1name)
//								  .arg (var2name));
	}

	return result;
}

/**
 * @brief DoubleBlock::varNameToDouble - convert var name to a <double> value
 * @param varname - name of variable or const value
 * @return the result of comparation
 */
//double DoubleBlock::varNameToDouble (const QString &varname) {
//	memory::DataState::Type type	= memory::DataState::Type::DOUBLE;
//	double			ret		= 0.0; // = 0.0 -> exclude compiler warning

//	if (check (varname)) {
//		ret = varname.toDouble ();
//	}
//	else if (!dataContainer->checkType (varname, type)) {
//		invalidate ();
//		dataContainer->setError (Error::DATA_CONVERSION_ERROR,
//								  QObject::tr ("%1 is not a double variable or constant.")
//								  .arg (varname));
//	}
//	else {
//		ret = dataContainer->getVar (varname).toDouble ();
//	}

//	return ret;
//}

}
