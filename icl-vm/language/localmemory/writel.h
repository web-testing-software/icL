#ifndef WRITEL_H
#define WRITEL_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace localmemory {
namespace write {

void parse (vm::main::Driver &drive);


void runBoolean (vm::main::Driver &drive);
void runInt (vm::main::Driver &drive);
void runDouble (vm::main::Driver &drive);
void runString (vm::main::Driver &drive);
void runStringList (vm::main::Driver &drive);
void runWebElement (vm::main::Driver &drive);

}
}
}
}


#endif // WRITEL_H
