#ifndef PARSER_H
#define PARSER_H

#include "allcommands.h"

// All functions in this file are called `parse`
// The 3rd level parse functions are placed in specials files, not here
// All parse functions are released using `switch`es
// to keep the readability and extensibility of code

namespace VM {

	// Stop file parsing on error

	enum class Errors {
		CommandNotFound,
		CommandExecutionError,
		InvalidArgs,
		UnexpectedEOF,
		DataConversionError,
		NoError
	};

	Errors error = Errors::NoError;

	void parse (const int &command);

	namespace Language {
		void parse (const int &command);

		namespace Control {
			void parse (const int &command);
			}

		namespace LocalMemory {
			void parse (const int &command);
			}

		namespace StateStorange {
			void parse (const int &command);
			}

		namespace Constant {
			void parse (const int &command);
			}

		namespace BoolOperator {
			void parse (const int &command);
			}
		}

	//	namespace Browser {
	//		//
	//		}

	namespace Driver {
		void parse (const int &command);

		namespace Navigation {
			void parse (const int &command);
			}

		namespace ManageContent {
			void parse (const int &command);
			}
		}

	namespace JavaScript {
		void parse (const int &command);

		namespace BaseJS {
			void parse (const int &command);
			}

		namespace DOM {
			void parse (const int &command);
			}
		}

	namespace Input {
		void parse (const int &command);

		namespace Mouse {
			void parse (const int &command);
			}

		namespace Keyboard {
			void parse (const int &command);
			}
		}

	namespace DataBase {
		void parse (const int &command);

		namespace Basic {
			void parse (const int &command);
			}
		}

	namespace Debugger {
		void parse (const int &command);

		namespace Basic {
			void parse (const int &command);
			}
		}
	}

#endif // PARSER_H
