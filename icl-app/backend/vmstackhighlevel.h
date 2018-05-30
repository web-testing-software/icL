#ifndef VMSTACKHIGHLEVEL_H
#define VMSTACKHIGHLEVEL_H

#include <icl-vm/vmstack.h>

#include <QObject>

namespace icL::app {

class VMStackHighLevel
	: public QObject
	, public VMStack
{
	Q_OBJECT

	Q_PROPERTY(Server * server READ server WRITE setServer NOTIFY serverChanged)

public:
	VMStackHighLevel() = default;

	Q_INVOKABLE void init(const QString & source, bool contentChanged);
	Q_INVOKABLE void step(memory::StepType::Value stopRule);

	// memory.VMStackLowLevel interface
	virtual void highlight(int pos1, int pos2) override;

	// Properties
	Server * server() const override;

public slots:
	void setServer(Server * server);

signals:
	void serverChanged(Server * server);

	void requestHighlight(int pos1, int pos2);


};
}  // namespace icL::app

#endif  // VMSTACKHIGHLEVEL_H
