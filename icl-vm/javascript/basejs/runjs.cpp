#include "runjs.h"


namespace vm::javascript::basejs::runjs {

void parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::RUN_STRING ) :
		runRunString (drive);
		break;

	case static_cast <int> ( Command::RUN_FILE ) :
		runRunFile (drive);
		break;

//	default :
//		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void runRunString (main::Driver &drive) {

}

void runRunFile (main::Driver &drive) {

}

}
