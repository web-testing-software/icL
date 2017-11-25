#ifndef WRITEL_H
#define WRITEL_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace localmemory {
namespace write {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runBoolean (vm::system::Driver &driver);
	static void runInt (vm::system::Driver &driver);
	static void runDouble (vm::system::Driver &driver);
	static void runString (vm::system::Driver &driver);
	static void runStringList (vm::system::Driver &driver);
	static void runWebElement (vm::system::Driver &driver);
};

}
}
}
}


#endif // WRITEL_H
