#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "../../parser.h"



namespace vm {
namespace driver {
namespace navigation {
namespace navigation {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runGoToURL ();
};

}
}
}
}

#endif // NAVIGATION_H
