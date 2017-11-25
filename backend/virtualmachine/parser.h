#include "system/main/driver.h"
#include "system/main/virtualmachine.h"

#ifndef PARSER_H
#define PARSER_H

#include "allcommands.h"

#include <QDataStream>
#include <QFile>

// All functions in this file are called `parse`
// The 3rd level parse functions are placed in specials files, not here
// All parse functions are released using `switch`es
// to keep the readability and extensibility of code

namespace vm {

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

	void parse (vm::system::Driver& driver);

	namespace language {
		void parse (vm::system::Driver& driver);

		namespace control {
			void parse (vm::system::Driver& driver);
			}

		namespace localmemory {
			void parse (vm::system::Driver& driver);
			}

		namespace statestorange {
			void parse (vm::system::Driver& driver);
			}

		namespace constant {
			void parse (vm::system::Driver& driver);
			}

		namespace booloperator {
			void parse (vm::system::Driver& driver);
			}
		}

	//	namespace Browser {
	//		//
	//		}

	namespace driver {
		void parse (vm::system::Driver& driver);

		namespace navigation {
			void parse (vm::system::Driver& driver);
			}

		namespace managecontent {
			void parse (vm::system::Driver& driver);
			}
		}

	namespace javascript {
		void parse (vm::system::Driver& driver);

		namespace basejs {
			void parse (vm::system::Driver& driver);
			}

		namespace dom {
			void parse (vm::system::Driver& driver);
			}
		}

	namespace input {
		void parse (vm::system::Driver& driver);

		namespace mouse {
			void parse (vm::system::Driver& driver);
			}

		namespace keyboard {
			void parse (vm::system::Driver& driver);
			}
		}

	namespace database {
		void parse (vm::system::Driver& driver);

		namespace basic {
			void parse (vm::system::Driver& driver);
			}
		}

	namespace debugger {
		void parse (vm::system::Driver& driver);

		namespace basic {
			void parse (vm::system::Driver& driver);
			}
		}
	}

#endif // PARSER_H
