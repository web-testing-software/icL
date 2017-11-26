#include "complexeventk.h"




void vm::input::keyboard::complexevent::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::SEND_KEY ) :
		Singleton::runSendKey (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::input::keyboard::complexevent::Singleton::runSendKey (vm::main::Driver &drive) {

}
