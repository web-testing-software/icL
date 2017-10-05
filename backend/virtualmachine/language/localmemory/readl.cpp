#include "readl.h"




void vm::language::localmemory::read::parse (const int &command) {
	using namespace vm::language::localmemory::read;

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

	case static_cast <int> ( Command::WEB_ELEMENT ) :
		Singleton::runWebElement ();
		break;

	default :
		return;//error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::language::localmemory::read::Singleton::runBoolean () {

}

void vm::language::localmemory::read::Singleton::runInt () {

}

void vm::language::localmemory::read::Singleton::runDouble () {

}

void vm::language::localmemory::read::Singleton::runString () {

}

void vm::language::localmemory::read::Singleton::runStringList () {

}

void vm::language::localmemory::read::Singleton::runWebElement () {

}
