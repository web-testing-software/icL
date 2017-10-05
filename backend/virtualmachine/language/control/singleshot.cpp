#include "singleshot.h"




void VM::Language::Control::SingleShot::parse (const int &command) {
	using namespace VM::Language::Control::SingleShot;

	int sw = command | static_cast<int>(VM::Filter::Level4);

	switch (sw) {
	case static_cast<int>(Command::If):
		Singleton::runIf ();
		break;

	case static_cast<int>(Command::BeginIf):
		Singleton::runBeginIf ();
		break;

	case static_cast<int>(Command::Else):
		Singleton::runElse ();
		break;

	case static_cast<int>(Command::EndIf):
		Singleton::runEndIf ();
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::Language::Control::SingleShot::Singleton::runIf () {

}

void VM::Language::Control::SingleShot::Singleton::runBeginIf () {

}

void VM::Language::Control::SingleShot::Singleton::runElse () {

}

void VM::Language::Control::SingleShot::Singleton::runEndIf () {

}
