#include "notequal.h"




void vm::language::booloperator::notequal::parse (main::Driver &drive) {
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

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::booloperator::notequal::runBoolean (vm::main::Driver &drive) {

}

void vm::language::booloperator::notequal::runInt (vm::main::Driver &drive) {

}

void vm::language::booloperator::notequal::runDouble (vm::main::Driver &drive) {

}

void vm::language::booloperator::notequal::runString (vm::main::Driver &drive) {

}

void vm::language::booloperator::notequal::runStringList (vm::main::Driver &drive) {

}
