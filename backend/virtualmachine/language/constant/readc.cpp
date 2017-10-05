#include "readc.h"




void vm::language::constant::read::parse (const int &command) {
	using namespace vm::language::constant::read;

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
		return;//error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::language::constant::read::Singleton::runBoolean () {

}

void vm::language::constant::read::Singleton::runInt () {

}

void vm::language::constant::read::Singleton::runDouble () {

}

void vm::language::constant::read::Singleton::runString () {

}

void vm::language::constant::read::Singleton::runStringList () {

}
