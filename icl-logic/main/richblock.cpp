// #include "../../main/virtualmachine.h"
#include "richblock.h"

namespace vm::logic {

RichBlock::RichBlock (OperationType otype) {
	operationType = otype;
}

RichBlock::~RichBlock () {

}

/**
 * @brief RichBlock::canAcceptVar - if the first or the second var/const are not setted
 * @return bool
 */
bool RichBlock::canAcceptCode () {
	return code2 == nullptr;
}

/**
 * @brief RichBlock::giveVar - set up next var/const
 * @param varname - var/const
 */
void RichBlock::giveCode (QString *code, int begin, int end) {
	if (code1 == nullptr ) {
		code1 = code;
		code1begin = begin;
		code1end = end;
	}
	else if (code2 == nullptr) {
		code1 = code;
		code1begin = begin;
		code1end = end;
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
	if (code1 == nullptr || code2 == nullptr ) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
		return false;
	}
	return true;
}

}
