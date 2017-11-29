#ifndef NOTEQUAL_H
#define NOTEQUAL_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace booloperator {
namespace notequal {

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

#endif // NOTEQUAL_H
