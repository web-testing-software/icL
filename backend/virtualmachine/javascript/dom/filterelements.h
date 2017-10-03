#ifndef FILTERELEMENTS_H
#define FILTERELEMENTS_H

#include "../../allcommands.h"



namespace VM { namespace JavaScript { namespace DOM { namespace FilterElements {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	void runByCSSSelector ();
	void runByContent ();
};

} } } }

#endif // FILTERELEMENTS_H
