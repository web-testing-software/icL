#include "reads.h"




void vm::language::statestorange::read::parse (const int &command) {
	using namespace vm::language::statestorange::read;

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
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::language::statestorange::read::Singleton::runBoolean () {

}

void vm::language::statestorange::read::Singleton::runInt () {

}

void vm::language::statestorange::read::Singleton::runDouble () {

}

void vm::language::statestorange::read::Singleton::runString () {

}

void vm::language::statestorange::read::Singleton::runStringList () {

}
