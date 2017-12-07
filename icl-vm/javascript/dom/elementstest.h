#ifndef ELEMENTSTEST_H
#define ELEMENTSTEST_H

#include "../../parser.h"



namespace vm::javascript::dom::elementstest {

void parse (main::Driver &drive);

void runIsVisible (main::Driver &drive);
void runGetX (main::Driver &drive);
void runGetY (main::Driver &drive);

}

#endif // ELEMENTSTEST_H
