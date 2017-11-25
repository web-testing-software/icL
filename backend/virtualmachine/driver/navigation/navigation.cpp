#include "navigation.h"




void vm::driver::navigation::navigation::parse (system::Driver &driver) {
	int sw = driver.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::GO_TO_URL ) :
		Singleton::runGoToURL (driver);
		break;

	default :
		driver.setError (Error::COMMAND_NOT_FOUND);
	}

}

void vm::driver::navigation::navigation::Singleton::runGoToURL (vm::system::Driver &driver) {

}
