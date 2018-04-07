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
	return frag2.source == nullptr;
}

/**
 * @brief RichBlock::giveVar - set up next var/const
 * @param varname - var/const
 */
void RichBlock::giveCode (memory::CodeFragment frag) {
	if (frag1.source == nullptr ) {
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
	if (frag1.source == nullptr || frag2.source == nullptr ) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
		return false;
	}
	return true;
}

}
