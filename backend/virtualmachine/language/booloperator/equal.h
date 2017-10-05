#ifndef EQUAL_H
#define EQUAL_H

#include "../../parser.h"



namespace vm { namespace language { namespace booloperator { namespace equal {

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

#endif // EQUAL_H
