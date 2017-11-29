#include "wainting.h"




void vm::driver::navigation::wainting::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::PREPARE_WAIT_FOR_PAGE_LOAD ) :
		runPrepareWaitForPageLoad (drive);
		break;

	case static_cast <int> ( Command::WAIT_FOR_PAGE_LOAD ) :
		runWaitForPageLoad (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::driver::navigation::wainting::runPrepareWaitForPageLoad (vm::main::Driver &drive) {

}

void vm::driver::navigation::wainting::runWaitForPageLoad (vm::main::Driver &drive) {

}
