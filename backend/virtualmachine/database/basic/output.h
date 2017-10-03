#ifndef OUTPUT_H
#define OUTPUT_H

#include "../../allcommands.h"



namespace VM { namespace DataBase { namespace Basic { namespace Output {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	void runSelect ();
};

} } } }

#endif // OUTPUT_H
