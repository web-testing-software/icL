#include "system.h"




void vm::debugger::basic::system::parse (const int &command) {
	using namespace vm::debugger::basic::focus;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::COMMAND ) :
		Singleton::runReport ();
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::debugger::basic::system::Singleton::runReport () {

}
