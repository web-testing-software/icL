#include "output.h"




void VM::DataBase::Basic::Output::parse (const int &command) {
	using namespace VM::DataBase::Basic::Output;

	int sw = command | static_cast<int>(VM::Filter::Level4);

	switch (sw) {
	case static_cast<int>(Command::Select):
		Singleton::runSelect ();
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::DataBase::Basic::Output::Singleton::runSelect () {

}
