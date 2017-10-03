#ifndef STRINGLIST_H
#define STRINGLIST_H

#include "../../allcommands.h"



namespace VM { namespace Language { namespace BoolOperator { namespace StringList {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	void runContains ();
	void runContainsFragment ();
};

} } } }

#endif // STRINGLIST_H
