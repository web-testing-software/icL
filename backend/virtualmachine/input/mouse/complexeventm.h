#ifndef COMPLEXEVENTM_H
#define COMPLEXEVENTM_H

#include "../../parser.h"



namespace vm {
namespace input {
namespace mouse {
namespace complexevent {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runClick ();
};

}
}
}
}

#endif // COMPLEXEVENTM_H
