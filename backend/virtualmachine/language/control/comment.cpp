#include "comment.h"




void vm::language::control::comment::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::DELIMITER ) :
		Singleton::runDelimiter (drive);
		break;

	case static_cast <int> ( Command::LINE ) :
		Singleton::runLine (drive);
		break;

	case static_cast <int> ( Command::MULTILINE ) :
		Singleton::runMultiline (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::control::comment::Singleton::runDelimiter (vm::main::Driver &drive) {

}

void vm::language::control::comment::Singleton::runLine (vm::main::Driver &drive) {

}

void vm::language::control::comment::Singleton::runMultiline (vm::main::Driver &drive) {

}
