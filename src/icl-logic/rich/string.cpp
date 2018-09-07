#include "string.h"

namespace icL::logic::rich {

String::String(memory::InterLevel * il, OperationType otype)
	: Rich(il, otype) {
	casted = true;
}

String::String(memory::InterLevel * il, Rich * block)
	: Rich(il, block) {}


/**
 * @brief String::calcResult - compare values
 * @return the result of comparation
 */
bool String::calcResult() {
	bool    result = false;
	QString var1   = value1.toString();

	if (value2.type() == QVariant::String) {
		QString var2 = value2.toString();

		switch (operationType) {
		case OperationType::Equal:
			result = (var1 == var2);
			break;

		case OperationType::NotEqual:
			result = (var1 != var2);
			break;

		default:
			resultValue = ResultValue::FAILED_CALCULATE;
			sendSignalWrongOperator("[String-String]");
		}
	}
	else {
		sendSignalWrongPair();
	}

	return result;
}

}  // namespace icL::logic::rich
