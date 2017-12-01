#include "comment.h"




void vm::language::control::comment::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::DELIMITER ) :
		runDelimiter (drive);
		break;

	case static_cast <int> ( Command::LINE ) :
		runLine (drive);
		break;

	case static_cast <int> ( Command::MULTILINE ) :
		runMultiline (drive);
		break;

//	default :
//		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::control::comment::runDelimiter (vm::main::Driver &drive) {

}

void vm::language::control::comment::runLine (vm::main::Driver &drive) {

}

void vm::language::control::comment::runMultiline (vm::main::Driver &drive) {

}
