#ifndef LOGICAL_H
#define LOGICAL_H

#include "../../allcommands.h"



namespace VM { namespace Language { namespace BoolOperator { namespace Logical {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	void runNot ();
	void runAnd ();
	void runOr ();
	void runXOr ();
};

} } } }

#endif // LOGICAL_H
