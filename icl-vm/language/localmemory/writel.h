#ifndef WRITEL_H
#define WRITEL_H

#include "../../parser.h"



namespace vm::language::localmemory::write {

void parse (main::Driver &drive);


void runBoolean (main::Driver &drive);
void runInt (main::Driver &drive);
void runDouble (main::Driver &drive);
void runString (main::Driver &drive);
void runStringList (main::Driver &drive);
void runWebElement (main::Driver &drive);

}


#endif // WRITEL_H
