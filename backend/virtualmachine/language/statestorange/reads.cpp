#include "reads.h"




void VM::Language::StateStorange::Read::parse (const int &command) {
	using namespace VM::Language::StateStorange::Read;

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

void VM::Language::StateStorange::Read::Singleton::runBoolean () {

}

void VM::Language::StateStorange::Read::Singleton::runInt () {

}

void VM::Language::StateStorange::Read::Singleton::runDouble () {

}

void VM::Language::StateStorange::Read::Singleton::runString () {

}

void VM::Language::StateStorange::Read::Singleton::runStringList () {

}
