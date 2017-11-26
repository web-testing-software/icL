#include "output.h"




void vm::database::basic::output::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::SELECT ) :
		Singleton::runSelect (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::database::basic::output::Singleton::runSelect (vm::main::Driver &drive) {

}
