#ifndef LOGICAL_H
#define LOGICAL_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace booloperator {
namespace logical {

void parse (vm::main::Driver &drive);

void runNot (vm::main::Driver &drive);
void runAnd (vm::main::Driver &drive);
void runOr (vm::main::Driver &drive);
void runXOr (vm::main::Driver &drive);

}
}
}
}

#endif // LOGICAL_H
