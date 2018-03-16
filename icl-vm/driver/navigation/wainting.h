#ifndef WAINTING_H
#define WAINTING_H

#include "../../parser.h"



namespace vm::driver::navigation::wainting {

void parse (main::Driver &drive);


void runPrepareWaitForPageLoad (main::Driver &drive);
void runWaitForPageLoad (main::Driver &drive);

}

#endif // WAINTING_H
