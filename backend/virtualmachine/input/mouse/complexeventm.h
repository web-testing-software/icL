#ifndef COMPLEXEVENTM_H
#define COMPLEXEVENTM_H

#include "../../parser.h"



namespace vm {
namespace input {
namespace mouse {
namespace complexevent {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runClick (vm::system::Driver &driver);
};

}
}
}
}

#endif // COMPLEXEVENTM_H
