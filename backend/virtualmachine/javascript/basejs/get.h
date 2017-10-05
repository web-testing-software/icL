#ifndef GET_H
#define GET_H

#include "../../parser.h"



namespace vm {
namespace javascript {
namespace basejs {
namespace get {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runBoolean ();
	static void runInt ();
	static void runDouble ();
	static void runString ();
	static void runStringList ();
};

}
}
}
}

#endif // GET_H
