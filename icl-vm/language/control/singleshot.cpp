#include "singleshot.h"

namespace vm::language::control::singleshot {

void parse (main::Driver &drive) {
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

	case static_cast <int> ( Command::UNEXPECTED_END ) :
		runUnexpectedEnd (drive);
		break;

	case static_cast <int> ( Command::SUCCESS ) :
		runSuccess (drive);
		break;

	case static_cast <int> ( Command::FAILED ) :
		runFailed (drive);
		break;

	case static_cast <int> ( Command::EMPTY_STACK ) :
		runEmptyStack (drive);
		break;

	case static_cast <int> ( Command::OPEN_STACK ) :
		runOpenStack (drive);
		break;

	case static_cast <int> ( Command::DROP_STACK ) :
		runDropStack (drive);
		break;

//	default :
//		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void runIf (main::Driver &drive) {
//	stackStateIterator->openNewStack (system::StackState::StackType::IF_STACK);
}

void runBeginIf (main::Driver &drive) {
//	system::CommandsToSearch commads = drive.

//	if ()
}

void runElse (main::Driver &drive) {

}

void runUnexpectedEnd (main::Driver &drive) {

}

void runSuccess (main::Driver &drive) {

}

void runFailed (main::Driver &drive) {

}

void runEmptyStack (main::Driver &drive) {

}

void runOpenStack (main::Driver &drive) {

}

void runDropStack (main::Driver &drive) {

}

}
