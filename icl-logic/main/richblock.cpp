// #include "../../main/virtualmachine.h"
#include "richblock.h"

namespace vm::logic {

RichBlock::RichBlock (OperationType otype) {
	operationType = otype;
}

RichBlock::~RichBlock () = default;

/**
 * @brief RichBlock::canAcceptVar - if the first or the second var/const are not setted
 * @return bool
 */
bool RichBlock::canAcceptCode () {
	return frag2.source == nullptr;
}

/**
 * @brief RichBlock::giveVar - set up next var/const
 * @param varname - var/const
 */
void RichBlock::giveCode (memory::CodeFragment frag) {
	if (frag1.source == nullptr) {
		frag1 = frag;
	}
	else if (frag2.source == nullptr) {
		frag2 = frag;
	}
}

/**
 * @brief RichBlock::isCross - it cann't contains blocks like child
 * @return false
 */
bool RichBlock::isCross () {
	return false;
}

/**
 * @brief RichBlock::checkIntegrity - if the both var/const are setted
 * @return bool
 */
bool RichBlock::checkIntegrity () {
	if (frag1.source == nullptr || frag2.source == nullptr) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
		return false;
	}
	return true;
}

/**
 * @brief RichBlock::oTypeToString - operation type to string, special for errors messages
 * @return a string with operation token (==, !=, <<,  <*)
 */
QString RichBlock::oTypeToString () {
	QString ret;

	switch (operationType) {
	case OperationType::EQUAL :
		ret = QStringLiteral ("==");
		break;

	case OperationType::NOT_EQUAL :
		ret = QStringLiteral ("!=");
		break;

	case OperationType::CONTAINS :
		ret = QStringLiteral ("<<");
		break;

	case OperationType::CONTAINS_FRAGMENT :
		ret = QStringLiteral ("<*");
		break;

	default :
		ret = QStringLiteral ("?");
	}

	return ret;
}


/**
 * @brief RichBlock::pairData - give data for error messages
 * @return a string, which contains the type of the first and second values
 */
QString RichBlock::pairData () {
	return "[" + typeToString (value1.type () ) + "-" + typeToString (value2.type () ) + "]";
}

void RichBlock::sendSignalWrongPair () {
	emit exception (-201, "Wrong operarands pair: " + pairData () );
}

void RichBlock::sendSignalWrongOperator (const QString &pair) {
	emit exception (-202, "Wrong operator " + oTypeToString () + " for operands pair " + pair);
}

}
