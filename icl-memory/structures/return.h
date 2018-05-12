#ifndef RETURN_H
#define RETURN_H

#include "exception.h"
#include <QVariant>



namespace vm::memory {

class Return
{
public:
	Return() = default;
	QVariant returnValue;
	QVariant consoleValue;

	Exception exception;
};

}  // namespace vm::memory

#endif  // RETURN_H
