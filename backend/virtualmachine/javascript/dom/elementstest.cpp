#include "elementstest.h"




void vm::javascript::dom::elementstest::parse (const int &command) {
	using namespace vm::javascript::dom::elementstest;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::IS_VISIBLE ) :
		Singleton::runIsVisible ();
		break;

	case static_cast <int> ( Command::GET_X ) :
		Singleton::runGetX ();
		break;

	case static_cast <int> ( Command::GET_Y ) :
		Singleton::runGetY ();
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::javascript::dom::elementstest::Singleton::runIsVisible () {

}

void vm::javascript::dom::elementstest::Singleton::runGetX () {

}

void vm::javascript::dom::elementstest::Singleton::runGetY () {

}
