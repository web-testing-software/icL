#include "focus.h"




void vm::debugger::basic::focus::parse (const int &command) {
	using namespace vm::debugger::basic::focus;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::COMMAND ) :
		Singleton::runCommand ();
		break;

	default :
		return;//error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::debugger::basic::focus::Singleton::runCommand () {

}
