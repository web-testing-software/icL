#include "runjs.h"




void VM::JavaScript::BaseJS::RunJS::parse (const int &command) {
	using namespace VM::JavaScript::BaseJS::RunJS;

	int sw = command | static_cast<int>(VM::Filter::Level4);

	switch (sw) {
	case static_cast<int>(Command::RunString):
		Singleton::runRunString ();
		break;

	case static_cast<int>(Command::RunFile):
		Singleton::runRunFile ();
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::JavaScript::BaseJS::RunJS::Singleton::runRunString () {

}

void VM::JavaScript::BaseJS::RunJS::Singleton::runRunFile () {

}
