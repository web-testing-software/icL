#include "parser.h"
#include "allheaders.h"

void vm::parse (const int &command) {
	using namespace vm;

	int sw = command | static_cast <int> ( Filter::LEVEL1 );

	switch (sw) {
	case static_cast <int> ( Command::LANGUAGE ) :
		language::parse (command);
		break;

	case static_cast <int> ( Command::DRIVER ) :
		driver::parse (command);
		break;

	case static_cast <int> ( Command::JAVASCRIPT ) :
		javascript::parse (command);
		break;

	case static_cast <int> ( Command::INPUT ) :
		input::parse (command);
		break;

	case static_cast <int> ( Command::DATABASE ) :
		database::parse (command);
		break;

	case static_cast <int> ( Command::DEBUGGER ) :
		debugger::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::language::parse (const int &command) {
	using namespace vm::language;

	int sw = command | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::CONTROL ) :
		control::parse (command);
		break;

	case static_cast <int> ( Command::LOCAL_MEMORY ) :
		localmemory::parse (command);
		break;

	case static_cast <int> ( Command::STATE_STORANGE ) :
		statestorange::parse (command);
		break;

	case static_cast <int> ( Command::CONSTANT ) :
		constant::parse (command);
		break;

	case static_cast <int> ( Command::BOOL_OPERATOR ) :
		booloperator::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::language::control::parse (const int &command) {
	using namespace vm::language::control;

	int sw = command | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::SINGLE_SHOT ) :
		singleshot::parse (command);
		break;

	case static_cast <int> ( Command::COMMENT ) :
		comment::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::language::localmemory::parse (const int &command) {
	using namespace vm::language::localmemory;

	int sw = command | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::READ ) :
		read::parse (command);
		break;

	case static_cast <int> ( Command::WRITE ) :
		write::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::language::statestorange::parse (const int &command) {
	using namespace vm::language::statestorange;

	int sw = command | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::READ ) :
		read::parse (command);
		break;

	case static_cast <int> ( Command::WRITE ) :
		write::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::language::constant::parse (const int &command) {
	using namespace vm::language::constant;

	int sw = command | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::READ ) :
		read::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::language::booloperator::parse (const int &command) {
	using namespace vm::language::booloperator;

	int sw = command | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::LOGICAL ) :
		logical::parse (command);
		break;

	case static_cast <int> ( Command::EQUAL ) :
		equal::parse (command);
		break;

	case static_cast <int> ( Command::NOT_EQUAL ) :
		notequal::parse (command);
		break;

	case static_cast <int> ( Command::STRING_LIST ) :
		stringlist::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::driver::parse (const int &command) {
	using namespace vm::driver;

	int sw = command | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::NAVIGATION ) :
		navigation::parse (command);
		break;

	case static_cast <int> ( Command::MANAGE_CONTENT ) :
		managecontent::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::driver::navigation::parse (const int &command) {
	using namespace vm::driver::navigation;

	int sw = command | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::NAVIGATION ) :
		navigation::parse (command);
		break;

	case static_cast <int> ( Command::WAINTING ) :
		wainting::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::driver::managecontent::parse (const int &command) {
	using namespace vm::driver::managecontent;

	int sw = command | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::FRAMES ) :
		frames::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::javascript::parse (const int &command) {
	using namespace vm::javascript;

	int sw = command | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::BASE_JS ) :
		basejs::parse (command);
		break;

	case static_cast <int> ( Command::DOM ) :
		dom::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::javascript::basejs::parse (const int &command) {
	using namespace vm::javascript::basejs;

	int sw = command | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::RUN_JS ) :
		runjs::parse (command);
		break;

	case static_cast <int> ( Command::GET ) :
		get::parse (command);
		break;

	case static_cast <int> ( Command::SET ) :
		set::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::javascript::dom::parse (const int &command) {
	using namespace vm::javascript::dom;

	int sw = command | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::FIND_ELEMENTS ) :
		findelements::parse (command);
		break;

	case static_cast <int> ( Command::FILTER_ELEMENTS ) :
		filterelements::parse (command);
		break;

	case static_cast <int> ( Command::ELEMENTS_TEST ) :
		elementstest::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::input::parse (const int &command) {
	using namespace vm::input;

	int sw = command | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::MOUSE ) :
		mouse::parse (command);
		break;

	case static_cast <int> ( Command::KEYBOARD ) :
		keyboard::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::input::mouse::parse (const int &command) {
	using namespace vm::input::mouse;

	int sw = command | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::COMPLEX_EVENT ) :
		complexevent::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::input::keyboard::parse (const int &command) {
	using namespace vm::input::keyboard;

	int sw = command | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::COMPLEX_EVENT ) :
		complexevent::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::database::parse (const int &command) {
	using namespace vm::database;

	int sw = command | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::BASIC ) :
		basic::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::database::basic::parse (const int &command) {
	using namespace vm::database::basic;

	int sw = command | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::OUTPUT ) :
		output::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::debugger::parse (const int &command) {
	using namespace vm::debugger;

	int sw = command | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::BASIC ) :
		basic::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}

void vm::debugger::basic::parse (const int &command) {
	using namespace vm::debugger::basic;

	int sw = command | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::FOCUS ) :
		focus::parse (command);
		break;

	default :
		error = Error::COMMAND_NOT_FOUND;
	}
}
