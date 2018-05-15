#ifndef RETURN_H
#define RETURN_H

#include "exception.h"

#include <QVariant>


/**
 *  icL
 *  |- app
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
namespace icL::memory {

class Return
{
public:
	Return() = default;
	QVariant returnValue;
	QVariant consoleValue;

	Exception exception;
};

}  // namespace icL::memory

#endif  // RETURN_H
