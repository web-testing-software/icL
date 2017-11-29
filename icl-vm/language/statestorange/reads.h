#ifndef READS_H
#define READS_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace statestorange {
namespace read {

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

#endif // READS_H
