#ifndef PARSER_H
#define PARSER_H

#include "allcommands.h"

// All functions in this file are called `parse`
// The 3rd level parse functions are placed in specials files, not here

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

	void parse (int &command);

	namespace Language {
		void parse (int &command);

		namespace Control {
			void parse (int &command);
			}

		namespace LocalMemory {
			void parse (int &command);
			}

		namespace StateStorange {
			void parse (int &command);
			}

		namespace Constant {
			void parse (int &command);
			}

		namespace BoolOperator {
			void parse (int &command);
			}
		}

//	namespace Browser {
//		//
//		}

	namespace Driver {
		void parse (int &command);

		namespace Naigation {
			void parse (int &command);
			}

		namespace ManageContent {
			void parse (int &command);
			}
		}

	namespace JavaScript {
		void parse (int &command);

		namespace BaseJS {
			void parse (int &command);
			}

		namespace DOM {
			void parse (int &command);
			}
		}

	namespace Input {
		void parse (int &command);

		namespace Mouse {
			void parse (int &command);
			}

		namespace Keyboard {
			void parse (int &command);
			}
		}

	namespace DataBase {
		void parse (int &command);

		namespace Basic {
			void parse (int &command);
			}
		}

	namespace Debbuger {
		void parse (int &command);

		namespace Basic {
			void parse (int &command);
			}
		}
}

#endif // PARSER_H
