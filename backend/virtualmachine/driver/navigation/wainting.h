#ifndef WAINTING_H
#define WAINTING_H

#include "../../allcommands.h"



namespace VM { namespace Driver { namespace Navigation { namespace Wainting {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	void runPrepareWaitForPageLoad ();
	void runWaitForPageLoad ();
};

} } } }

#endif // WAINTING_H
