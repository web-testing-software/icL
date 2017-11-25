#ifndef SINGLESHOT_H
#define SINGLESHOT_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace control {
namespace singleshot {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runIf (vm::system::Driver &driver);
	static void runBeginIf (vm::system::Driver &driver);
	static void runElse (vm::system::Driver &driver);
	static void runEndIf (vm::system::Driver &driver);
};

}
}
}
}

#endif // SINGLESHOT_H
