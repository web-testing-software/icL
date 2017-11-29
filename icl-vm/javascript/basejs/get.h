#ifndef GET_H
#define GET_H

#include "../../parser.h"



namespace vm {
namespace javascript {
namespace basejs {
namespace get {

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

#endif // GET_H
