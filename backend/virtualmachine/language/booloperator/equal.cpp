#include "equal.h"




void vm::language::booloperator::equal::parse (const int &command) {
	using namespace vm::language::booloperator::equal;

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

void vm::language::booloperator::equal::Singleton::runBoolean () {

}

void vm::language::booloperator::equal::Singleton::runInt () {

}

void vm::language::booloperator::equal::Singleton::runDouble () {

}

void vm::language::booloperator::equal::Singleton::runString () {

}

void vm::language::booloperator::equal::Singleton::runStringList () {

}
