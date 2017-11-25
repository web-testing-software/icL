#ifndef WAINTING_H
#define WAINTING_H

#include "../../parser.h"



namespace vm {
namespace driver {
namespace navigation {
namespace wainting {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runPrepareWaitForPageLoad (vm::system::Driver &driver);
	static void runWaitForPageLoad (vm::system::Driver &driver);
};

}
}
}
}

#endif // WAINTING_H
