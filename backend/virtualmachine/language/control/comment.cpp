#include "comment.h"




void vm::language::control::comment::parse (system::Driver &driver) {
	int sw = driver.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::DELIMITER ) :
		Singleton::runDelimiter (driver);
		break;

	case static_cast <int> ( Command::LINE ) :
		Singleton::runLine (driver);
		break;

	case static_cast <int> ( Command::MULTILINE ) :
		Singleton::runMultiline (driver);
		break;

	default :
		driver.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::control::comment::Singleton::runDelimiter (vm::system::Driver &driver) {

}

void vm::language::control::comment::Singleton::runLine (vm::system::Driver &driver) {

}

void vm::language::control::comment::Singleton::runMultiline (vm::system::Driver &driver) {

}
