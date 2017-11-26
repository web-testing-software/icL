#ifndef WAINTING_H
#define WAINTING_H

#include "../../parser.h"



namespace vm {
namespace driver {
namespace navigation {
namespace wainting {

void parse (vm::main::Driver &drive);

class Singleton {

public:
	static void runPrepareWaitForPageLoad (vm::main::Driver &drive);
	static void runWaitForPageLoad (vm::main::Driver &drive);
};

}
}
}
}

#endif // WAINTING_H
