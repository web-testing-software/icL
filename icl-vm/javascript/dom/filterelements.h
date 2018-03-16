#ifndef FILTERELEMENTS_H
#define FILTERELEMENTS_H

#include "../../parser.h"



namespace vm::javascript::dom::filterelements {

void parse (main::Driver &drive);

void runByCSSSelector (main::Driver &drive);
void runByContent (main::Driver &drive);

}

#endif // FILTERELEMENTS_H
