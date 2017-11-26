#include "logical.h"




void vm::language::booloperator::logical::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::NOT ) :
		Singleton::runNot (drive);
		break;

	case static_cast <int> ( Command::AND ) :
		Singleton::runAnd (drive);
		break;

	case static_cast <int> ( Command::OR ) :
		Singleton::runOr (drive);
		break;

	case static_cast <int> ( Command::XOR ) :
		Singleton::runXOr (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::booloperator::logical::Singleton::runNot (vm::main::Driver &drive) {

}

void vm::language::booloperator::logical::Singleton::runAnd (vm::main::Driver &drive) {

}

void vm::language::booloperator::logical::Singleton::runOr (vm::main::Driver &drive) {

}

void vm::language::booloperator::logical::Singleton::runXOr (vm::main::Driver &drive) {

}
