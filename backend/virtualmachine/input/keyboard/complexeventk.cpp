#include "complexeventk.h"




void vm::input::keyboard::complexevent::parse (system::Driver &driver) {
	int sw = driver.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::SEND_KEY ) :
		Singleton::runSendKey (driver);
		break;

	default :
		driver.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::input::keyboard::complexevent::Singleton::runSendKey (vm::system::Driver &driver) {

}
