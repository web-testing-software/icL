#include "focus.h"




void VM::Debugger::Basic::Focus::parse (const int &command) {
	using namespace VM::Debugger::Basic::Focus;

	int sw = command | static_cast<int>(VM::Filter::Level4);

	switch (sw) {
	case static_cast<int>(Command::Command):
		Singleton::runCommand ();
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::Debugger::Basic::Focus::Singleton::runCommand () {

}
