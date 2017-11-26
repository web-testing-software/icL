#include "stringlist.h"




void vm::language::booloperator::stringlist::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::CONTAINS ) :
		Singleton::runContains (drive);
		break;

	case static_cast <int> ( Command::CONSTAINS_FRAGMENT ) :
		Singleton::runContainsFragment (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::booloperator::stringlist::Singleton::runContains (vm::main::Driver &drive) {

}

void vm::language::booloperator::stringlist::Singleton::runContainsFragment (vm::main::Driver &drive) {

}
