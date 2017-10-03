#ifndef READL_H
#define READL_H

#include "../../allcommands.h"



namespace VM { namespace Language { namespace LocalMemory { namespace Read {

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
	void runWebElement ();
};

} } } }

#endif // READL_H
