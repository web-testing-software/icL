#ifndef READL_H
#define READL_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace localmemory {
namespace read {

void parse (vm::main::Driver &drive);

class Singleton {

public:
	static void runBoolean (vm::main::Driver &drive);
	static void runInt (vm::main::Driver &drive);
	static void runDouble (vm::main::Driver &drive);
	static void runString (vm::main::Driver &drive);
	static void runStringList (vm::main::Driver &drive);
	static void runWebElement (vm::main::Driver &drive);
};

}
}
}
}

#endif // READL_H
