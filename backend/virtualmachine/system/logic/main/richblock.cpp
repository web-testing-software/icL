#include "../../main/virtualmachine.h"
#include "richblock.h"


vm::system::logic::RichBlock::RichBlock (OperationType otype) {
	operationType = otype;
}

bool vm::system::logic::RichBlock::canAcceptVar () {
	return var2name.isEmpty ();
}

void vm::system::logic::RichBlock::giveVar (QString &varname) {
	if (var1name.isEmpty ()) {
		var1name = varname;
	}
	else if (var2name.isEmpty ()) {
		var2name = var2name;
	}
}

bool vm::system::logic::RichBlock::isCross () {
	return false;
}


bool vm::system::logic::RichBlock::checkIntegrity () {
	if (var1name.isEmpty () || var2name.isEmpty ()) {
		resultValue = ResultValue::INTEGRITY_CHECK_FAILED;
		return false;
	}
	return true;
}
