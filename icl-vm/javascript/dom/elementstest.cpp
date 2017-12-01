#include "elementstest.h"




void vm::javascript::dom::elementstest::parse (main::Driver &drive) {
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

void vm::javascript::dom::elementstest::runIsVisible (vm::main::Driver &drive) {

}

void vm::javascript::dom::elementstest::runGetX (vm::main::Driver &drive) {

}

void vm::javascript::dom::elementstest::runGetY (vm::main::Driver &drive) {

}
