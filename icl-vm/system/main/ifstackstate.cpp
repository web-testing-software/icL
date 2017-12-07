#include "../../language/control/singleshot.h"
#include "ifstackstate.h"
//#include "virtualmachine.h"

namespace vm::memory {

IfStackState::IfStackState (StackState *prev, int stackLevel)
	: StackState (prev, stackLevel) {

}

bool IfStackState::tryToDestroy () {
	// This is not a loop, always returns true
	return true;
}

void IfStackState::releaseCondition () {

}

}
