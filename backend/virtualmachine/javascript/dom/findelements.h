#ifndef FINDELEMENTS_H
#define FINDELEMENTS_H

#include "../../parser.h"



namespace vm {
namespace javascript {
namespace dom {
namespace findelements {

void parse (vm::main::Driver &drive);

class Singleton {

public:
	static void runQuery (vm::main::Driver &drive);
	static void runQueryAll (vm::main::Driver &drive);
};

}
}
}
}

#endif // FINDELEMENTS_H
