//#include "../../main/virtualmachine.h"
#include "richblock.h"

namespace vm::main::logic {

RichBlock::RichBlock (OperationType otype) {
	operationType = otype;
}

bool RichBlock::canAcceptVar () {
	return var2name.isEmpty ();
}

void RichBlock::giveVar (QString &varname) {
	if (var1name.isEmpty ()) {
		var1name = varname;
	}
	else if (var2name.isEmpty ()) {
		var2name = var2name;
	}
}

bool RichBlock::isCross () {
	return false;
}


bool RichBlock::checkIntegrity () {
	if (var1name.isEmpty () || var2name.isEmpty ()) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
		return false;
	}
	return true;
}

}
