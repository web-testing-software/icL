#ifndef COMMENT_H
#define COMMENT_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace control {
namespace comment {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runDelimiter ();
	static void runLine ();
	static void runMultiline ();
};

}
}
}
}

#endif // COMMENT_H
