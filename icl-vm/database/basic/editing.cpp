#include "editing.h"


namespace vm::database::basic::editing {

void parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::INSERT ) :
		runInsert (drive);
		break;

//	default :
//		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void runInsert (main::Driver &drive) {

}

}
