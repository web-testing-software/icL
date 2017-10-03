#ifndef FINDELEMENTS_H
#define FINDELEMENTS_H

#include "../../allcommands.h"



namespace VM { namespace JavaScript { namespace DOM { namespace FindElements {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	void runQuery ();
	void runQueryAll ();
};

} } } }

#endif // FINDELEMENTS_H
