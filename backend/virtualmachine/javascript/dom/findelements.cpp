#include "findelements.h"




void vm::javascript::dom::findelements::parse (main::Driver &drive) {
	int sw = drive.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::QUERY ) :
		Singleton::runQuery (drive);
		break;

	case static_cast <int> ( Command::QUERY_ALL ) :
		Singleton::runQueryAll (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::javascript::dom::findelements::Singleton::runQuery (vm::main::Driver &drive) {

}

void vm::javascript::dom::findelements::Singleton::runQueryAll (vm::main::Driver &drive) {

}
