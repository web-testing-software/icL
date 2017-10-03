#ifndef READS_H
#define READS_H

#include "../../allcommands.h"



namespace VM { namespace Language { namespace StateStorange { namespace Read {

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

#endif // READS_H
