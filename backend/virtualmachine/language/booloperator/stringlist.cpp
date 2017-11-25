#include "stringlist.h"




void vm::language::booloperator::stringlist::parse (system::Driver &driver) {
	int sw = driver.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::CONTAINS ) :
		Singleton::runContains (driver);
		break;

	case static_cast <int> ( Command::CONSTAINS_FRAGMENT ) :
		Singleton::runContainsFragment (driver);
		break;

	default :
		driver.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::booloperator::stringlist::Singleton::runContains (vm::system::Driver &driver) {

}

void vm::language::booloperator::stringlist::Singleton::runContainsFragment (vm::system::Driver &driver) {

}
