#include "runjs.h"




void vm::javascript::basejs::runjs::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::RUN_STRING ) :
		runRunString (drive);
		break;

	case static_cast <int> ( Command::RUN_FILE ) :
		runRunFile (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::javascript::basejs::runjs::runRunString (vm::main::Driver &drive) {

}

void vm::javascript::basejs::runjs::runRunFile (vm::main::Driver &drive) {

}
