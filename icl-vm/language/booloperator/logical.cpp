#include "logical.h"




void vm::language::booloperator::logical::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::NOT ) :
		runNot (drive);
		break;

	case static_cast <int> ( Command::AND ) :
		runAnd (drive);
		break;

	case static_cast <int> ( Command::OR ) :
		runOr (drive);
		break;

	case static_cast <int> ( Command::XOR ) :
		runXOr (drive);
		break;

//	default :
//		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::booloperator::logical::runNot (vm::main::Driver &drive) {

}

void vm::language::booloperator::logical::runAnd (vm::main::Driver &drive) {

}

void vm::language::booloperator::logical::runOr (vm::main::Driver &drive) {

}

void vm::language::booloperator::logical::runXOr (vm::main::Driver &drive) {

}
