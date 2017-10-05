#include "wainting.h"




void vm::driver::navigation::wainting::parse (const int &command) {
	using namespace vm::driver::navigation::wainting;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::PREPARE_WAIT_FOR_PAGE_LOAD ) :
		Singleton::runPrepareWaitForPageLoad ();
		break;

	case static_cast <int> ( Command::WAIT_FOR_PAGE_LOAD ) :
		Singleton::runWaitForPageLoad ();
		break;

	default :
		return;//error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::driver::navigation::wainting::Singleton::runPrepareWaitForPageLoad () {

}

void vm::driver::navigation::wainting::Singleton::runWaitForPageLoad () {

}
