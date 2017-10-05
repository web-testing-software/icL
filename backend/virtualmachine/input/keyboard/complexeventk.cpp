#include "complexeventk.h"




void VM::Input::Keyboard::ComplexEvent::parse (const int &command) {
	using namespace VM::Input::Keyboard::ComplexEvent;

	int sw = command | static_cast<int>(VM::Filter::Level4);

	switch (sw) {
	case static_cast<int>(Command::SendKey):
		Singleton::runSendKey ();
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::Input::Keyboard::ComplexEvent::Singleton::runSendKey () {

}
