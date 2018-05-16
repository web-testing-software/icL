#include "stringblock.h"

namespace icL::logic::rich {

StringBlock::StringBlock(memory::InterLevel * il, OperationType otype)
	: RichBlock(il, otype) {
	casted = true;
}

StringBlock::StringBlock(memory::InterLevel * il, RichBlock * block)
	: RichBlock(il, block) {}


/**
 * @brief StringBlock::calcResult - compare values
 * @return the result of comparation
 */
bool StringBlock::calcResult() {
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
