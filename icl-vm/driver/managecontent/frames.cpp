#include "frames.h"


namespace vm::driver::managecontent::frames {

void parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::SWITCH_TO_FRAME ) :
		runSwitchToFrame (drive);
		break;

	case static_cast <int> ( Command::SWITCH_TO_DEFAULT ) :
		runSwitchToDefault (drive);
		break;

//	default :
//		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void runSwitchToFrame (main::Driver &drive) {

}

void runSwitchToDefault (main::Driver &drive) {

}

}
