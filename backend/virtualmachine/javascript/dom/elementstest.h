#ifndef ELEMENTSTEST_H
#define ELEMENTSTEST_H

#include "../../parser.h"



namespace vm {
namespace javascript {
namespace dom {
namespace elementstest {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runIsVisible (vm::system::Driver &driver);
	static void runGetX (vm::system::Driver &driver);
	static void runGetY (vm::system::Driver &driver);
};

}
}
}
}

#endif // ELEMENTSTEST_H
