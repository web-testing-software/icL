#include "elementstest.h"




void VM::JavaScript::DOM::ElementsTest::parse (const int &command) {
	using namespace VM::JavaScript::DOM::ElementsTest;

	int sw = command | static_cast<int>(VM::Filter::Level4);

	switch (sw) {
	case static_cast<int>(Command::IsVisible):
		Singleton::runIsVisible ();
		break;

	case static_cast<int>(Command::GetX):
		Singleton::runGetX ();
		break;

	case static_cast<int>(Command::GetY):
		Singleton::runGetY ();
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::JavaScript::DOM::ElementsTest::Singleton::runIsVisible () {

}

void VM::JavaScript::DOM::ElementsTest::Singleton::runGetX () {

}

void VM::JavaScript::DOM::ElementsTest::Singleton::runGetY () {

}
