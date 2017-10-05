#include "filterelements.h"




void VM::JavaScript::DOM::FilterElements::parse (const int &command) {
	using namespace VM::JavaScript::DOM::FilterElements;

	int sw = command | static_cast<int>(VM::Filter::Level4);

	switch (sw) {
	case static_cast<int>(Command::ByCSSSelector):
		Singleton::runByCSSSelector ();
		break;

	case static_cast<int>(Command::ByContent):
		Singleton::runByContent ();
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::JavaScript::DOM::FilterElements::Singleton::runByCSSSelector () {

}

void VM::JavaScript::DOM::FilterElements::Singleton::runByContent () {

}
