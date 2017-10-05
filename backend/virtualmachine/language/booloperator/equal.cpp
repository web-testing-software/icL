#include "equal.h"




void VM::Language::BoolOperator::Equal::parse (const int &command) {
	using namespace VM::Language::BoolOperator::Equal;

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

void VM::Language::BoolOperator::Equal::Singleton::runBoolean () {

}

void VM::Language::BoolOperator::Equal::Singleton::runInt () {

}

void VM::Language::BoolOperator::Equal::Singleton::runDouble () {

}

void VM::Language::BoolOperator::Equal::Singleton::runString () {

}

void VM::Language::BoolOperator::Equal::Singleton::runStringList () {

}
