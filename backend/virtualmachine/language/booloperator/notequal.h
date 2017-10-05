#ifndef NOTEQUAL_H
#define NOTEQUAL_H

#include "../../parser.h"



namespace VM { namespace Language { namespace BoolOperator { namespace NotEqual {

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

#endif // NOTEQUAL_H
