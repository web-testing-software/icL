#include "Bool.h"

namespace icL::logic::rich {

Bool::Bool(memory::InterLevel * il, OperationType otype)
	: Rich(il, otype) {
	casted = true;
}

Bool::Bool(memory::InterLevel * il, Rich * block)
	: Rich(il, block) {}

/**
 * @brief Bool::calcResult - compare values
 * @return the result of comparation
 */
bool Bool::calcResult() {
	bool result = false;
	bool var1   = value1.toBool();

	if (value2.type() == QVariant::Bool) {
		bool var2 = value2.toBool();

		switch (operationType) {
		case OperationType::Equal:
			result = (var1 == var2);
			break;

		case OperationType::NotEqual:
			result = (var1 != var2);
			break;

		default:
			resultValue = ResultValue::FAILED_CALCULATE;
			sendSignalWrongOperator("[Bool-Bool]");
		}
	}
	else {
		sendSignalWrongPair();
	}

	return result;
}

}  // namespace icL::logic::rich
