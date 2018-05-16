#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H

#include <icl-memory/interlevel/interlevel.h>


/**
 *  @namespace icL
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
 *  '- memory
 */
namespace icL {

class VirtualMachine
{
public:
	VirtualMachine();

private:
	memory::interlevel::InterLevel il;
};

}  // namespace icL

#endif  // VIRTUALMACHINE_H
