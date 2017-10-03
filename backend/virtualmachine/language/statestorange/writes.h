#ifndef WRITES_H
#define WRITES_H

#include "../../allcommands.h"



namespace VM { namespace Language { namespace StateStorange { namespace Write {

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

#endif // WRITES_H
