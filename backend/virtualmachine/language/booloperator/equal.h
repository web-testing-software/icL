#ifndef EQUAL_H
#define EQUAL_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace booloperator {
namespace equal {

void parse (vm::main::Driver &drive);

void runBoolean (vm::main::Driver &drive);
void runInt (vm::main::Driver &drive);
void runDouble (vm::main::Driver &drive);
void runString (vm::main::Driver &drive);
void runStringList (vm::main::Driver &drive);

}
}
}
}

#endif // EQUAL_H
