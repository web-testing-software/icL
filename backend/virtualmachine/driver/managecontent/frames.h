#ifndef FRAMES_H
#define FRAMES_H

#include "../../parser.h"



namespace vm {
namespace driver {
namespace managecontent {
namespace frames {

void parse (vm::main::Driver &drive);


void runSwitchToFrame (vm::main::Driver &drive);
void runSwitchToDefault (vm::main::Driver &drive);


}
}
}
}

#endif // FRAMES_H
