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

	enum class LoopMode {
		NO_STATE,
		ONCE,
		LOOP_CURRENT,
		LOOP_TO_END
	};

	void parse (main::Driver& drive);

	namespace language {
		void parse (main::Driver&);

		namespace control {
			void parse (main::Driver&);
			}

		namespace localmemory {
			void parse (main::Driver&);
			}

		namespace statestorange {
			void parse (main::Driver&);
			}

		namespace constant {
			void parse (main::Driver&);
			}
		}

	//	namespace Browser {
	//		//
	//		}

	namespace driver {
		void parse (main::Driver&);

		namespace navigation {
			void parse (main::Driver&);
			}

		namespace managecontent {
			void parse (main::Driver&);
			}
		}

	namespace javascript {
		void parse (main::Driver&);

		namespace basejs {
			void parse (main::Driver&);
			}

		namespace dom {
			void parse (main::Driver&);
			}
		}

	namespace input {
		void parse (main::Driver&);

		namespace mouse {
			void parse (main::Driver&);
			}

		namespace keyboard {
			void parse (main::Driver&);
			}
		}

	namespace database {
		void parse (main::Driver&);

		namespace basic {
			void parse (main::Driver&);
			}
		}

	namespace debugger {
		void parse (main::Driver&);

		namespace basic {
			void parse (main::Driver&);
			}
		}
	}

#endif // PARSER_H
