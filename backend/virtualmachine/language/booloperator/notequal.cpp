#include "notequal.h"




void vm::language::booloperator::notequal::parse (const int &command) {
	using namespace vm::language::booloperator::notequal;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::BOOLEAN ) :
		Singleton::runBoolean ();
		break;

	case static_cast <int> ( Command::INT ) :
		Singleton::runInt ();
		break;

	case static_cast <int> ( Command::DOUBLE ) :
		Singleton::runDouble ();
		break;

	case static_cast <int> ( Command::STRING ) :
		Singleton::runString ();
		break;

	case static_cast <int> ( Command::STRING_LIST ) :
		Singleton::runStringList ();
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::booloperator::notequal::Singleton::runBoolean () {

}

void vm::language::booloperator::notequal::Singleton::runInt () {

}

void vm::language::booloperator::notequal::Singleton::runDouble () {

}

void vm::language::booloperator::notequal::Singleton::runString () {

}

void vm::language::booloperator::notequal::Singleton::runStringList () {

}
