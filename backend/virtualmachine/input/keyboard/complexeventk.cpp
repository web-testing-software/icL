#include "complexeventk.h"




void vm::input::keyboard::complexevent::parse (const int &command) {
	using namespace vm::input::keyboard::complexevent;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::SEND_KEY ) :
		Singleton::runSendKey ();
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::input::keyboard::complexevent::Singleton::runSendKey () {

}
