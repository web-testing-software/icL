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
	, public memory::VMStack
{
	Q_OBJECT

	Q_PROPERTY(Server * server READ server WRITE setServer NOTIFY serverChanged)
	Q_PROPERTY(QColor sColor READ sColor NOTIFY sColorChanged)
	Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)

public:
	VMStack();

	memory::Memory * memory();

	Q_INVOKABLE void init(const QString & source, bool contentChanged);
	Q_INVOKABLE void step(int stopRule);

	Server * server() const;
	QColor sColor() const;
	bool running() const;

public slots:
	void setServer(Server * server);
	void setRunning(bool running);

public:
	// memory.VirtualMachineStack interface
	virtual void interrupt(
	  memory::FunctionCall                  fcall,
	  std::function<void(memory::Return &)> feedback) override;

	const QString & getWorkingDir() override;
	const QString & getCrossfirePass() override;

	void highlight(int pos1, int pos2) override;

	void exit(const memory::Exception & exc) override;

	void setSColor(memory::SelectionColor scolor) override;

signals:
	void serverChanged(Server * server);

	void sColorChanged(QColor sColor);

	void runningChanged(bool running);

	// switch thread signal
	void invoke_highlight(int po1, int pos2);

	// signal for qml
	void request_Highlight(int pos1, int pos2);

public slots:
	// functions executed in main thread
	void release_hightlight(int pos1, int pos2);

	// QThread interface
protected:
	void run() override;

	int stopRule;

private:
	Server * m_server = nullptr;
	QColor m_sColor;
	memory::SelectionColor e_sColor = memory::SelectionColor::Error;


	memory::Memory mem;

	QString dir_path = ".";
	QString crossfirePass = "123465";

	VirtualMachine * vm = nullptr;

	QString source;

	bool error_state = false;
	bool m_running = false;
};

}  // namespace icL

#endif  // icL_VirtualMachineStack
