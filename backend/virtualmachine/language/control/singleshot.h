#ifndef SINGLESHOT_H
#define SINGLESHOT_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace control {
namespace singleshot {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runIf ();
	static void runBeginIf ();
	static void runElse ();
	static void runEndIf ();
};

}
}
}
}

#endif // SINGLESHOT_H
