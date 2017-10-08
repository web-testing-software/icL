#include "../../language/control/singleshot.h"
#include "ifstackstate.h"
#include "virtualmachine.h"


vm::system::IfStackState::IfStackState (StackState *prev, int stackLevel)
	: StackState (prev, stackLevel) {

}

bool vm::system::IfStackState::tryToDestroy () {
	// This is not a loop, always returns true
	return true;
}

void vm::system::IfStackState::releaseCondition () {
	CommandsToSearch commands;

	if (logicBlock->getResult ()) {
		commands.command1 = static_cast <int> ( language::control::singleshot::Command::BEGIN_IF );
		commands.command2 = static_cast <int> ( language::control::singleshot::Command::BEGIN_IF );
	}
	else {
		commands.command1	= static_cast <int> ( language::control::singleshot::Command::ELSE );
		commands.command2	= static_cast <int> ( language::control::singleshot::Command::END_IF );
	}

	virtualMachine->search (commands);
}
