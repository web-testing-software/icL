#include "system.h"




void vm::debugger::basic::system::parse (vm::system::Driver &driver) {
	int sw = driver.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::REPORT ) :
		Singleton::runReport (driver);
		break;

	default :
		driver.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::debugger::basic::system::Singleton::runReport (vm::system::Driver &driver) {

}
