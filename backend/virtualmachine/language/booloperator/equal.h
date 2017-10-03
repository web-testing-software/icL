#ifndef EQUAL_H
#define EQUAL_H

#include "../../allcommands.h"



namespace VM { namespace Language { namespace BoolOperator { namespace Equal {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	void runBoolean ();
	void runInt ();
	void runDouble ();
	void runString ();
	void runStringList ();
};

} } } }

#endif // EQUAL_H
