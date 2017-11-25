#ifndef OUTPUT_H
#define OUTPUT_H

#include "../../parser.h"



namespace vm {
namespace database {
namespace basic {
namespace output {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runSelect (vm::system::Driver &driver);
};

}
}
}
}

#endif // OUTPUT_H
