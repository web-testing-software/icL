#include "rich.h"

#include "../rich/boolean.h"
#include "../rich/double.h"
#include "../rich/int.h"
#include "../rich/list.h"
#include "../rich/string.h"

#include <QStringBuilder>

namespace icL::logic::rich {

Rich::Rich(memory::InterLevel * il, OperationType otype)
	: Logic(il) {
	operationType = otype;
}

Rich::Rich(memory::InterLevel * il, Rich * block)
	: Logic(il) {
	operationType = block->operationType;
	value1        = block->value1;
	value2        = block->value2;
	frag1         = block->frag1;
	frag2         = block->frag2;

	casted = true;
	valu1getted = true;
}

Rich::~Rich() = default;

/**
 * @brief Rich::canAcceptVar - if the first or the second var/const are not
 * setted
 * @return bool
 */
bool Rich::canAcceptCode() {
	return frag2.source == nullptr;
}

/**
 * @brief Rich::giveVar - set up next var/const
 * @param varname - var/const
 */
void Rich::giveCode(memory::CodeFragment frag) {
	if (frag1.source == nullptr) {
		frag1 = frag;
	}
	else if (frag2.source == nullptr) {
		frag2 = frag;
	}
}

/**
 * @brief Rich::oTypeToString - operation type to string, special for
 * errors messages
 * @return a string with operation token (==, !=, <<,  <*)
 */
QString Rich::oTypeToString() {
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
 * @brief Rich::pairData - give data for error messages
 * @return a string, which contains the type of the first and second values
 */
QString Rich::pairData() {
	return "[" % typeToString(value1.type()) % "-" %
		   typeToString(value2.type()) % "]";
}

void Rich::sendSignalWrongPair() {
	il->vm->exception({-201, "Wrong operarands pair: " + pairData()});
}

void Rich::sendSignalWrongOperator(const QString & pair) {
	il->vm->exception({-202, "Wrong operator " % oTypeToString() %
							   " for operands pair " % pair});
}



/**
 * @brief Rich::isCross - it cann't contains blocks like child
 * @return false
 */
bool Rich::isCross() {
	return false;
}

/**
 * @brief Rich::checkIntegrity - if the both var/const are setted
 * @return bool
 */
bool Rich::checkIntegrity() {
	if (frag1.source == nullptr || frag2.source == nullptr) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
		return false;
	}
	return true;
}

bool Rich::needCast() {
	return !casted && valu1getted;
}

Logic * Rich::castNow() {
	Logic * ret = nullptr;

	switch (value1.type()) {
	case QVariant::Bool:
		ret = new Boolean(il, this);
		break;

	case QVariant::Int:
		ret = new Int(il, this);
		break;

	case QVariant::Double:
		ret = new Double(il, this);
		break;

	case QVariant::String:
		ret = new String(il, this);
		break;

	case QVariant::StringList:
		ret = new ListBlock(il, this);
		break;

	default:
		il->vm->exception({-201,
						   "The operands of comparing operators must be "
						   "Boolean, Int, Double, String or List"});
		break;
	}

	return ret;
}

bool Rich::step() {
	if (!valu1getted) {
		memory::FunctionCall fcall;

		fcall.source = frag1;

		il->vms->interrupt(fcall, [this](memory::Return & ret) {
			if (ret.exception.code != 0) {
				il->vm->exception(ret.exception);
			}
			else {
				this->value1      = ret.consoleValue;
				this->valu1getted = true;
			}
		});


		return false;
	}
	else if (!value2getted && !canResultPreliminarily()) {
		memory::FunctionCall fcall;

		fcall.source = frag2;

		il->vms->interrupt(fcall, [this](memory::Return & ret) {
			if (ret.exception.code != 0) {
				il->vm->exception(ret.exception);
			}
			else {
				this->value2       = ret.consoleValue;
				this->value2getted = true;
			}
		});


		return false;
	}
	else {
		result         = calcResult();
		resultCalculed = true;

		return true;
	}
}

bool Rich::calcResult() {
	// Never called, make class not abstract
	return false;
}

}  // namespace icL::logic::rich
