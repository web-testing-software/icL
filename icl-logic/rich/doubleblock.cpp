#include "doubleblock.h"

namespace icL::logic::rich {

DoubleBlock::DoubleBlock(OperationType otype)
	: icL::logic::RichBlock(otype) {
	casted = true;
}

DoubleBlock::DoubleBlock(RichBlock * block)
	: RichBlock(block) {}


/**
 * @brief DoubleBlock::calcResult - compare values
 * @return the result of comparation
 */
bool DoubleBlock::calcResult() {
	bool   result = false;
	double var1   = value1.toDouble();

	if (value2.type() == QVariant::Double) {
		double var2 = value2.toDouble();

		switch (operationType) {
		case OperationType::Equal:
			result = qFuzzyCompare(var1, var2);
			break;

		case OperationType::NotEqual:
			result = !qFuzzyCompare(var1, var2);
			break;

		default:
			resultValue = ResultValue::FAILED_CALCULATE;
			sendSignalWrongOperator("[Double-Double]");
		}
	}
	else {
		sendSignalWrongPair();
	}

	return result;
}

}  // namespace icL::logic::rich
