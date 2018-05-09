#include "stringblock.h"

namespace vm::logic::rich {

StringBlock::StringBlock (OperationType otype) :
	vm::logic::RichBlock (otype) {

}

/**
 * @brief StringBlock::calcResult - compare values
 * @return the result of comparation
 */
bool StringBlock::calcResult () {
	bool	result	= false;
	QString var1	= value1.toString ();

	if (value2.type () == QVariant::String) {
		QString var2 = value2.toString ();

		switch (operationType) {
		case OperationType::EQUAL :
			result = ( var1 == var2 );
			break;

		case OperationType::NOT_EQUAL :
			result = ( var1 != var2 );
			break;

		default :
			resultValue = ResultValue::FAILED_CALCULATE;
			sendSignalWrongOperator ("[String-String]");
		}
	}
	else {
		sendSignalWrongPair ();
	}

	return result;
}

}
