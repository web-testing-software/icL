#ifndef READC_H
#define READC_H

#include "../../allcommands.h"



namespace VM { namespace Language { namespace Constant { namespace Read {

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

#endif // READC_H
