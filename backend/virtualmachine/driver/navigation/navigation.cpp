#include "navigation.h"




void vm::driver::navigation::navigation::parse (const int &command) {
	using namespace vm::driver::navigation::navigation;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::GO_TO_URL ) :
		Singleton::runGoToURL ();
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}

}

void vm::driver::navigation::navigation::Singleton::runGoToURL () {

}
