#ifndef ELEMENTSTEST_H
#define ELEMENTSTEST_H

#include "../../parser.h"



namespace vm { namespace javascript { namespace dom { namespace elementstest {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runIsVisible ();
	static void runGetX ();
	static void runGetY ();
};

} } } }

#endif // ELEMENTSTEST_H
