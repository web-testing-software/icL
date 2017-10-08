#include "runjs.h"




void vm::javascript::basejs::runjs::parse (const int &command) {
	using namespace vm::javascript::basejs::runjs;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::RUN_STRING ) :
		Singleton::runRunString ();
		break;

	case static_cast <int> ( Command::RUN_FILE ) :
		Singleton::runRunFile ();
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::javascript::basejs::runjs::Singleton::runRunString () {

}

void vm::javascript::basejs::runjs::Singleton::runRunFile () {

}
