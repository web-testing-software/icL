#include "parser.h"
#include "allheaders.h"

void VM::parse (const int &command) {
	using namespace VM;

	int sw = command | static_cast <int> ( Filter::Level1 );

	switch (sw) {
	case static_cast <int> ( Command::Language ) :
		Language::parse (command);
		break;

	case static_cast <int> ( Command::Driver ) :
		Driver::parse (command);
		break;

	case static_cast <int> ( Command::JavaScript ) :
		JavaScript::parse (command);
		break;

	case static_cast <int> ( Command::Input ) :
		Input::parse (command);
		break;

	case static_cast <int> ( Command::DataBase ) :
		DataBase::parse (command);
		break;

	case static_cast <int> ( Command::Debugger ) :
		Debugger::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::Language::parse (const int &command) {
	using namespace VM::Language;

	int sw = command | static_cast <int> ( Filter::Level2 );

	switch (sw) {
	case static_cast <int> ( Command::Control ) :
		Control::parse (command);
		break;

	case static_cast <int> ( Command::LocalMemory ) :
		LocalMemory::parse (command);
		break;

	case static_cast <int> ( Command::StateStorange ) :
		StateStorange::parse (command);
		break;

	case static_cast <int> ( Command::Constant ) :
		Constant::parse (command);
		break;

	case static_cast <int> ( Command::BoolOperator ) :
		BoolOperator::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::Language::Control::parse (const int &command) {
	using namespace VM::Language::Control;

	int sw = command | static_cast <int> ( Filter::Level3 );

	switch (sw) {
	case static_cast <int> ( Command::SingleShot ) :
		SingleShot::parse (command);
		break;

	case static_cast <int> ( Command::Comment ) :
		Comment::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::Language::LocalMemory::parse (const int &command) {
	using namespace VM::Language::LocalMemory;

	int sw = command | static_cast <int> ( Filter::Level3 );

	switch (sw) {
	case static_cast <int> ( Command::Read ) :
		Read::parse (command);
		break;

	case static_cast <int> ( Command::Write ) :
		Write::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::Language::StateStorange::parse (const int &command) {
	using namespace VM::Language::StateStorange;

	int sw = command | static_cast <int> ( Filter::Level3 );

	switch (sw) {
	case static_cast <int> ( Command::Read ) :
		Read::parse (command);
		break;

	case static_cast <int> ( Command::Write ) :
		Write::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::Language::Constant::parse (const int &command) {
	using namespace VM::Language::Constant;

	int sw = command | static_cast <int> ( Filter::Level3 );

	switch (sw) {
	case static_cast <int> ( Command::Read ) :
		Read::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::Language::BoolOperator::parse (const int &command) {
	using namespace VM::Language::BoolOperator;

	int sw = command | static_cast <int> ( Filter::Level3 );

	switch (sw) {
	case static_cast <int> ( Command::Logical ) :
		Logical::parse (command);
		break;

	case static_cast <int> ( Command::Equal ) :
		Equal::parse (command);
		break;

	case static_cast <int> ( Command::NotEqual ) :
		NotEqual::parse (command);
		break;

	case static_cast <int> ( Command::StringList ) :
		StringList::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::Driver::parse (const int &command) {
	using namespace VM::Driver;

	int sw = command | static_cast <int> ( Filter::Level2 );

	switch (sw) {
	case static_cast <int> ( Command::Navigation ) :
		Navigation::parse (command);
		break;

	case static_cast <int> ( Command::ManageContent ) :
		ManageContent::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::Driver::Navigation::parse (const int &command) {
	using namespace VM::Driver::Navigation;

	int sw = command | static_cast <int> ( Filter::Level3 );

	switch (sw) {
	case static_cast <int> ( Command::Navigation ) :
		Navigation::parse (command);
		break;

	case static_cast <int> ( Command::Wainting ) :
		Wainting::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::Driver::ManageContent::parse (const int &command) {
	using namespace VM::Driver::ManageContent;

	int sw = command | static_cast <int> ( Filter::Level3 );

	switch (sw) {
	case static_cast <int> ( Command::Frames ) :
		Frames::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::JavaScript::parse (const int &command) {
	using namespace VM::JavaScript;

	int sw = command | static_cast <int> ( Filter::Level2 );

	switch (sw) {
	case static_cast <int> ( Command::BaseJS ) :
		BaseJS::parse (command);
		break;

	case static_cast <int> ( Command::DOM ) :
		DOM::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::JavaScript::BaseJS::parse (const int &command) {
	using namespace VM::JavaScript::BaseJS;

	int sw = command | static_cast <int> ( Filter::Level3 );

	switch (sw) {
	case static_cast <int> ( Command::RunJS ) :
		RunJS::parse (command);
		break;

	case static_cast <int> ( Command::Get ) :
		Get::parse (command);
		break;

	case static_cast <int> ( Command::Set ) :
		Set::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::JavaScript::DOM::parse (const int &command) {
	using namespace VM::JavaScript::DOM;

	int sw = command | static_cast <int> ( Filter::Level3 );

	switch (sw) {
	case static_cast <int> ( Command::FindElements ) :
		FindElements::parse (command);
		break;

	case static_cast <int> ( Command::FilterElements ) :
		FilterElements::parse (command);
		break;

	case static_cast <int> ( Command::ElementsTest ) :
		ElementsTest::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::Input::parse (const int &command) {
	using namespace VM::Input;

	int sw = command | static_cast <int> ( Filter::Level2 );

	switch (sw) {
	case static_cast <int> ( Command::Mouse ) :
		Mouse::parse (command);
		break;

	case static_cast <int> ( Command::Keyboard ) :
		Keyboard::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::Input::Mouse::parse (const int &command) {
	using namespace VM::Input::Mouse;

	int sw = command | static_cast <int> ( Filter::Level3 );

	switch (sw) {
	case static_cast <int> ( Command::ComplexEvent ) :
		ComplexEvent::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::Input::Keyboard::parse (const int &command) {
	using namespace VM::Input::Keyboard;

	int sw = command | static_cast <int> ( Filter::Level3 );

	switch (sw) {
	case static_cast <int> ( Command::ComplexEvent ) :
		ComplexEvent::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::DataBase::parse (const int &command) {
	using namespace VM::DataBase;

	int sw = command | static_cast <int> ( Filter::Level2 );

	switch (sw) {
	case static_cast <int> ( Command::Basic ) :
		Basic::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::DataBase::Basic::parse (const int &command) {
	using namespace VM::DataBase::Basic;

	int sw = command | static_cast <int> ( Filter::Level3 );

	switch (sw) {
	case static_cast <int> ( Command::Output ) :
		Output::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::Debugger::parse (const int &command) {
	using namespace VM::Debugger;

	int sw = command | static_cast <int> ( Filter::Level2 );

	switch (sw) {
	case static_cast <int> ( Command::Basic ) :
		Basic::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}

void VM::Debugger::Basic::parse (const int &command) {
	using namespace VM::Debugger::Basic;

	int sw = command | static_cast <int> ( Filter::Level3 );

	switch (sw) {
	case static_cast <int> ( Command::Focus ) :
		Focus::parse (command);
		break;

	default :
		error = Errors::CommandNotFound;
	}
}
