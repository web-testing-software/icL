#ifndef icL_memory_interfaces_h
#define icL_memory_interfaces_h

#include "../structures/functioncontainer.h"
#include "../structures/return.h"


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

class Exception;

class Interpreter
{
public:
	virtual void newSignal(int code, const QString & name) = 0;
};

class VirtualMachine
{
public:
	virtual void exception(const Exception & exc) = 0;
};

class VirtualMachineStack
{
public:
	virtual Return          interrupt(FunctionCall fcall) = 0;
	virtual const QString & getWorkingDir()               = 0;
	virtual const QString & getCrossfirePass()            = 0;
	virtual const QString * source()                      = 0;
};

class Server
{
public:
	virtual QVariant runJS(const QString & code)                = 0;
	virtual bool     click(int x, int y)                        = 0;
	virtual void     keys(const QString & keys)                 = 0;
	virtual void     newLog(int level, const QString & message) = 0;
	virtual bool     get(const QString & url)                   = 0;
};

}  // namespace icL::memory

#endif  // icL_memory_interfaces_h
