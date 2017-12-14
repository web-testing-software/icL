#ifndef DATASTATE_H
#define DATASTATE_H

#include <QMap>
#include <QVariant>


namespace vm::memory {

class DataState
{
public:
	DataState ();

	// Data types which can be mapped
	enum class Type {
		INVALID,
		BOOLEAN,
		INT,
		DOUBLE,
		STRING,
		STRING_LIST,
		WEB_ELEMENT
	};

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
