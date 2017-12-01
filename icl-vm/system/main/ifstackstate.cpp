#include "../../language/control/singleshot.h"
#include "ifstackstate.h"
//#include "virtualmachine.h"


vm::memory::IfStackState::IfStackState (StackState *prev, int stackLevel)
	: StackState (prev, stackLevel) {

}

bool vm::memory::IfStackState::tryToDestroy () {
	// This is not a loop, always returns true
	return true;
}

void vm::memory::IfStackState::releaseCondition () {

}
