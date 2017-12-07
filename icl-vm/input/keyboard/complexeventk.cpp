#include "complexeventk.h"


namespace vm::input::keyboard::complexevent {

void parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::SEND_KEY ) :
		runSendKey (drive);
		break;

//	default :
//		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void runSendKey (main::Driver &drive) {

}

}
