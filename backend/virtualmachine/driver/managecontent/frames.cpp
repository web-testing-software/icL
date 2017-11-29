#include "frames.h"




void vm::driver::managecontent::frames::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::SWITCH_TO_FRAME ) :
		runSwitchToFrame (drive);
		break;

	case static_cast <int> ( Command::SWITCH_TO_DEFAULT ) :
		runSwitchToDefault (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::driver::managecontent::frames::runSwitchToFrame (vm::main::Driver &drive) {

}

void vm::driver::managecontent::frames::runSwitchToDefault (vm::main::Driver &drive) {

}
