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

	void parse (const int &command);

	namespace language {
		void parse (const int &command);

		namespace control {
			void parse (const int &command);
			}

		namespace localmemory {
			void parse (const int &command);
			}

		namespace statestorange {
			void parse (const int &command);
			}

		namespace constant {
			void parse (const int &command);
			}

		namespace booloperator {
			void parse (const int &command);
			}
		}

	//	namespace Browser {
	//		//
	//		}

	namespace driver {
		void parse (const int &command);

		namespace navigation {
			void parse (const int &command);
			}

		namespace managecontent {
			void parse (const int &command);
			}
		}

	namespace javascript {
		void parse (const int &command);

		namespace basejs {
			void parse (const int &command);
			}

		namespace dom {
			void parse (const int &command);
			}
		}

	namespace input {
		void parse (const int &command);

		namespace mouse {
			void parse (const int &command);
			}

		namespace keyboard {
			void parse (const int &command);
			}
		}

	namespace database {
		void parse (const int &command);

		namespace basic {
			void parse (const int &command);
			}
		}

	namespace debugger {
		void parse (const int &command);

		namespace basic {
			void parse (const int &command);
			}
		}
	}

#endif // PARSER_H