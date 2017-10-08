#include "stringlist.h"




void vm::language::booloperator::stringlist::parse (const int &command) {
	using namespace vm::language::booloperator::stringlist;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::CONTAINS ) :
		Singleton::runContains ();
		break;

	case static_cast <int> ( Command::CONSTAINS_FRAGMENT ) :
		Singleton::runContainsFragment ();
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::booloperator::stringlist::Singleton::runContains () {

}

void vm::language::booloperator::stringlist::Singleton::runContainsFragment () {

}
