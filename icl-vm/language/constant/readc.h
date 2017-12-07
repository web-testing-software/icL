#ifndef READC_H
#define READC_H

#include "../../parser.h"



namespace vm::language::constant::read {

void parse (main::Driver &drive);


void runBoolean (main::Driver &drive);
void runInt (main::Driver &drive);
void runDouble (main::Driver &drive);
void runString (main::Driver &drive);
void runStringList (main::Driver &drive);

}

#endif // READC_H
