#ifndef RUNJS_H
#define RUNJS_H

#include "../../parser.h"



namespace vm {
namespace javascript {
namespace basejs {
namespace runjs {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runRunString (vm::system::Driver &driver);
	static void runRunFile (vm::system::Driver &driver);
};

}
}
}
}

#endif // RUNJS_H
