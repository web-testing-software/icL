#include "findelements.h"




void VM::JavaScript::DOM::FindElements::parse (const int &command) {
	using namespace VM::JavaScript::DOM::FindElements;

	int sw = command | static_cast<int>(VM::Filter::Level4);

	switch (sw) {
	case static_cast<int>(Command::Query):
		Singleton::runQuery ();
		break;

	case static_cast<int>(Command::QueryAll):
		Singleton::runQueryAll ();
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::JavaScript::DOM::FindElements::Singleton::runQuery () {

}

void VM::JavaScript::DOM::FindElements::Singleton::runQueryAll () {

}
