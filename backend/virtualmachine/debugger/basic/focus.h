#ifndef FOCUS_H
#define FOCUS_H

#include "../../allcommands.h"



namespace VM { namespace Debugger { namespace Basic { namespace Focus {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	void runCommand ();
};

} } } }

#endif // FOCUS_H
