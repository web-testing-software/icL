#ifndef ELEMENTSTEST_H
#define ELEMENTSTEST_H

#include "../../allcommands.h"



namespace VM { namespace JavaScript { namespace DOM { namespace ElementsTest {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	void runIsVisible ();
	void runGetX ();
	void runGetY ();
};

} } } }

#endif // ELEMENTSTEST_H
