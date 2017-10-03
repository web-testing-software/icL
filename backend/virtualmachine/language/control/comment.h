#ifndef COMMENT_H
#define COMMENT_H

#include "../../allcommands.h"



namespace VM { namespace Language { namespace Control { namespace Comment {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	void runDelimiter ();
	void runLine ();
	void runMultiline ();
};

} } } }

#endif // COMMENT_H
