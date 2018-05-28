#ifndef VIRTUALMACHINESTACK_H
#define VIRTUALMACHINESTACK_H

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

class VirtualMachineStack
{
public:
	VirtualMachineStack();
};

} // namespace icL

#endif // VIRTUALMACHINESTACK_H
