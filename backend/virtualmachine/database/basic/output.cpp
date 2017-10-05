#include "output.h"




void vm::database::basic::output::parse (const int &command) {
	using namespace vm::database::basic::output;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::SELECT ) :
		Singleton::runSelect ();
		break;

	default :
		return;//error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::database::basic::output::Singleton::runSelect () {

}
