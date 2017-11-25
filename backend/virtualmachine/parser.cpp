#include "system/main/virtualmachine.h"
#include "allheaders.h"
#include "parser.h"

#include <backend/virtualmachine/system/main/driver.h>



void vm::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL1 );

	switch (sw) {
	case static_cast <int> ( Command::LANGUAGE ) :
		language::parse (driver);
		break;

	case static_cast <int> ( Command::DRIVER ) :
		driver::parse (driver);
		break;

	case static_cast <int> ( Command::JAVASCRIPT ) :
		javascript::parse (driver);
		break;

	case static_cast <int> ( Command::INPUT ) :
		input::parse (driver);
		break;

	case static_cast <int> ( Command::DATABASE ) :
		database::parse (driver);
		break;

	case static_cast <int> ( Command::DEBUGGER ) :
		debugger::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::CONTROL ) :
		control::parse (driver);
		break;

	case static_cast <int> ( Command::LOCAL_MEMORY ) :
		localmemory::parse (driver);
		break;

	case static_cast <int> ( Command::STATE_STORANGE ) :
		statestorange::parse (driver);
		break;

	case static_cast <int> ( Command::CONSTANT ) :
		constant::parse (driver);
		break;

	case static_cast <int> ( Command::BOOL_OPERATOR ) :
		booloperator::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::control::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::SINGLE_SHOT ) :
		singleshot::parse (driver);
		break;

	case static_cast <int> ( Command::COMMENT ) :
		comment::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::localmemory::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::READ ) :
		read::parse (driver);
		break;

	case static_cast <int> ( Command::WRITE ) :
		write::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::statestorange::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::READ ) :
		read::parse (driver);
		break;

	case static_cast <int> ( Command::WRITE ) :
		write::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::constant::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::READ ) :
		read::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::language::booloperator::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::LOGICAL ) :
		logical::parse (driver);
		break;

	case static_cast <int> ( Command::EQUAL ) :
		equal::parse (driver);
		break;

	case static_cast <int> ( Command::NOT_EQUAL ) :
		notequal::parse (driver);
		break;

	case static_cast <int> ( Command::STRING_LIST ) :
		stringlist::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::driver::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::NAVIGATION ) :
		navigation::parse (driver);
		break;

	case static_cast <int> ( Command::MANAGE_CONTENT ) :
		managecontent::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::driver::navigation::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::NAVIGATION ) :
		navigation::parse (driver);
		break;

	case static_cast <int> ( Command::WAINTING ) :
		wainting::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::driver::managecontent::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::FRAMES ) :
		frames::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::javascript::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::BASE_JS ) :
		basejs::parse (driver);
		break;

	case static_cast <int> ( Command::DOM ) :
		dom::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::javascript::basejs::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::RUN_JS ) :
		runjs::parse (driver);
		break;

	case static_cast <int> ( Command::GET ) :
		get::parse (driver);
		break;

	case static_cast <int> ( Command::SET ) :
		set::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::javascript::dom::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::FIND_ELEMENTS ) :
		findelements::parse (driver);
		break;

	case static_cast <int> ( Command::FILTER_ELEMENTS ) :
		filterelements::parse (driver);
		break;

	case static_cast <int> ( Command::ELEMENTS_TEST ) :
		elementstest::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::input::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::MOUSE ) :
		mouse::parse (driver);
		break;

	case static_cast <int> ( Command::KEYBOARD ) :
		keyboard::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::input::mouse::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::COMPLEX_EVENT ) :
		complexevent::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::input::keyboard::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::COMPLEX_EVENT ) :
		complexevent::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::database::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::BASIC ) :
		basic::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::database::basic::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::OUTPUT ) :
		output::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::debugger::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL2 );

	switch (sw) {
	case static_cast <int> ( Command::BASIC ) :
		basic::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}

void vm::debugger::basic::parse (vm::system::Driver &driver) {

	int sw = driver.currentCommand () | static_cast <int> ( Filter::LEVEL3 );

	switch (sw) {
	case static_cast <int> ( Command::SYSTEM ) :
		system::parse (driver);
		break;

	default :
		virtualMachine->setError (Error::COMMAND_NOT_FOUND);
	}
}
