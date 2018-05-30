//#ifndef VMSTACKHIGHLEVEL_H
//#define VMSTACKHIGHLEVEL_H

//#include "steptypehighlevel.h"

//#include <icl-vm/vmstack.h>

//#include <QObject>

//namespace icL::app {

//class ServerHighLevel;

//class VMStackHighLevel
//	: public QObject
//	, public VMStack
//{
//	Q_OBJECT

//	Q_PROPERTY(ServerHighLevel * server READ server WRITE setServer NOTIFY serverChanged)

//public:
//	VMStackHighLevel() = default;

//	Q_INVOKABLE void init(const QString & source, bool contentChanged);
//	Q_INVOKABLE void step(StepTypeHighLevel::Value stopRule);

//	// memory.VMStackLowLevel interface
//	virtual void highlight(int pos1, int pos2) override;

//	// Properties
//	ServerHighLevel * server() const;

//	virtual Server * serverMiddleLevel() const override;

//public slots:
//	void setServer(ServerHighLevel * server);

//signals:
//	void serverChanged(ServerHighLevel * server);

//	void requestHighlight(int pos1, int pos2);

//private:
//	ServerHighLevel * m_server;
//};
//}  // namespace icL::app

//#endif  // VMSTACKHIGHLEVEL_H
