#include "findelements.h"




void vm::javascript::dom::findelements::parse (system::Driver &driver) {
	int sw = driver.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::QUERY ) :
		Singleton::runQuery (driver);
		break;

	case static_cast <int> ( Command::QUERY_ALL ) :
		Singleton::runQueryAll (driver);
		break;

	default :
		driver.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::javascript::dom::findelements::Singleton::runQuery (vm::system::Driver &driver) {

}

void vm::javascript::dom::findelements::Singleton::runQueryAll (vm::system::Driver &driver) {

}
