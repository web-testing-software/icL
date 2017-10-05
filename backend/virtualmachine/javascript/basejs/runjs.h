#ifndef RUNJS_H
#define RUNJS_H

#include "../../parser.h"



namespace vm { namespace javascript { namespace basejs { namespace runjs {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runRunString ();
	static void runRunFile ();
};

} } } }

#endif // RUNJS_H
