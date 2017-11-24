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

	Q_INVOKABLE QList<QObject*> top9 ();

	void add_visit (QString url, QString name);

signals:

public slots:

private:
	QSqlError init();
	void file_to_sql (const QString &filename);
	void print_error (const QSqlQuery &query);
	QSqlError transact_file (QSqlQuery& q, const QString &filename);

	QSqlDatabase db;
	QString sql;
	bool invalid;

	QRegExp site_exp = QRegExp("https?://((\\w+\\.)+\\w+)/?.*");
};

#endif // DATABASE_H