#ifndef RUNJS_H
#define RUNJS_H

#include "../../allcommands.h"



namespace VM { namespace JavaScript { namespace BaseJS { namespace RunJS {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	void runRunString ();
	void runRunFile ();
};

} } } }

#endif // RUNJS_H
