#include "database.h"

#include <QDebug>
#include <QFile>
#include <QSqlQuery>
#include <QTextStream>

DataBase::DataBase (QObject *parent) : QObject (parent) {

}

QList <DialDescription> DataBase::top9 () {
	QList <DialDescription> ret;

	if (invalid) {
		return ret;
	}

	QSqlQuery	q (db);
	QFile		top9_file (":/select/top9.sql");
	QTextStream top9_stream (&top9_file);
	QString		sql;

	top9_file.open (QFile::ReadOnly);
	sql = top9_stream.readAll ();
	if (!q.exec (sql)) {
		print_error (q);
	}
	else {
		// This indexes need to be updated on request select params changed
		const int	name_index	= 0;
		const int	url_index	= 1;
		const int	count_index = 2;

		while (q.next ()) {
			DialDescription dial_descript;

			dial_descript.setCount (q.value (count_index).toInt ());
			dial_descript.setUrl (q.value (url_index).toString ());
			dial_descript.setTitle (q.value (name_index).toString ());

			ret << dial_descript;
		}
	}

	return ret;
}

void DataBase::add_visit (QString url, QString name) {
	QSqlQuery q (db);
	int site_id;
	QString site_url;

	if (!site_exp.exactMatch (url)) {
		qWarning() << "The getted url is not valid" << url;
		return;
	}

	file_to_sql (":/select/site_id.sql");
	q.prepare (sql);
	q.addBindValue (site_url);
	if (!q.exec ()) {
		print_error (q);
		return;
	}

	if (q.next ()) {
		site_id = q.value (0).toInt ();
	}
	else {
		file_to_sql (":/insert/site.sql");
		q.prepare (sql);
		q.addBindValue (site_url);
		q.addBindValue (name);
		if (!q.exec ()) {
			print_error (q);
			return;
		}

		site_id = q.lastInsertId ().toInt ();
	}

	file_to_sql (":/insert/visit.sql");
	q.prepare (sql);
	q.addBindValue (site_id);
	q.addBindValue (name);
	if (!q.exec ()) {
		print_error (q);
		return;
	}
}

QSqlError DataBase::init () {
	db = QSqlDatabase::addDatabase ("QSQLITE");
	db.setDatabaseName ("ic-lightning.db");

	if (!db.open ()) {
		return db.lastError ();
	}

	QStringList tables = db.tables ();
	QSqlQuery	q (db);
	QString		sql;

	if (!tables.contains ("versions", Qt::CaseInsensitive)) {

		file_to_sql (":/init/create_v1.sql");
		if (!q.exec (sql)) {
			return q.lastError ();
		}

#ifdef ICL_ADD_TEST_DB_DATA
		file_to_sql (":/init/create_testdata.sql");
		if (!q.exec (sql)) {
			return q.lastError ();
		}
#endif
	}

	// Later add db update code for backward compatibility if will be necessary
}

void DataBase::file_to_sql (const QString &filename) {
	QFile		file (filename);
	QTextStream stream (&file);

	file.open (QFile::ReadOnly);
	sql = stream.readAll ();
}

void DataBase::print_error(const QSqlQuery &query)
{
	qWarning() << query.lastError ();
}
