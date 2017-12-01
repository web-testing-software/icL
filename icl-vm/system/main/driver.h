#ifndef DRIVER_H
#define DRIVER_H

#include <QObject>

#include "system/functions/server.h"
#include "state/datacontainer.h"

namespace vm {

enum class Error;

namespace main {

class Driver : public QObject
{
	Q_OBJECT

	Q_PROPERTY (Server *server READ server)
	Q_PROPERTY (memory::DataContainer *dataContainer READ dataContainer)

public:
	explicit Driver (QObject *parent = nullptr);

	// External access to functions
	Server* server ();

	// QML functions
	Q_INVOKABLE void openFile (const QString &path);

	// Parser interface
	int currentCommand ();
	const QVariantMap* currentParams ();

	// Intereter interface
	void setCurrentCommand (int n_currentCommand);
	void setCurrentParams (const QVariantMap &n_currentParams);

	memory::DataContainer* dataContainer ();

signals:

public slots:

private:
	Server m_server;

	bool m_runIsPermited	= true;
	int m_currentCommand	= 0x0;
	QVariantMap m_currentParams;
	memory::DataContainer m_dataContainer;
};

}   // system
}   // vm

#endif // DRIVER_H
