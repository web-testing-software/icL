#ifndef STRINGLIST_H
#define STRINGLIST_H

#include "../../parser.h"



namespace VM { namespace Language { namespace BoolOperator { namespace StringList {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runContains ();
	static void runContainsFragment ();
};

} } } }

#endif // STRINGLIST_H
