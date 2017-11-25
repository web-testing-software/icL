#include "runjs.h"




void vm::javascript::basejs::runjs::parse (system::Driver &driver) {
	int sw = driver.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::RUN_STRING ) :
		Singleton::runRunString (driver);
		break;

	case static_cast <int> ( Command::RUN_FILE ) :
		Singleton::runRunFile (driver);
		break;

	default :
		driver.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::javascript::basejs::runjs::Singleton::runRunString (vm::system::Driver &driver) {

}

void vm::javascript::basejs::runjs::Singleton::runRunFile (vm::system::Driver &driver) {

}
