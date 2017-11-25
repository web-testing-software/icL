#include "frames.h"




void vm::driver::managecontent::frames::parse (system::Driver &driver) {
	int sw = driver.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::SWITCH_TO_FRAME ) :
		Singleton::runSwitchToFrame (driver);
		break;

	case static_cast <int> ( Command::SWITCH_TO_DEFAULT ) :
		Singleton::runSwitchToDefault (driver);
		break;

	default :
		driver.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::driver::managecontent::frames::Singleton::runSwitchToFrame (vm::system::Driver &driver) {

}

void vm::driver::managecontent::frames::Singleton::runSwitchToDefault (vm::system::Driver &driver) {

}
