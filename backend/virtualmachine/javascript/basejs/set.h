#ifndef SET_H
#define SET_H

#include "../../parser.h"



namespace vm {
namespace javascript {
namespace basejs {
namespace set {

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

#endif // SET_H
