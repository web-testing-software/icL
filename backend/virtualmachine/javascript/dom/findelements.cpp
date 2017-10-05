#include "findelements.h"




void vm::javascript::dom::findelements::parse (const int &command) {
	using namespace vm::javascript::dom::findelements;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::QUERY ) :
		Singleton::runQuery ();
		break;

	case static_cast <int> ( Command::QUERY_ALL ) :
		Singleton::runQueryAll ();
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::javascript::dom::findelements::Singleton::runQuery () {

}

void vm::javascript::dom::findelements::Singleton::runQueryAll () {

}
