#ifndef FILTERELEMENTS_H
#define FILTERELEMENTS_H

#include "../../parser.h"



namespace VM { namespace JavaScript { namespace DOM { namespace FilterElements {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runByCSSSelector ();
	static void runByContent ();
};

} } } }

#endif // FILTERELEMENTS_H
