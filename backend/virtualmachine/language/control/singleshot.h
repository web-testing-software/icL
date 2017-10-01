#ifndef SINGLESHOT_H
#define SINGLESHOT_H

#include "../../allcommands.h"



namespace VM { namespace Language { namespace Control { namespace SingleShot {

void parse (int &command);

void runIf ();
void runBeginIf ();
void runElse ();
void runEndIf ();

} } } }

#endif // SINGLESHOT_H
