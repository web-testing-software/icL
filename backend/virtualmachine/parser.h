#ifndef PARSER_H
#define PARSER_H

#include "allcommands.h"
#include "system/main/driver.h"

#include <QDataStream>
#include <QFile>

// All functions in this file are called `parse`
// The 3rd level parse functions are placed in specials files, not here
// All parse functions are released using `switch`es
// to keep the readability and extensibility of code


namespace vm {

	namespace main {
		class Driver;
	}

	enum class Error {
		COMMAND_NOT_FOUND,
		COMMAND_EXECUTION_ERROR,
		INVALID_ARGUMENTS,
		UNEXPECTED_EOF,
		DATA_CONVERSION_ERROR,
		WRONG_STACK_STATE,
		SERVER_ERROR,
		FILE_NOT_OPENED,
		WRONG_FILE_FORMAT,
		NO_VM_ERROR
	};

	enum class LoopMode {
		NO_STATE,
		ONCE,
		LOOP_CURRENT,
		LOOP_TO_END
	};

	void parse (vm::main::Driver& drive);

	namespace language {
		void parse (vm::main::Driver&);

		namespace control {
			void parse (vm::main::Driver&);
			}

		namespace localmemory {
			void parse (vm::main::Driver&);
			}

		namespace statestorange {
			void parse (vm::main::Driver&);
			}

		namespace constant {
			void parse (vm::main::Driver&);
			}

		namespace booloperator {
			void parse (vm::main::Driver&);
			}
		}

	//	namespace Browser {
	//		//
	//		}

	namespace driver {
		void parse (vm::main::Driver&);

		namespace navigation {
			void parse (vm::main::Driver&);
			}

		namespace managecontent {
			void parse (vm::main::Driver&);
			}
		}

	namespace javascript {
		void parse (vm::main::Driver&);

		namespace basejs {
			void parse (vm::main::Driver&);
			}

		namespace dom {
			void parse (vm::main::Driver&);
			}
		}

	namespace input {
		void parse (vm::main::Driver&);

		namespace mouse {
			void parse (vm::main::Driver&);
			}

		namespace keyboard {
			void parse (vm::main::Driver&);
			}
		}

	namespace database {
		void parse (vm::main::Driver&);

		namespace basic {
			void parse (vm::main::Driver&);
			}
		}

	namespace debugger {
		void parse (vm::main::Driver&);

		namespace basic {
			void parse (vm::main::Driver&);
			}
		}
	}

#endif // PARSER_H
