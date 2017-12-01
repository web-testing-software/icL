#include "findelements.h"




void vm::javascript::dom::findelements::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::QUERY ) :
		runQuery (drive);
		break;

	case static_cast <int> ( Command::QUERY_ALL ) :
		runQueryAll (drive);
		break;

//	default :
//		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::javascript::dom::findelements::runQuery (vm::main::Driver &drive) {

}

void vm::javascript::dom::findelements::runQueryAll (vm::main::Driver &drive) {

}
