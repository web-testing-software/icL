#include "complexeventm.h"




void vm::input::mouse::complexevent::parse (const int &command) {
	using namespace vm::input::mouse::complexevent;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::CLICK ) :
		Singleton::runClick ();
		break;

	default :
		return;//error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::input::mouse::complexevent::Singleton::runClick () {

}
