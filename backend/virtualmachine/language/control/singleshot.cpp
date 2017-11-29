#include "singleshot.h"



void vm::language::control::singleshot::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::IF ) :
		runIf (drive);
		break;

	case static_cast <int> ( Command::BEGIN_IF ) :
		runBeginIf (drive);
		break;

	case static_cast <int> ( Command::ELSE ) :
		runElse (drive);
		break;

	case static_cast <int> ( Command::END_IF ) :
		runEndIf (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::control::singleshot::runIf (vm::main::Driver &drive) {
//	stackStateIterator->openNewStack (system::StackState::StackType::IF_STACK);
}

void vm::language::control::singleshot::runBeginIf (vm::main::Driver &drive) {
//	system::CommandsToSearch commads = drive.
	
//	if ()
}

void vm::language::control::singleshot::runElse (vm::main::Driver &drive) {

}

void vm::language::control::singleshot::runEndIf (vm::main::Driver &drive) {

}
