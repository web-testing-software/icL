#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>



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
