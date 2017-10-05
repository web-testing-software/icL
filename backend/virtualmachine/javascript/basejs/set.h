#ifndef SET_H
#define SET_H

#include "../../parser.h"



namespace VM { namespace JavaScript { namespace BaseJS { namespace Set {

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

} } } }

#endif // SET_H
