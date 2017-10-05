#include "complexeventm.h"




void VM::Input::Mouse::ComplexEvent::parse (const int &command) {
	using namespace VM::Input::Mouse::ComplexEvent;

	int sw = command | static_cast<int>(VM::Filter::Level4);

	switch (sw) {
	case static_cast<int>(Command::Click):
		Singleton::runClick ();
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::Input::Mouse::ComplexEvent::Singleton::runClick () {

}
