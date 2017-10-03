#ifndef SINGLESHOT_H
#define SINGLESHOT_H

#include "../../allcommands.h"



namespace VM { namespace Language { namespace Control { namespace SingleShot {

void parse (const int &command);

// This class is needed for compability with QML
class Singleton : public QObject {
	Q_OBJECT

public:
	void runIf ();
	void runBeginIf ();
	void runElse ();
	void runEndIf ();

	//	Q_INVOKABLE bool addIf(QVariant v);
	//	Q_INVOKABLE bool addBeginIf(QVariant v);
	//	Q_INVOKABLE bool addElse(QVariant v);
	//	Q_INVOKABLE bool addEndIf(QVariant v);
};

} } } }

#endif // SINGLESHOT_H
