#ifndef WAINTING_H
#define WAINTING_H

#include "../../parser.h"



namespace VM { namespace Driver { namespace Navigation { namespace Wainting {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runPrepareWaitForPageLoad ();
	static void runWaitForPageLoad ();
};

} } } }

#endif // WAINTING_H
