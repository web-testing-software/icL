#ifndef GET_H
#define GET_H

#include "../../allcommands.h"



namespace VM { namespace JavaScript { namespace BaseJS { namespace Get {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	void runBoolean ();
	void runInt ();
	void runDouble ();
	void runString ();
	void runStringList ();
};

} } } }

#endif // GET_H
