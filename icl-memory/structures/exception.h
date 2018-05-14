#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>


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

class Exception
{
public:
	Exception(int code, const QString& message);

	int     code, line;
	QString message;
};

}  // namespace vm::memory

#endif  // EXCEPTION_H
