#include "filterelements.h"




void vm::javascript::dom::filterelements::parse (const int &command) {
	using namespace vm::javascript::dom::filterelements;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::BY_CSS_SELECTOR ) :
		Singleton::runByCSSSelector ();
		break;

	case static_cast <int> ( Command::BY_CONTENT ) :
		Singleton::runByContent ();
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::javascript::dom::filterelements::Singleton::runByCSSSelector () {

}

void vm::javascript::dom::filterelements::Singleton::runByContent () {

}
