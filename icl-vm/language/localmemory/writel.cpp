#include "writel.h"


namespace vm::language::localmemory::write {

void parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::BOOLEAN ) :
		runBoolean (drive);
		break;

	case static_cast <int> ( Command::INT ) :
		runInt (drive);
		break;

	case static_cast <int> ( Command::DOUBLE ) :
		runDouble (drive);
		break;

	case static_cast <int> ( Command::STRING ) :
		runString (drive);
		break;

	case static_cast <int> ( Command::STRING_LIST ) :
		runStringList (drive);
		break;

	case static_cast <int> ( Command::WEB_ELEMENT ) :
		runWebElement (drive);
		break;

//	default :
//		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void runBoolean (main::Driver &drive) {

}

void runInt (main::Driver &drive) {

}

void runDouble (main::Driver &drive) {

}

void runString (main::Driver &drive) {

}

void runStringList (main::Driver &drive) {

}

void runWebElement (main::Driver &drive) {

}

}
