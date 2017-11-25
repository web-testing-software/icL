#include "logical.h"




void vm::language::booloperator::logical::parse (system::Driver &driver) {
	int sw = driver.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::NOT ) :
		Singleton::runNot (driver);
		break;

	case static_cast <int> ( Command::AND ) :
		Singleton::runAnd (driver);
		break;

	case static_cast <int> ( Command::OR ) :
		Singleton::runOr (driver);
		break;

	case static_cast <int> ( Command::XOR ) :
		Singleton::runXOr (driver);
		break;

	default :
		driver.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::booloperator::logical::Singleton::runNot (vm::system::Driver &driver) {

}

void vm::language::booloperator::logical::Singleton::runAnd (vm::system::Driver &driver) {

}

void vm::language::booloperator::logical::Singleton::runOr (vm::system::Driver &driver) {

}

void vm::language::booloperator::logical::Singleton::runXOr (vm::system::Driver &driver) {

}
