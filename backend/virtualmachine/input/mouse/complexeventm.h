#ifndef COMPLEXEVENTM_H
#define COMPLEXEVENTM_H

#include "../../parser.h"



namespace vm {
namespace input {
namespace mouse {
namespace complexevent {

void parse (vm::main::Driver &drive);

class Singleton {

public:
	static void runClick (vm::main::Driver &drive);
};

}
}
}
}

#endif // COMPLEXEVENTM_H
