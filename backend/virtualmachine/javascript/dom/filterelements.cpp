#include "filterelements.h"




void vm::javascript::dom::filterelements::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::BY_CSS_SELECTOR ) :
		Singleton::runByCSSSelector (drive);
		break;

	case static_cast <int> ( Command::BY_CONTENT ) :
		Singleton::runByContent (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::javascript::dom::filterelements::Singleton::runByCSSSelector (vm::main::Driver &drive) {

}

void vm::javascript::dom::filterelements::Singleton::runByContent (vm::main::Driver &drive) {

}
