#include "../../language/control/singleshot.h"
#include "ifstackstate.h"
#include "virtualmachine.h"


vm::main::IfStackState::IfStackState (StackState *prev, int stackLevel)
	: StackState (prev, stackLevel) {

}

bool vm::main::IfStackState::tryToDestroy () {
	// This is not a loop, always returns true
	return true;
}

void vm::main::IfStackState::releaseCondition () {

}
