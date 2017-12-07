#ifndef FRAMES_H
#define FRAMES_H

#include "../../parser.h"



namespace vm::driver::managecontent::frames {

void parse (main::Driver &drive);


void runSwitchToFrame (main::Driver &drive);
void runSwitchToDefault (main::Driver &drive);

}

#endif // FRAMES_H
