#include "logical.h"




void vm::language::booloperator::logical::parse (const int &command) {
	using namespace vm::language::booloperator::equal;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::NOT ) :
		Singleton::runNot ();
		break;

	case static_cast <int> ( Command::AND ) :
		Singleton::runAnd ();
		break;

	case static_cast <int> ( Command::OR ) :
		Singleton::runOr ();
		break;

	case static_cast <int> ( Command::XOR ) :
		Singleton::runXOr ();
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::booloperator::logical::Singleton::runNot () {

}

void vm::language::booloperator::logical::Singleton::runAnd () {

}

void vm::language::booloperator::logical::Singleton::runOr () {

}

void vm::language::booloperator::logical::Singleton::runXOr () {

}
