#ifndef EDITING_H
#define EDITING_H

#include "../../parser.h"



namespace vm { namespace database { namespace basic { namespace editing {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runInsert ();
};

} } } }

#endif // EDITING_H
