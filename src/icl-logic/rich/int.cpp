#include "int.h"

namespace icL::logic::rich {

Int::Int(memory::InterLevel * il, OperationType otype)
	: Rich(il, otype) {
	casted = true;
}

Int::Int(memory::InterLevel * il, Rich * block)
	: Rich(il, block) {}


/**
 * @brief Int::calcResult - compare values
 * @return the result of comparation
 */
bool Int::calcResult() {
	bool result = false;
	int  var1   = value1.toInt();

	if (value2.type() == QVariant::Int) {
		int var2 = value2.toInt();

		switch (operationType) {
		case OperationType::Equal:
			result = (var1 == var2);
			break;

		case OperationType::NotEqual:
			result = (var1 != var2);
			break;

		default:
			resultValue = ResultValue::FAILED_CALCULATE;
			sendSignalWrongOperator("[Int-Int]");
		}
	}
	else {
		sendSignalWrongPair();
	}

	return result;
}

}  // namespace icL::logic::rich
