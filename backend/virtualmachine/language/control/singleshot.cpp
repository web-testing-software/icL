#include "singleshot.h"




void vm::language::control::singleshot::parse (const int &command) {
	using namespace vm::language::control::singleshot;

	int sw = command | static_cast <int> ( vm::Filter::LEVEL4 );

	switch (sw) {
	case static_cast <int> ( Command::IF ) :
		Singleton::runIf ();
		break;

	case static_cast <int> ( Command::BEGIN_IF ) :
		Singleton::runBeginIf ();
		break;

	case static_cast <int> ( Command::ELSE ) :
		Singleton::runElse ();
		break;

	case static_cast <int> ( Command::END_IF ) :
		Singleton::runEndIf ();
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::language::control::singleshot::Singleton::runIf () {

}

void vm::language::control::singleshot::Singleton::runBeginIf () {

}

void vm::language::control::singleshot::Singleton::runElse () {

}

void vm::language::control::singleshot::Singleton::runEndIf () {

}
