#include "navigation.h"




void VM::Driver::Navigation::Navigation::parse (const int &command) {
	using namespace VM::Driver::Navigation::Navigation;

	int sw = command | static_cast<int>(VM::Filter::Level4);

	switch (sw) {
	case static_cast<int>(Command::GoToURL):
		Singleton::runGoToURL ();
		break;

	default:
		error = Errors::CommandNotFound;
	}

}

void VM::Driver::Navigation::Navigation::Singleton::runGoToURL () {

}
