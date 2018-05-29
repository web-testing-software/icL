#ifndef icL_VirtualMachineStack
#define icL_VirtualMachineStack

#include "server.h"

#include <icl-inter/interpreter.h>
#include <icl-memory/interlevel/interfaces.h>
#include <icl-memory/state/memory.h>
#include <icl-memory/structures/steptype.h>

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

class VirtualMachine;

class VirtualMachineStack
	: public QObject
	, public memory::VirtualMachineStack
{
	Q_OBJECT

	Q_PROPERTY(Server * server READ server WRITE setServer NOTIFY serverChanged)

	Server * m_server;

public:
	VirtualMachineStack();

	memory::Memory * memory();

	Q_INVOKABLE void init(const QString & source, bool contentChanged);
	Q_INVOKABLE void step(memory::StepType::Value stopRule);

	Server * server() const;

	// memory.VirtualMachineStack interface
	virtual void interrupt(
	  memory::FunctionCall                  fcall,
	  std::function<void(memory::Return &)> feedback) override;

	virtual const QString & getWorkingDir() override;
	virtual const QString & getCrossfirePass() override;

	virtual void highlight(int pos1, int pos2) override;

public slots:
	void setServer(Server * server);

signals:
	void serverChanged(Server * server);

	void requestHighlight(int pos1, int pos2);

private:
	VirtualMachine * vm;

	QString source;
};

}  // namespace icL

#endif  // icL_VirtualMachineStack
