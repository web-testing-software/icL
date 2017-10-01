#include "parser.h"

void VM::parse(int &command)
{

}

void VM::Language::parse (int &command) {
	using namespace VM::Language;

	switch (command) {
	case static_cast<int>(Command::Control):
		Control::parse (command);
		break;

	case static_cast<int>(Command::LocalMemory):
		LocalMemory::parse (command);
		break;

	case static_cast<int>(Command::StateStorange):
		StateStorange::parse (command);
		break;

	case static_cast<int>(Command::Constant):
		Constant::parse (command);
		break;

	case static_cast<int>(Command::BoolOperator):
		BoolOperator::parse (command);
		break;

	default:
		error = Errors::CommandNotFound;
	}
}

void VM::Language::Control::parse (int &command) {
	using namespace VM::Language::Control;
	// static_cast<int>(Command::)
}

void VM::Language::LocalMemory::parse (int &command) {
	using namespace VM::Language::LocalMemory;

}

void VM::Language::StateStorange::parse (int &command) {
	using namespace VM::Language::StateStorange;

}

void VM::Language::Constant::parse (int &command) {
	using namespace VM::Language::Constant;

}

void VM::Language::BoolOperator::parse (int &command) {
	using namespace VM::Language::BoolOperator;

}

void VM::Driver::parse (int &command) {
	using namespace VM::Driver;

}

void VM::Driver::Naigation::parse (int &command) {
	using namespace VM::Driver::Naigation;

}

void VM::Driver::ManageContent::parse (int &command) {
	using namespace VM::Driver::ManageContent;

}

void VM::JavaScript::parse (int &command) {
	using namespace VM::JavaScript;

}

void VM::JavaScript::BaseJS::parse (int &command) {
	using namespace VM::JavaScript::BaseJS;

}

void VM::JavaScript::DOM::parse (int &command) {
	using namespace VM::JavaScript::DOM;

}

void VM::Input::parse (int &command) {
	using namespace VM::Input;

}

void VM::Input::Mouse::parse (int &command) {
	using namespace VM::Input::Mouse;

}

void VM::Input::Keyboard::parse (int &command) {
	using namespace VM::Input::Keyboard;

}

void VM::DataBase::parse (int &command) {
	using namespace VM::DataBase;

}

void VM::DataBase::Basic::parse (int &command) {
	using namespace VM::DataBase::Basic;

}

void VM::Debbuger::parse (int &command) {
	using namespace VM::Debbuger;

}

void VM::Debbuger::Basic::parse (int &command) {
	using namespace VM::Debbuger::Basic;

}
