#include "../../main/virtualmachine.h"
#include "richblock.h"


vm::system::logic::RichBlock::RichBlock (OperationType otype) {
	operationType = otype;
}

bool vm::system::logic::RichBlock::canAcceptVar () {

}

void vm::system::logic::RichBlock::giveVar (QString &varname) {

}

bool vm::system::logic::RichBlock::isCross () {
}


bool vm::system::logic::RichBlock::checkIntegrity()
{
	if (var1name.isEmpty () || var2name.isEmpty ()) {
		return false;
	}
//	return
}
