#ifndef FRAMES_H
#define FRAMES_H

#include "../../parser.h"



namespace vm {
namespace driver {
namespace managecontent {
namespace frames {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runSwitchToFrame (vm::system::Driver &driver);
	static void runSwitchToDefault (vm::system::Driver &driver);
};

}
}
}
}

#endif // FRAMES_H
