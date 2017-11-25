#include "output.h"




void vm::database::basic::output::parse (system::Driver &driver) {
	int sw = driver.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::SELECT ) :
		Singleton::runSelect (driver);
		break;

	default :
		driver.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::database::basic::output::Singleton::runSelect (vm::system::Driver &driver) {

}
