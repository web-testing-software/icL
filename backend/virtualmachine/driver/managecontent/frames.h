#ifndef FRAMES_H
#define FRAMES_H

#include "../../parser.h"



namespace vm { namespace driver { namespace managecontent { namespace frames {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runSwitchToFrame ();
	static void runSwitchToDefault ();
};

} } } }

#endif // FRAMES_H
