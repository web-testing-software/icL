#include "editing.h"




void vm::database::basic::editing::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::INSERT ) :
		Singleton::runInsert (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::database::basic::editing::Singleton::runInsert (vm::main::Driver &drive) {

}
