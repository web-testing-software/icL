#ifndef LOGICAL_H
#define LOGICAL_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace booloperator {
namespace logical {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runNot (vm::system::Driver &driver);
	static void runAnd (vm::system::Driver &driver);
	static void runOr (vm::system::Driver &driver);
	static void runXOr (vm::system::Driver &driver);
};

}
}
}
}

#endif // LOGICAL_H
