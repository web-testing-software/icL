#include "filterelements.h"




void vm::javascript::dom::filterelements::parse (system::Driver &driver) {
	int sw = driver.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::BY_CSS_SELECTOR ) :
		Singleton::runByCSSSelector (driver);
		break;

	case static_cast <int> ( Command::BY_CONTENT ) :
		Singleton::runByContent (driver);
		break;

	default :
		driver.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::javascript::dom::filterelements::Singleton::runByCSSSelector (vm::system::Driver &driver) {

}

void vm::javascript::dom::filterelements::Singleton::runByContent (vm::system::Driver &driver) {

}
