#ifndef ELEMENTSTEST_H
#define ELEMENTSTEST_H

#include "../../parser.h"



namespace VM { namespace JavaScript { namespace DOM { namespace ElementsTest {

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
