#ifndef ELEMENTSTEST_H
#define ELEMENTSTEST_H

#include "../../parser.h"



namespace vm {
namespace javascript {
namespace dom {
namespace elementstest {

void parse (vm::main::Driver &drive);

class Singleton {

public:
	static void runIsVisible (vm::main::Driver &drive);
	static void runGetX (vm::main::Driver &drive);
	static void runGetY (vm::main::Driver &drive);
};

}
}
}
}

#endif // ELEMENTSTEST_H
