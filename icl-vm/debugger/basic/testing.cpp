#include "testing.h"


namespace vm::debugger::basic::testing {

void parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::REPORT ) :
		runReport (drive);
		break;

//	default :
//		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void runReport (main::Driver &drive) {

}

}
