#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "../../parser.h"



namespace VM { namespace Driver { namespace Navigation { namespace Navigation {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runGoToURL ();
};

} } } }

#endif // NAVIGATION_H
