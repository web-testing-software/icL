#ifndef icL_VirtualMachine
#define icL_VirtualMachine

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
	memory::InterLevel il;
};

}  // namespace icL

#endif  // icL_VirtualMachine
