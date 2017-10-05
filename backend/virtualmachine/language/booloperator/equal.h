#ifndef EQUAL_H
#define EQUAL_H

#include "../../parser.h"



namespace VM { namespace Language { namespace BoolOperator { namespace Equal {

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
