#include "../../main/virtualmachine.h"
#include "richblock.h"


vm::main::logic::RichBlock::RichBlock (OperationType otype) {
	operationType = otype;
}

bool vm::main::logic::RichBlock::canAcceptVar () {
	return var2name.isEmpty ();
}

void vm::main::logic::RichBlock::giveVar (QString &varname) {
	if (var1name.isEmpty ()) {
		var1name = varname;
	}
	else if (var2name.isEmpty ()) {
		var2name = var2name;
	}
}

bool vm::main::logic::RichBlock::isCross () {
	return false;
}


bool vm::main::logic::RichBlock::checkIntegrity () {
	if (var1name.isEmpty () || var2name.isEmpty ()) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
		return false;
	}
	return true;
}
