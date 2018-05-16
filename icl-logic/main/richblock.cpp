#include "richblock.h"

#include <rich/booleanblock.h>
#include <rich/doubleblock.h>
#include <rich/intblock.h>
#include <rich/listblock.h>
#include <rich/stringblock.h>

namespace icL::logic {

RichBlock::RichBlock(memory::InterLevel * il, OperationType otype)
	: LogicBlock(il) {
	operationType = otype;
}

RichBlock::RichBlock(memory::InterLevel * il, RichBlock * block)
	: LogicBlock(il) {
	operationType = block->operationType;
	value1        = block->value1;
	value2        = block->value2;
	frag1         = block->frag1;
	frag2         = block->frag2;
}

RichBlock::~RichBlock() = default;

/**
 * @brief RichBlock::canAcceptVar - if the first or the second var/const are not
 * setted
 * @return bool
 */
bool RichBlock::canAcceptCode() {
	return frag2.source == nullptr;
}

/**
 * @brief RichBlock::giveVar - set up next var/const
 * @param varname - var/const
 */
void RichBlock::giveCode(memory::CodeFragment frag) {
	if (frag1.source == nullptr) {
		frag1 = frag;
	}
	else if (frag2.source == nullptr) {
		frag2 = frag;
	}
}

/**
 * @brief RichBlock::oTypeToString - operation type to string, special for
 * errors messages
 * @return a string with operation token (==, !=, <<,  <*)
 */
QString RichBlock::oTypeToString() {
	QString ret;

	switch (operationType) {
	case OperationType::Equal:
		ret = QStringLiteral("==");
		break;

	case OperationType::NotEqual:
		ret = QStringLiteral("!=");
		break;

	case OperationType::Contains:
		ret = QStringLiteral("<<");
		break;

	case OperationType::ContainsFragment:
		ret = QStringLiteral("<*");
		break;

	default:
		ret = QStringLiteral("?");
	}

	return ret;
}


/**
 * @brief RichBlock::pairData - give data for error messages
 * @return a string, which contains the type of the first and second values
 */
QString RichBlock::pairData() {
	return "[" % typeToString(value1.type()) % "-" %
		   typeToString(value2.type()) % "]";
}

void RichBlock::sendSignalWrongPair() {
	il->vm->exception({-201, "Wrong operarands pair: " + pairData()});
}

void RichBlock::sendSignalWrongOperator(const QString & pair) {
	il->vm->exception({-202, "Wrong operator " % oTypeToString() %
							   " for operands pair " % pair});
}



/**
 * @brief RichBlock::isCross - it cann't contains blocks like child
 * @return false
 */
bool RichBlock::isCross() {
	return false;
}

/**
 * @brief RichBlock::checkIntegrity - if the both var/const are setted
 * @return bool
 */
bool RichBlock::checkIntegrity() {
	if (frag1.source == nullptr || frag2.source == nullptr) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
		return false;
	}
	return true;
}

bool RichBlock::needCast() {
	return !casted;
}

LogicBlock * RichBlock::castNow() {
	LogicBlock * ret = nullptr;

	switch (value1.type()) {
	case QVariant::Bool:
		ret = new rich::BooleanBlock(il, this);
		break;

	case QVariant::Int:
		ret = new rich::IntBlock(il, this);
		break;

	case QVariant::Double:
		ret = new rich::DoubleBlock(il, this);
		break;

	case QVariant::String:
		ret = new rich::StringBlock(il, this);
		break;

	case QVariant::StringList:
		ret = new rich::ListBlock(il, this);
		break;

	default:
		il->vm->exception({-201,
						   "The operands of comparing operators must be "
						   "Boolean, Int, Double, String or List"});
		break;
	}

	return ret;
}

bool RichBlock::step() {
	if (!valu1getted) {
		memory::FunctionCall fcall;

		fcall.source = frag1;

		memory::Return ret = il->vms->interrupt(fcall);
		if (ret.exception.code != 0) {
			il->vm->exception(ret.exception);
		}
		else {
			this->value1      = ret.consoleValue;
			this->valu1getted = true;
		}

		return false;
	}
	else if (!value2getted && !canResultPreliminarily()) {
		memory::FunctionCall fcall;

		fcall.source = frag2;

		memory::Return ret = il->vms->interrupt(fcall);
		if (ret.exception.code != 0) {
			il->vm->exception(ret.exception);
		}
		else {
			this->value2       = ret.consoleValue;
			this->value2getted = true;
		}

		return false;
	}
	else {
		result         = calcResult();
		resultCalculed = true;

		return true;
	}
}

bool RichBlock::calcResult() {
	// Never called, make class not abstract
	return false;
}

}  // namespace icL::logic
