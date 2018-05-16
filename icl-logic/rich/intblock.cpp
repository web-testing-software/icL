#include "intblock.h"

namespace icL::logic::rich {

IntBlock::IntBlock(memory::InterLevel * il, OperationType otype)
	: RichBlock(il, otype) {
	casted = true;
}

IntBlock::IntBlock(memory::InterLevel * il, RichBlock * block)
	: RichBlock(il, block) {}


/**
 * @brief IntBlock::calcResult - compare values
 * @return the result of comparation
 */
bool IntBlock::calcResult() {
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
