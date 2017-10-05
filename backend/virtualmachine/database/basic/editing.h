#ifndef EDITING_H
#define EDITING_H

#include "../../parser.h"



namespace VM { namespace DataBase { namespace Basic { namespace Editing {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	static void runInsert ();
};

} } } }

#endif // EDITING_H
