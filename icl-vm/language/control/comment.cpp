#include "comment.h"


namespace vm::language::control::comment {

void parse (main::Driver &drive) {
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

void runDelimiter (main::Driver &drive) {

}

void runLine (main::Driver &drive) {

}

void runMultiline (main::Driver &drive) {

}

}
