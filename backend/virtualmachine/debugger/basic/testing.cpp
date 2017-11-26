#include "testing.h"




void vm::debugger::basic::testing::parse (vm::main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::REPORT ) :
		Singleton::runReport (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::debugger::basic::testing::Singleton::runReport (vm::main::Driver &drive) {

}
