#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "../../parser.h"



namespace vm {
namespace driver {
namespace navigation {
namespace navigation {

void parse (vm::main::Driver &drive);

class Singleton {

public:
	static void runGoToURL (vm::main::Driver &drive);
};

}
}
}
}

#endif // NAVIGATION_H
