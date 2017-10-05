#include "stringlist.h"




void VM::Language::BoolOperator::StringList::parse (const int &command) {
	using namespace VM::Language::BoolOperator::StringList;

	int sw = command | static_cast<int>(VM::Filter::Level4);

	switch (sw) {
	case static_cast<int>(Command::Contains):
		Singleton::runContains ();
		break;

	case static_cast<int>(Command::ContainsFragment):
		Singleton::runContainsFragment ();
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::Language::BoolOperator::StringList::Singleton::runContains () {

}

void VM::Language::BoolOperator::StringList::Singleton::runContainsFragment () {

}
