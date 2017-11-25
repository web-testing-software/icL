#ifndef SYSTEM_H
#define SYSTEM_H

#include "../../parser.h"



namespace vm {
namespace debugger {
namespace basic {
namespace system {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runReport ();
};

}
}
}
}

#endif // SYSTEM_H
