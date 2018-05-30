#ifndef icL_VMStack
#define icL_VMStack

#include "server.h"

#include <icl-inter/interpreter.h>
#include <icl-memory/interlevel/interfaces.h>
#include <icl-memory/state/memory.h>
#include <icl-memory/structures/steptype.h>


/**
 * > icL
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
 *  '- memory
 */
namespace icL {

class VirtualMachine;

class VMStack : public memory::VMStackLowLevel
{

public:
	VMStack() = default;

	memory::Memory * memory();

	// memory.VMStackLowLevel interface
	virtual void interrupt(
	  memory::FunctionCall                  fcall,
	  std::function<void(memory::Return &)> feedback) override;

	virtual const QString & getWorkingDir() override;
	virtual const QString & getCrossfirePass() override;

	virtual Server * server() const = 0;

protected:
	Server * m_server;

	VirtualMachine * vm;

	memory::Memory mem;

	QString source;
};

}  // namespace icL

#endif  // icL_VMStack
