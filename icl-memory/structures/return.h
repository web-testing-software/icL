#ifndef RETURN_H
#define RETURN_H

#include "exception.h"

#include <QVariant>



namespace vm::memory {

class Return
{
public:
	Return ();

	QVariant returnValue;
	QVariant consoleValue;

	Exception exception;
};

} // namespace

#endif // RETURN_H
