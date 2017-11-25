#include "complexeventm.h"




void vm::input::mouse::complexevent::parse (system::Driver &driver) {
	int sw = driver.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::CLICK ) :
		Singleton::runClick (driver);
		break;

	default :
		driver.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::input::mouse::complexevent::Singleton::runClick (vm::system::Driver &driver) {

}
