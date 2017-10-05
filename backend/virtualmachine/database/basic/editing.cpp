#include "editing.h"




void VM::DataBase::Basic::Editing::parse (const int &command) {
	using namespace VM::DataBase::Basic::Editing;

	int sw = command | static_cast<int>(VM::Filter::Level4);

	switch (sw) {
	case static_cast<int>(Command::Insert):
		Singleton::runInsert ();
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::DataBase::Basic::Editing::Singleton::runInsert () {

}
