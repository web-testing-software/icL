#include "frames.h"




void vm::driver::managecontent::frames::parse (const int &command) {
	using namespace vm::driver::managecontent::frames;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::SWITCH_TO_FRAME ) :
		Singleton::runSwitchToFrame ();
		break;

	case static_cast <int> ( Command::SWITCH_TO_DEFAULT ) :
		Singleton::runSwitchToDefault ();
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::driver::managecontent::frames::Singleton::runSwitchToFrame () {

}

void vm::driver::managecontent::frames::Singleton::runSwitchToDefault () {

}
