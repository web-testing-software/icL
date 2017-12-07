#ifndef RUNJS_H
#define RUNJS_H

#include "../../parser.h"



namespace vm::javascript::basejs::runjs {

void parse (main::Driver &drive);

void runRunString (main::Driver &drive);
void runRunFile (main::Driver &drive);

}

#endif // RUNJS_H
