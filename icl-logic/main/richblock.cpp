// #include "../../main/virtualmachine.h"
#include "richblock.h"

namespace vm::main::logic {

RichBlock::RichBlock (OperationType otype) {
	operationType = otype;
}

RichBlock::~RichBlock () {

}

/**
 * @brief RichBlock::canAcceptVar - if the first or the second var/const are not setted
 * @return bool
 */
bool RichBlock::canAcceptVar () {
	return var2name.isEmpty ();
}

/**
 * @brief RichBlock::giveVar - set up next var/const
 * @param varname - var/const
 */
void RichBlock::giveVar (QString &varname) {
	if (var1name.isEmpty () ) {
		var1name = varname;
	}
	else if (var2name.isEmpty () ) {
		var2name = var2name;
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
	if (var1name.isEmpty () || var2name.isEmpty () ) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
		return false;
	}
	return true;
}

}
