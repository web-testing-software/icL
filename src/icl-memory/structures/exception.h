#ifndef icL_memory_Exception
#define icL_memory_Exception

#include <QString>


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
 *  '-> memory
 */
namespace icL::memory {

class Exception
{
public:
	Exception() = default;
	Exception(int code, const QString & message);

	int     code, line;
	QString message;
};

}  // namespace icL::memory

#endif  // icL_memory_Exception
