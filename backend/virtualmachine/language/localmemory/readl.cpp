#include "readl.h"




void vm::language::localmemory::read::parse (main::Driver &drive) {
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

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::localmemory::read::runBoolean (vm::main::Driver &drive) {

}

void vm::language::localmemory::read::runInt (vm::main::Driver &drive) {

}

void vm::language::localmemory::read::runDouble (vm::main::Driver &drive) {

}

void vm::language::localmemory::read::runString (vm::main::Driver &drive) {

}

void vm::language::localmemory::read::runStringList (vm::main::Driver &drive) {

}

void vm::language::localmemory::read::runWebElement (vm::main::Driver &drive) {

}
