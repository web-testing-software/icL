#ifndef LOGICAL_H
#define LOGICAL_H

#include "../../parser.h"



namespace VM { namespace Language { namespace BoolOperator { namespace Logical {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runNot ();
	static void runAnd ();
	static void runOr ();
	static void runXOr ();
};

} } } }

#endif // LOGICAL_H
