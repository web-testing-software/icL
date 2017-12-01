#include "complexeventm.h"




void vm::input::mouse::complexevent::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::CLICK ) :
		runClick (drive);
		break;

//	default :
//		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::input::mouse::complexevent::runClick (vm::main::Driver &drive) {

}
