#ifndef READC_H
#define READC_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace constant {
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

#endif // READC_H
