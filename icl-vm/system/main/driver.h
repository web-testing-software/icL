#ifndef DRIVER_H
#define DRIVER_H

#include "memorystate.h"
#include "stackstate.h"

#include <QObject>

namespace vm {

enum class Error;

namespace main {

class Driver : public QObject
{
	Q_OBJECT
public:
	explicit Driver (QObject *parent = nullptr);

	// External access to functions
	MemoryStateIterator* memoryStateIt ();
	StackStateIterator* stackStateIt ();

	// Base functions
	void openFile (const QString &path);
	bool containsVar (const QString &name);
	bool checkType (const QString &name, DataState::Type &type);
	QVariant getVar (const QString &name);

	// Debug functions
	void setError (Error m_error, const QString &description = "");

	// `Loop current` mode helper functions
	MemoryState* memoryStateToStop ();
	void setMemoryStateToStop (MemoryState *ms);

	// Parser interface
	int currentCommand ();
	const QMap <QString, QVariant>* currentParams ();

	// Intereter interface
	void setCurrentCommand (int n_currentCommand);
	void setCurrentParams (const QMap <QString, QVariant> &n_currentParams);

signals:

public slots:

private:
	MemoryStateIterator m_memoryStateIt;
	StackStateIterator m_stackStateIt;
	MemoryState *m_memoryStateToStop;

	Error m_error;
	QString last_error;

	bool m_runIsPermited	= true;
	int m_currentCommand	= 0x0;
	QMap <QString, QVariant> m_currentParams;
};

}   // system
}   // vm

#endif // DRIVER_H
