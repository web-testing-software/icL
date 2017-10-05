#include "frames.h"




void VM::Driver::ManageContent::Frames::parse (const int &command) {
	using namespace VM::Driver::ManageContent::Frames;

	int sw = command | static_cast<int>(VM::Filter::Level4);

	switch (sw) {
	case static_cast<int>(Command::SwitchToFrame):
		Singleton::runSwitchToFrame ();
		break;

	case static_cast<int>(Command::SwitchToDefault):
		Singleton::runSwitchToDefault ();
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::Driver::ManageContent::Frames::Singleton::runSwitchToFrame () {

}

void VM::Driver::ManageContent::Frames::Singleton::runSwitchToDefault () {

}
