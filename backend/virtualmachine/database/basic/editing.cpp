#include "editing.h"




void vm::database::basic::editing::parse (const int &command) {
	using namespace vm::database::basic::editing;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::INSERT ) :
		Singleton::runInsert ();
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::database::basic::editing::Singleton::runInsert () {

}
