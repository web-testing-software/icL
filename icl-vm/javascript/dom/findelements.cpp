#include "findelements.h"


namespace vm::javascript::dom::findelements {

void parse (main::Driver &drive) {
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

void runQuery (main::Driver &drive) {

}

void runQueryAll (main::Driver &drive) {

}

}
