#include "logical.h"




void VM::Language::BoolOperator::Logical::parse (const int &command) {
	using namespace VM::Language::BoolOperator::Equal;

	int sw = command | static_cast<int>(VM::Filter::Level4);

	switch (sw) {
	case static_cast<int>(Command::Not):
		Singleton::runNot ();
		break;

	case static_cast<int>(Command::And):
		Singleton::runAnd ();
		break;

	case static_cast<int>(Command::Or):
		Singleton::runOr ();
		break;

	case static_cast<int>(Command::XOr):
		Singleton::runXOr ();
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::Language::BoolOperator::Logical::Singleton::runNot () {

}

void VM::Language::BoolOperator::Logical::Singleton::runAnd () {

}

void VM::Language::BoolOperator::Logical::Singleton::runOr () {

}

void VM::Language::BoolOperator::Logical::Singleton::runXOr () {

}
