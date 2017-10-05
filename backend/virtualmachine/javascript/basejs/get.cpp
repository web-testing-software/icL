#include "get.h"




void vm::javascript::basejs::get::parse (const int &command) {
	using namespace vm::javascript::basejs::get;

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

void vm::javascript::basejs::get::Singleton::runBoolean () {

}

void vm::javascript::basejs::get::Singleton::runInt () {

}

void vm::javascript::basejs::get::Singleton::runDouble () {

}

void vm::javascript::basejs::get::Singleton::runString () {

}

void vm::javascript::basejs::get::Singleton::runStringList () {

}
