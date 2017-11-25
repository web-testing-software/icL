#ifndef SYSTEM_H
#define SYSTEM_H

#include "../../parser.h"



namespace vm {
namespace debugger {
namespace basic {
namespace system {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runReport (vm::system::Driver &driver);
};

}
}
}
}

#endif // SYSTEM_H
