#include "editing.h"




void vm::database::basic::editing::parse (system::Driver &driver) {
	int sw = driver.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::INSERT ) :
		Singleton::runInsert (driver);
		break;

	default :
		driver.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::database::basic::editing::Singleton::runInsert (vm::system::Driver &driver) {

}
