#include "stringlist.h"




void vm::language::booloperator::stringlist::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::CONTAINS ) :
		runContains (drive);
		break;

	case static_cast <int> ( Command::CONSTAINS_FRAGMENT ) :
		runContainsFragment (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::booloperator::stringlist::runContains (vm::main::Driver &drive) {

}

void vm::language::booloperator::stringlist::runContainsFragment (vm::main::Driver &drive) {

}
