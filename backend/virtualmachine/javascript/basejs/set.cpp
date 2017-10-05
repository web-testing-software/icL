#include "set.h"




void vm::javascript::basejs::set::parse (const int &command) {
	using namespace vm::javascript::basejs::set;

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

void vm::javascript::basejs::set::Singleton::runBoolean () {

}

void vm::javascript::basejs::set::Singleton::runInt () {

}

void vm::javascript::basejs::set::Singleton::runDouble () {

}

void vm::javascript::basejs::set::Singleton::runString () {

}

void vm::javascript::basejs::set::Singleton::runStringList () {

}
