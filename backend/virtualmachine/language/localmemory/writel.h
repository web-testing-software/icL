#ifndef WRITEL_H
#define WRITEL_H

#include "../../parser.h"



namespace VM { namespace Language { namespace LocalMemory { namespace Write {

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
	static void runWebElement ();
};

} } } }


#endif // WRITEL_H
