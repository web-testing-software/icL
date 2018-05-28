#ifndef icL_VirtualMachine
#define icL_VirtualMachine

#include <icl-inter/interpreter.h>
#include <icl-memory/interlevel/interlevel.h>


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

class VirtualMachineStack;

class VirtualMachine : public memory::VirtualMachine
{
public:
	VirtualMachine(VirtualMachineStack * vms);

	// memory.VirtualMachine interface
	virtual void exception(const memory::Exception & exc);

private:
	memory::InterLevel il;
	inter::Interpreter interpreter;
};

}  // namespace icL

#endif  // icL_VirtualMachine
