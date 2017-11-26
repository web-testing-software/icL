#ifndef RUNJS_H
#define RUNJS_H

#include "../../parser.h"



namespace vm {
namespace javascript {
namespace basejs {
namespace runjs {

void parse (vm::main::Driver &drive);

class Singleton {

public:
	static void runRunString (vm::main::Driver &drive);
	static void runRunFile (vm::main::Driver &drive);
};

}
}
}
}

#endif // RUNJS_H
