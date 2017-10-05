#include "comment.h"




void VM::Language::Control::Comment::parse (const int &command) {
	using namespace VM::Language::Control::Comment;

	int sw = command | static_cast<int>(VM::Filter::Level4);

	switch (sw) {
	case static_cast<int>(Command::Delimiter):
		Singleton::runDelimiter ();
		break;

	case static_cast<int>(Command::Line):
		Singleton::runLine ();
		break;

	case static_cast<int>(Command::MultiLine):
		Singleton::runMultiline ();
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::Language::Control::Comment::Singleton::runDelimiter () {

}

void VM::Language::Control::Comment::Singleton::runLine () {

}

void VM::Language::Control::Comment::Singleton::runMultiline () {

}
