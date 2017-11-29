#ifndef FILTERELEMENTS_H
#define FILTERELEMENTS_H

#include "../../parser.h"



namespace vm {
namespace javascript {
namespace dom {
namespace filterelements {

void parse (vm::main::Driver &drive);

void runByCSSSelector (vm::main::Driver &drive);
void runByContent (vm::main::Driver &drive);

}
}
}
}

#endif // FILTERELEMENTS_H
