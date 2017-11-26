#include "readc.h"




void vm::language::constant::read::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::BOOLEAN ) :
		Singleton::runBoolean (drive);
		break;

	case static_cast <int> ( Command::INT ) :
		Singleton::runInt (drive);
		break;

	case static_cast <int> ( Command::DOUBLE ) :
		Singleton::runDouble (drive);
		break;

	case static_cast <int> ( Command::STRING ) :
		Singleton::runString (drive);
		break;

	case static_cast <int> ( Command::STRING_LIST ) :
		Singleton::runStringList (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::constant::read::Singleton::runBoolean (vm::main::Driver &drive) {

}

void vm::language::constant::read::Singleton::runInt (vm::main::Driver &drive) {

}

void vm::language::constant::read::Singleton::runDouble (vm::main::Driver &drive) {

}

void vm::language::constant::read::Singleton::runString (vm::main::Driver &drive) {

}

void vm::language::constant::read::Singleton::runStringList (vm::main::Driver &drive) {

}
