#ifndef OUTPUT_H
#define OUTPUT_H

#include "../../parser.h"



namespace vm { namespace database { namespace basic { namespace output {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runSelect ();
};

} } } }

#endif // OUTPUT_H
