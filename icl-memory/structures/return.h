#ifndef icL_memory_Return
#define icL_memory_Return

#include "exception.h"

#include <QVariant>


/**
 *  icL
 *  |- app
 *  |- context
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

#endif  // icL_memory_Return
