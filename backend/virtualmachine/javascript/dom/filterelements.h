#ifndef FILTERELEMENTS_H
#define FILTERELEMENTS_H

#include "../../parser.h"



namespace vm {
namespace javascript {
namespace dom {
namespace filterelements {

void parse (vm::main::Driver &drive);

class Singleton {

public:
	static void runByCSSSelector (vm::main::Driver &drive);
	static void runByContent (vm::main::Driver &drive);
};

}
}
}
}

#endif // FILTERELEMENTS_H
