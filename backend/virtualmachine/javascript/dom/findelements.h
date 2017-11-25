#ifndef FINDELEMENTS_H
#define FINDELEMENTS_H

#include "../../parser.h"



namespace vm {
namespace javascript {
namespace dom {
namespace findelements {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runQuery (vm::system::Driver &driver);
	static void runQueryAll (vm::system::Driver &driver);
};

}
}
}
}

#endif // FINDELEMENTS_H
