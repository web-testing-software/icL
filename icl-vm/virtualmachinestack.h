#ifndef icL_VirtualMachineStack
#define icL_VirtualMachineStack

#include <icl-memory/interlevel/interfaces.h>
#include <icl-memory/state/memory.h>

#include <QObject>


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
	: public QObject
	, public memory::VirtualMachineStack
{
	Q_OBJECT

public:
	VirtualMachineStack();

	memory::Memory * memory();

	// memory.VirtualMachineStack interface
	virtual memory::Return  interrupt(memory::FunctionCall fcall) override;
	virtual const QString & getWorkingDir() override;
	virtual const QString & getCrossfirePass() override;
	virtual const QString * source() override;
};

}  // namespace icL

#endif  // icL_VirtualMachineStack
