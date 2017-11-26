#ifndef EQUAL_H
#define EQUAL_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace booloperator {
namespace equal {

void parse (vm::main::Driver &drive);

class Singleton {

public:
	static void runBoolean (vm::main::Driver &drive);
	static void runInt (vm::main::Driver &drive);
	static void runDouble (vm::main::Driver &drive);
	static void runString (vm::main::Driver &drive);
	static void runStringList (vm::main::Driver &drive);
};

}
}
}
}

#endif // EQUAL_H
