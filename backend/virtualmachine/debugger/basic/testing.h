#ifndef SYSTEM_H
#define SYSTEM_H

#include "../../parser.h"



namespace vm {
namespace debugger {
namespace basic {
namespace testing {

void parse (vm::main::Driver &drive);

class Singleton {

public:
	static void runReport (vm::main::Driver &drive);
};

}
}
}
}

#endif // SYSTEM_H
