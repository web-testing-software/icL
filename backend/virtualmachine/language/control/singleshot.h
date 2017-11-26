#ifndef SINGLESHOT_H
#define SINGLESHOT_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace control {
namespace singleshot {

void parse (vm::main::Driver &drive);

class Singleton {

public:
	static void runIf (vm::main::Driver &drive);
	static void runBeginIf (vm::main::Driver &drive);
	static void runElse (vm::main::Driver &drive);
	static void runEndIf (vm::main::Driver &drive);
};

}
}
}
}

#endif // SINGLESHOT_H
