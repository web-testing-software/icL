#ifndef WRITES_H
#define WRITES_H

#include "../../parser.h"



namespace vm::language::statestorange::write {

void parse (main::Driver &drive);


void runBoolean (main::Driver &drive);
void runInt (main::Driver &drive);
void runDouble (main::Driver &drive);
void runString (main::Driver &drive);
void runStringList (main::Driver &drive);

}

#endif // WRITES_H
