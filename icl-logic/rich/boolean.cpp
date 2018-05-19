#include "booleanblock.h"

namespace icL::logic::rich {

BooleanBlock::BooleanBlock(memory::InterLevel * il, OperationType otype)
	: RichBlock(il, otype) {
	casted = true;
}

BooleanBlock::BooleanBlock(memory::InterLevel * il, RichBlock * block)
	: RichBlock(il, block) {}

/**
 * @brief BooleanBlock::calcResult - compare values
 * @return the result of comparation
 */
bool BooleanBlock::calcResult() {
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
