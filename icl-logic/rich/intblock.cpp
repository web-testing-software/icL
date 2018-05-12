#include "intblock.h"

namespace vm::logic::rich {

IntBlock::IntBlock(OperationType otype)
	: vm::logic::RichBlock(otype) {
	casted = true;
}

IntBlock::IntBlock(RichBlock* block)
	: RichBlock(block) {}


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

}  // namespace vm::logic::rich
