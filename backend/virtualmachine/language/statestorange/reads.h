#ifndef READS_H
#define READS_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace statestorange {
namespace read {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runBoolean (vm::system::Driver &driver);
	static void runInt (vm::system::Driver &driver);
	static void runDouble (vm::system::Driver &driver);
	static void runString (vm::system::Driver &driver);
	static void runStringList (vm::system::Driver &driver);
};

}
}
}
}

#endif // READS_H
