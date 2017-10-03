#ifndef WRITEL_H
#define WRITEL_H

#include "../../allcommands.h"



namespace VM { namespace Language { namespace LocalMemory { namespace Write {

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


#endif // WRITEL_H
