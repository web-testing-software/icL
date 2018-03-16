#include "wainting.h"


namespace vm::driver::navigation::wainting {

void parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::PREPARE_WAIT_FOR_PAGE_LOAD ) :
		runPrepareWaitForPageLoad (drive);
		break;

	case static_cast <int> ( Command::WAIT_FOR_PAGE_LOAD ) :
		runWaitForPageLoad (drive);
		break;

//	default :
//		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void runPrepareWaitForPageLoad (main::Driver &drive) {

}

void runWaitForPageLoad (main::Driver &drive) {

}

}
