#ifndef FINDELEMENTS_H
#define FINDELEMENTS_H

#include "../../parser.h"



namespace vm {
namespace javascript {
namespace dom {
namespace findelements {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runQuery ();
	static void runQueryAll ();
};

}
}
}
}

#endif // FINDELEMENTS_H
