#ifndef RETURN_H
#define RETURN_H

#include "exception.h"
#include <QVariant>


/**
 * vm
 *	|- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- @namespace memory
 */
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
