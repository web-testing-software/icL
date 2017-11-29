#ifndef SINGLESHOT_H
#define SINGLESHOT_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace control {
namespace singleshot {

void parse (vm::main::Driver &drive);


void runIf (vm::main::Driver &drive);
void runBeginIf (vm::main::Driver &drive);
void runElse (vm::main::Driver &drive);
void runEndIf (vm::main::Driver &drive);

}
}
}
}

#endif // SINGLESHOT_H
