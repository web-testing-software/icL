#include "navigation.h"




void vm::driver::navigation::navigation::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::GO_TO_URL ) :
		runGoToURL (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}

}

void vm::driver::navigation::navigation::runGoToURL (vm::main::Driver &drive) {

}
