#include "writes.h"




void VM::Language::StateStorange::Write::parse (const int &command) {
	using namespace VM::Language::StateStorange::Write;

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

void VM::Language::StateStorange::Write::Singleton::runBoolean () {

}

void VM::Language::StateStorange::Write::Singleton::runInt () {

}

void VM::Language::StateStorange::Write::Singleton::runDouble () {

}

void VM::Language::StateStorange::Write::Singleton::runString () {

}

void VM::Language::StateStorange::Write::Singleton::runStringList () {

}
