#ifndef COMPLEXEVENTK_H
#define COMPLEXEVENTK_H

#include "../../parser.h"



namespace vm {
namespace input {
namespace keyboard {
namespace complexevent {

void parse (vm::main::Driver &drive);

class Singleton {

public:
	static void runSendKey (vm::main::Driver &drive);
};

}
}
}
}

#endif // COMPLEXEVENTK_H
