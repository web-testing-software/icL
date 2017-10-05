#ifndef COMPLEXEVENTK_H
#define COMPLEXEVENTK_H

#include "../../parser.h"



namespace vm { namespace input { namespace keyboard { namespace complexevent {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runSendKey ();
};

} } } }

#endif // COMPLEXEVENTK_H
