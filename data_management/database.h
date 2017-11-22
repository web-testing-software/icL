#ifndef DATABASE_H
#define DATABASE_H

#include "dialdescription.h"

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>

class DataBase : public QObject
{
	Q_OBJECT
public:
	explicit DataBase(QObject *parent = nullptr);

	Q_INVOKABLE QList<DialDescription> top9 ();

signals:

public slots:

private:
	QSqlError init();

	QSqlDatabase db;
	bool invalid = false;
};

#endif // DATABASE_H
