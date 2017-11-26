#ifndef OUTPUT_H
#define OUTPUT_H

#include "../../parser.h"



namespace vm {
namespace database {
namespace basic {
namespace output {

void parse (vm::main::Driver &drive);

class Singleton {

public:
	static void runSelect (vm::main::Driver &drive);
};

}
}
}
}

#endif // OUTPUT_H
