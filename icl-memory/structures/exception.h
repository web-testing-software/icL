#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>


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

class Exception
{
public:
	Exception(int code, const QString& message);

	int     code, line;
	QString message;
};

}  // namespace icL::memory

#endif  // EXCEPTION_H
