#include "booleanblock.h"

namespace vm::logic::rich {

BooleanBlock::BooleanBlock (OperationType otype) :
	RichBlock (otype) {
	casted = true;
}

BooleanBlock::BooleanBlock (RichBlock *block)
	: RichBlock (block) {
}

/**
 * @brief BooleanBlock::calcResult - compare values
 * @return the result of comparation
 */
bool BooleanBlock::calcResult () {
	bool	result	= false;
	bool	var1	= value1.toBool ();

	if (value2.type () == QVariant::Bool) {
		bool var2 = value2.toBool ();

		switch (operationType) {
		case OperationType::EQUAL :
			result = ( var1 == var2 );
			break;

		case OperationType::NOT_EQUAL :
			result = ( var1 != var2 );
			break;

		default :
			resultValue = ResultValue::FAILED_CALCULATE;
			sendSignalWrongOperator ("[Bool-Bool]");
		}
	}
	else {
		sendSignalWrongPair ();
	}

	return result;
}

}
