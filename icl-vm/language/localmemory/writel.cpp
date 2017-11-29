#include "writel.h"




void vm::language::localmemory::write::parse (main::Driver &drive) {
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

void vm::language::localmemory::write::runBoolean (vm::main::Driver &drive) {

}

void vm::language::localmemory::write::runInt (vm::main::Driver &drive) {

}

void vm::language::localmemory::write::runDouble (vm::main::Driver &drive) {

}

void vm::language::localmemory::write::runString (vm::main::Driver &drive) {

}

void vm::language::localmemory::write::runStringList (vm::main::Driver &drive) {

}

void vm::language::localmemory::write::runWebElement (vm::main::Driver &drive) {

}
