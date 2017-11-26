#ifndef LOGICAL_H
#define LOGICAL_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace booloperator {
namespace logical {

void parse (vm::main::Driver &drive);

class Singleton {

public:
	static void runNot (vm::main::Driver &drive);
	static void runAnd (vm::main::Driver &drive);
	static void runOr (vm::main::Driver &drive);
	static void runXOr (vm::main::Driver &drive);
};

}
}
}
}

#endif // LOGICAL_H
