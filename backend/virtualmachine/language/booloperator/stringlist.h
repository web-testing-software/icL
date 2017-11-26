#ifndef STRINGLIST_H
#define STRINGLIST_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace booloperator {
namespace stringlist {

void parse (vm::main::Driver &drive);

class Singleton {

public:
	static void runContains (vm::main::Driver &drive);
	static void runContainsFragment (vm::main::Driver &drive);
};

}
}
}
}

#endif // STRINGLIST_H
