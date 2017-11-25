#include "readl.h"




void vm::language::localmemory::read::parse (system::Driver &driver) {
	int sw = driver.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::BOOLEAN ) :
		Singleton::runBoolean (driver);
		break;

	case static_cast <int> ( Command::INT ) :
		Singleton::runInt (driver);
		break;

	case static_cast <int> ( Command::DOUBLE ) :
		Singleton::runDouble (driver);
		break;

	case static_cast <int> ( Command::STRING ) :
		Singleton::runString (driver);
		break;

	case static_cast <int> ( Command::STRING_LIST ) :
		Singleton::runStringList (driver);
		break;

	case static_cast <int> ( Command::WEB_ELEMENT ) :
		Singleton::runWebElement (driver);
		break;

	default :
		driver.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::localmemory::read::Singleton::runBoolean (vm::system::Driver &driver) {

}

void vm::language::localmemory::read::Singleton::runInt (vm::system::Driver &driver) {

}

void vm::language::localmemory::read::Singleton::runDouble (vm::system::Driver &driver) {

}

void vm::language::localmemory::read::Singleton::runString (vm::system::Driver &driver) {

}

void vm::language::localmemory::read::Singleton::runStringList (vm::system::Driver &driver) {

}

void vm::language::localmemory::read::Singleton::runWebElement (vm::system::Driver &driver) {

}
