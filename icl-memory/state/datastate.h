#ifndef DATASTATE_H
#define DATASTATE_H

#include <QMap>
#include <QVariant>

#include "../structures/type.h"


namespace vm::memory {

/**
 * @brief The DataState class - interface for stack state and memory state
 */
class DataState
{
public:
	DataState ();

	// Functions to add data to containers
	void setValue (const QString &name, QVariant &value);
	void addToStringList (const QString &name, QString &value);

	// Functions to access data and metadata from containers
	bool contains (const QString &name);
	Type getType (const QString &name);
	bool checkType (const QString &name, Type &type);
	QVariant getValue (const QString &name);

private:
	// Data container
	QVariantMap dataMap;
};

}

#endif // DATASTATE_H
