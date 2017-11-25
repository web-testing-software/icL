#include "wainting.h"




void vm::driver::navigation::wainting::parse (system::Driver &driver) {
	int sw = driver.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::PREPARE_WAIT_FOR_PAGE_LOAD ) :
		Singleton::runPrepareWaitForPageLoad (driver);
		break;

	case static_cast <int> ( Command::WAIT_FOR_PAGE_LOAD ) :
		Singleton::runWaitForPageLoad (driver);
		break;

	default :
		driver.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::driver::navigation::wainting::Singleton::runPrepareWaitForPageLoad (vm::system::Driver &driver) {

}

void vm::driver::navigation::wainting::Singleton::runWaitForPageLoad (vm::system::Driver &driver) {

}
