#include "filterelements.h"


namespace vm::javascript::dom::filterelements {

void parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::BY_CSS_SELECTOR ) :
		runByCSSSelector (drive);
		break;

	case static_cast <int> ( Command::BY_CONTENT ) :
		runByContent (drive);
		break;

//	default :
//		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void runByCSSSelector (main::Driver &drive) {

}

void runByContent (main::Driver &drive) {

}

}
