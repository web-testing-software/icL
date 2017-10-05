#include "readc.h"




void VM::Language::Constant::Read::parse (const int &command) {
	using namespace VM::Language::Constant::Read;

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

void VM::Language::Constant::Read::Singleton::runBoolean () {

}

void VM::Language::Constant::Read::Singleton::runInt () {

}

void VM::Language::Constant::Read::Singleton::runDouble () {

}

void VM::Language::Constant::Read::Singleton::runString () {

}

void VM::Language::Constant::Read::Singleton::runStringList () {

}
