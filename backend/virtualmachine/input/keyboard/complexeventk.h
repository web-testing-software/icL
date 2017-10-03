#ifndef COMPLEXEVENTK_H
#define COMPLEXEVENTK_H

#include "../../allcommands.h"



namespace VM { namespace Input { namespace Keyboard { namespace ComplexEvent {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	void runSendKey ();
};

} } } }

#endif // COMPLEXEVENTK_H
