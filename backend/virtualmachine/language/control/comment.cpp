#include "comment.h"




void vm::language::control::comment::parse (const int &command) {
	using namespace vm::language::control::comment;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::DELIMITER ) :
		Singleton::runDelimiter ();
		break;

	case static_cast <int> ( Command::LINE ) :
		Singleton::runLine ();
		break;

	case static_cast <int> ( Command::MULTILINE ) :
		Singleton::runMultiline ();
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::control::comment::Singleton::runDelimiter () {

}

void vm::language::control::comment::Singleton::runLine () {

}

void vm::language::control::comment::Singleton::runMultiline () {

}
