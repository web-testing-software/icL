#include "singleshot.h"



void vm::language::control::singleshot::parse (system::Driver &driver) {
	int sw = driver.currentCommand () | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::IF ) :
		Singleton::runIf (driver);
		break;

	case static_cast <int> ( Command::BEGIN_IF ) :
		Singleton::runBeginIf (driver);
		break;

	case static_cast <int> ( Command::ELSE ) :
		Singleton::runElse (driver);
		break;

	case static_cast <int> ( Command::END_IF ) :
		Singleton::runEndIf (driver);
		break;

	default :
		driver.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::control::singleshot::Singleton::runIf (vm::system::Driver &driver) {
	stackStateIterator->openNewStack (system::StackState::StackType::IF_STACK);
}

void vm::language::control::singleshot::Singleton::runBeginIf (vm::system::Driver &driver) {
//	system::CommandsToSearch commads = virtualMachine->
	
//	if ()
}

void vm::language::control::singleshot::Singleton::runElse (vm::system::Driver &driver) {

}

void vm::language::control::singleshot::Singleton::runEndIf (vm::system::Driver &driver) {

}
