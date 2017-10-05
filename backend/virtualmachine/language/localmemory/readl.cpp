#include "readl.h"




void VM::Language::LocalMemory::Read::parse (const int &command) {
	using namespace VM::Language::LocalMemory::Read;

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

	case static_cast<int>(Command::WebElement):
		Singleton::runWebElement ();
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::Language::LocalMemory::Read::Singleton::runBoolean () {

}

void VM::Language::LocalMemory::Read::Singleton::runInt () {

}

void VM::Language::LocalMemory::Read::Singleton::runDouble () {

}

void VM::Language::LocalMemory::Read::Singleton::runString () {

}

void VM::Language::LocalMemory::Read::Singleton::runStringList () {

}

void VM::Language::LocalMemory::Read::Singleton::runWebElement () {

}
