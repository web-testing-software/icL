#include "elementstest.h"




void vm::javascript::dom::elementstest::parse (system::Driver &driver) {
	int sw = driver.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::IS_VISIBLE ) :
		Singleton::runIsVisible (driver);
		break;

	case static_cast <int> ( Command::GET_X ) :
		Singleton::runGetX (driver);
		break;

	case static_cast <int> ( Command::GET_Y ) :
		Singleton::runGetY (driver);
		break;

	default :
		driver.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::javascript::dom::elementstest::Singleton::runIsVisible (vm::system::Driver &driver) {

}

void vm::javascript::dom::elementstest::Singleton::runGetX (vm::system::Driver &driver) {

}

void vm::javascript::dom::elementstest::Singleton::runGetY (vm::system::Driver &driver) {

}
