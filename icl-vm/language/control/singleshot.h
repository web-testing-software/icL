#ifndef SINGLESHOT_H
#define SINGLESHOT_H

#include "../../parser.h"



namespace vm::language::control::singleshot {

void parse (main::Driver &drive);


void runIf (main::Driver &drive);
void runBeginIf (main::Driver &drive);
void runElse (main::Driver &drive);
void runUnexpectedEnd (main::Driver &drive);
void runSuccess (main::Driver &drive);
void runFailed (main::Driver &drive);
void runEmptyStack (main::Driver &drive);
void runOpenStack (main::Driver &drive);
void runDropStack (main::Driver &drive);

}

#endif // SINGLESHOT_H
