#ifndef WRITES_H
#define WRITES_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace statestorange {
namespace write {

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

#endif // WRITES_H
