#include "writes.h"




void vm::language::statestorange::write::parse (const int &command) {
	using namespace vm::language::statestorange::write;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::BOOLEAN ) :
		Singleton::runBoolean ();
		break;

	case static_cast <int> ( Command::INT ) :
		Singleton::runInt ();
		break;

	case static_cast <int> ( Command::DOUBLE ) :
		Singleton::runDouble ();
		break;

	case static_cast <int> ( Command::STRING ) :
		Singleton::runString ();
		break;

	case static_cast <int> ( Command::STRING_LIST ) :
		Singleton::runStringList ();
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::statestorange::write::Singleton::runBoolean () {

}

void vm::language::statestorange::write::Singleton::runInt () {

}

void vm::language::statestorange::write::Singleton::runDouble () {

}

void vm::language::statestorange::write::Singleton::runString () {

}

void vm::language::statestorange::write::Singleton::runStringList () {

}
