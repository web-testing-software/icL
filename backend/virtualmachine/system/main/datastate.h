#ifndef DATASTATE_H
#define DATASTATE_H

#include <QMap>
#include <QVariant>


namespace vm {
namespace system {

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
	void setBoolean (const QString &name, bool &value);
	void setInt (const QString &name, int &value);
	void setDouble (const QString &name, double &value);
	void setString (const QString &name, QString &value);
	void setStringList (const QString &name, QStringList &value);
	void addToStringList (const QString &name, QString &value);

	// Functions to access data and metadata from containers
	virtual bool contains (const QString &name);
	virtual Type getType (const QString &name);
	virtual bool checkType (const QString &name, Type &type);
	virtual QVariant getValue (const QString &name);

private:
	// Containers
	QMap <QString, bool> boolMap;
	QMap <QString, int> intMap;
	QMap <QString, double> doubleMap;
	QMap <QString, QString> stringMap;
	QMap <QString, QStringList> stringListMap;
};

}
}

#endif // DATASTATE_H
