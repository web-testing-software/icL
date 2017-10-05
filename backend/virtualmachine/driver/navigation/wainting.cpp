#include "wainting.h"




void VM::Driver::Navigation::Wainting::parse (const int &command) {
	using namespace VM::Driver::Navigation::Wainting;

	int sw = command | static_cast<int>(VM::Filter::Level4);

	switch (sw) {
	case static_cast<int>(Command::PrepareWaitForPageLoad):
		Singleton::runPrepareWaitForPageLoad ();
		break;

	case static_cast<int>(Command::WaitForPageLoad):
		Singleton::runWaitForPageLoad ();
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::Driver::Navigation::Wainting::Singleton::runPrepareWaitForPageLoad () {

}

void VM::Driver::Navigation::Wainting::Singleton::runWaitForPageLoad () {

}
