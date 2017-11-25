#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "../../parser.h"



namespace vm {
namespace driver {
namespace navigation {
namespace navigation {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runGoToURL (vm::system::Driver &driver);
};

}
}
}
}

#endif // NAVIGATION_H
