#ifndef DRIVER_H
#define DRIVER_H

#include "memorystate.h"
#include "stackstate.h"

#include <QObject>

#include <system/functions/server.h>

namespace vm {

enum class Error;

namespace main {

class Driver : public QObject
{
	Q_OBJECT

	Q_PROPERTY (Server * server READ server)

public:
	explicit Driver (QObject *parent = nullptr);

	// External access to functions
	Server* server ();
	MemoryStateIterator* memoryStateIt ();
	StackStateIterator* stackStateIt ();

	// QML functions
	Q_INVOKABLE void openFile (const QString &path);

	// interface for VM
	bool containsVar (const QString &name);
	bool checkType (const QString &name, DataState::Type &type);
	QVariant getVar (const QString &name);
	void setVar (const QString &name, QVariant &value, bool to_stack);

	void setError (Error m_error, const QString &description = "");

	// `Loop current` mode helper functions
	MemoryState* memoryStateToStop ();
	void setMemoryStateToStop (MemoryState *ms);

	// Parser interface
	int currentCommand ();
	const QVariantMap* currentParams ();

	// Intereter interface
	void setCurrentCommand (int n_currentCommand);
	void setCurrentParams (const QVariantMap &n_currentParams);

signals:

public slots:

private:
	Server m_server;
	MemoryStateIterator m_memoryStateIt;
	StackStateIterator m_stackStateIt;
	MemoryState *m_memoryStateToStop;

	Error m_error;
	QString last_error;

	bool m_runIsPermited	= true;
	int m_currentCommand	= 0x0;
	QVariantMap m_currentParams;

	static const QStringList keywoords;
};

}   // system
}   // vm

#endif // DRIVER_H
