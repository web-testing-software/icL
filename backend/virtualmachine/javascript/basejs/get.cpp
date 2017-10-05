#include "get.h"




void VM::JavaScript::BaseJS::Get::parse (const int &command) {
	using namespace VM::JavaScript::BaseJS::Get;

	int sw = command | static_cast<int>(VM::Filter::Level4);

	switch (sw) {
	case static_cast<int>(Command::Boolean):
		Singleton::runBoolean ();
		break;

	case static_cast<int>(Command::Int):
		Singleton::runInt ();
		break;

	case static_cast<int>(Command::Double):
		Singleton::runDouble ();
		break;

	case static_cast<int>(Command::String):
		Singleton::runString ();
		break;

	case static_cast<int>(Command::StringList):
		Singleton::runStringList ();
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::JavaScript::BaseJS::Get::Singleton::runBoolean () {

}

void VM::JavaScript::BaseJS::Get::Singleton::runInt () {

}

void VM::JavaScript::BaseJS::Get::Singleton::runDouble () {

}

void VM::JavaScript::BaseJS::Get::Singleton::runString () {

}

void VM::JavaScript::BaseJS::Get::Singleton::runStringList () {

}
