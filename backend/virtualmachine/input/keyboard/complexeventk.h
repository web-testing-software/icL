#ifndef COMPLEXEVENTK_H
#define COMPLEXEVENTK_H

#include "../../parser.h"



namespace vm {
namespace input {
namespace keyboard {
namespace complexevent {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runSendKey (vm::system::Driver &driver);
};

}
}
}
}

#endif // COMPLEXEVENTK_H
