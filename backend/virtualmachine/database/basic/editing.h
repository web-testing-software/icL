#ifndef EDITING_H
#define EDITING_H

#include "../../parser.h"



namespace vm {
namespace database {
namespace basic {
namespace editing {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runInsert (vm::system::Driver &driver);
};

}
}
}
}

#endif // EDITING_H
