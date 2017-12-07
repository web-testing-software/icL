#include "elementstest.h"


namespace vm::javascript::dom::elementstest {

void parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::IS_VISIBLE ) :
		runIsVisible (drive);
		break;

	case static_cast <int> ( Command::GET_X ) :
		runGetX (drive);
		break;

	case static_cast <int> ( Command::GET_Y ) :
		runGetY (drive);
		break;

//	default :
//		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void runIsVisible (main::Driver &drive) {

}

void runGetX (main::Driver &drive) {

}

void runGetY (main::Driver &drive) {

}

}
