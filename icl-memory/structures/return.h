#ifndef RETURN_H
#define RETURN_H

#include <QVariant>



namespace vm::memory {

class Return
{
public:
	Return ();

	QVariant returnValue;
	QVariant consoleValue;

	int error, line;
	QString message;
};

} // namespace

#endif // RETURN_H
