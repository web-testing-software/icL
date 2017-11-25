#ifndef FILTERELEMENTS_H
#define FILTERELEMENTS_H

#include "../../parser.h"



namespace vm {
namespace javascript {
namespace dom {
namespace filterelements {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runByCSSSelector (vm::system::Driver &driver);
	static void runByContent (vm::system::Driver &driver);
};

}
}
}
}

#endif // FILTERELEMENTS_H
