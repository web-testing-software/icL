//#include "system/main/virtualmachine.h"
#include "allheaders.h"
#include "parser.h"



void vm::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL1 );

	switch (sw) {
	case static_cast <int> ( Command::LANGUAGE ) :
		language::parse (drive);
		break;

	case static_cast <int> ( Command::DRIVER ) :
		driver::parse (drive);
		break;

	case static_cast <int> ( Command::JAVASCRIPT ) :
		javascript::parse (drive);
		break;

	case static_cast <int> ( Command::INPUT ) :
		input::parse (drive);
		break;

	case static_cast <int> ( Command::DATABASE ) :
		database::parse (drive);
		break;

	case static_cast <int> ( Command::DEBUGGER ) :
		debugger::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::CONTROL ) :
		control::parse (drive);
		break;

	case static_cast <int> ( Command::LOCAL_MEMORY ) :
		localmemory::parse (drive);
		break;

	case static_cast <int> ( Command::STATE_STORANGE ) :
		statestorange::parse (drive);
		break;

	case static_cast <int> ( Command::CONSTANT ) :
		constant::parse (drive);
		break;

	case static_cast <int> ( Command::BOOL_OPERATOR ) :
		booloperator::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::control::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::SINGLE_SHOT ) :
		singleshot::parse (drive);
		break;

	case static_cast <int> ( Command::COMMENT ) :
		comment::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::localmemory::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::READ ) :
		read::parse (drive);
		break;

	case static_cast <int> ( Command::WRITE ) :
		write::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::statestorange::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::READ ) :
		read::parse (drive);
		break;

	case static_cast <int> ( Command::WRITE ) :
		write::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::constant::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::READ ) :
		read::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::booloperator::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::LOGICAL ) :
		logical::parse (drive);
		break;

	case static_cast <int> ( Command::EQUAL ) :
		equal::parse (drive);
		break;

	case static_cast <int> ( Command::NOT_EQUAL ) :
		notequal::parse (drive);
		break;

	case static_cast <int> ( Command::STRING_LIST ) :
		stringlist::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::driver::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::NAVIGATION ) :
		navigation::parse (drive);
		break;

	case static_cast <int> ( Command::MANAGE_CONTENT ) :
		managecontent::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::driver::navigation::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::NAVIGATION ) :
		navigation::parse (drive);
		break;

	case static_cast <int> ( Command::WAINTING ) :
		wainting::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::driver::managecontent::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::FRAMES ) :
		frames::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::javascript::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::BASE_JS ) :
		basejs::parse (drive);
		break;

	case static_cast <int> ( Command::DOM ) :
		dom::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::javascript::basejs::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::RUN_JS ) :
		runjs::parse (drive);
		break;

	case static_cast <int> ( Command::GET ) :
		get::parse (drive);
		break;

	case static_cast <int> ( Command::SET ) :
		set::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::javascript::dom::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::FIND_ELEMENTS ) :
		findelements::parse (drive);
		break;

	case static_cast <int> ( Command::FILTER_ELEMENTS ) :
		filterelements::parse (drive);
		break;

	case static_cast <int> ( Command::ELEMENTS_TEST ) :
		elementstest::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::input::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::MOUSE ) :
		mouse::parse (drive);
		break;

	case static_cast <int> ( Command::KEYBOARD ) :
		keyboard::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::input::mouse::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::COMPLEX_EVENT ) :
		complexevent::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::input::keyboard::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::COMPLEX_EVENT ) :
		complexevent::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::database::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::BASIC ) :
		basic::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::database::basic::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::OUTPUT ) :
		output::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::debugger::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::BASIC ) :
		basic::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::debugger::basic::parse (vm::main::Driver &drive) {

	int sw = drive.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::TESTING ) :
		testing::parse (drive);
		break;

	default :
		drive.setError (Error::COMMAND_NOT_FOUND);
	}
}
