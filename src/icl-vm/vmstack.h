#ifndef icL_VirtualMachineStack
#define icL_VirtualMachineStack

#include "server.h"

#include <icl-inter/interpreter.h>
#include <icl-memory/interlevel/interfaces.h>
#include <icl-memory/state/memory.h>
#include <icl-memory/structures/steptype.h>

#include <QObject>
#include <QThread>


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

class VMStack
	: public QThread
	, public memory::VMStackLowLevel
{
	Q_OBJECT

	Q_PROPERTY(Server * server READ server WRITE setServer NOTIFY serverChanged)

	Server * m_server;

public:
	VMStack();

	memory::Memory * memory();

	Q_INVOKABLE void init(const QString & source, bool contentChanged);
	Q_INVOKABLE void step(int stopRule);

	Server * server() const;

public slots:
	void setServer(Server * server);

public:
	// memory.VirtualMachineStack interface
	virtual void interrupt(
	  memory::FunctionCall                  fcall,
	  std::function<void(memory::Return &)> feedback) override;

	virtual const QString & getWorkingDir() override;
	virtual const QString & getCrossfirePass() override;

	virtual void highlight(int pos1, int pos2) override;

signals:
	void serverChanged(Server * server);

	// switch thread signal
	void invoke_highlight(int po1, int pos2);

	// signal for qml
	void request_Highlight(int pos1, int pos2);

public slots:
	// functions executed in main thread
	void release_hightlight(int pos1, int pos2);

private:
	memory::Memory mem;

	VirtualMachine * vm = nullptr;

	QString source;

	// QThread interface
protected:
	int stopRule;

	void run() override;
};

}  // namespace icL

#endif  // icL_VirtualMachineStack
