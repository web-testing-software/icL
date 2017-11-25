#ifndef STRINGLIST_H
#define STRINGLIST_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace booloperator {
namespace stringlist {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runContains (vm::system::Driver &driver);
	static void runContainsFragment (vm::system::Driver &driver);
};

}
}
}
}

#endif // STRINGLIST_H
