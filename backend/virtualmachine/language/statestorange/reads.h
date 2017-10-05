#ifndef READS_H
#define READS_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace statestorange {
namespace read {

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

#endif // READS_H
