#include "intblock.h"

namespace vm::logic::rich {

IntBlock::IntBlock (OperationType otype) :
	vm::logic::RichBlock (otype) {

}

/**
 * @brief IntBlock::calcResult - compare values
 * @return the result of comparation
 */
bool IntBlock::calcResult () {
	bool	result	= false;
	int		var1	= value1.toInt ();

	if (value2.type () == QVariant::Int) {
		int var2 = value2.toInt ();

		switch (operationType) {
		case OperationType::EQUAL :
			result = ( var1 == var2 );
			break;

		case OperationType::NOT_EQUAL :
			result = ( var1 != var2 );
			break;

		default :
			resultValue = ResultValue::FAILED_CALCULATE;
			sendSignalWrongOperator("[Int-Int]");
		}
	}
	else {
		sendSignalWrongPair();
	}

	return result;
}

}
