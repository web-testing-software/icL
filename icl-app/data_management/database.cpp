#include "database.h"
#include "dialdescription.h"

#include <QDebug>
#include <QFile>
#include <QSqlQuery>
#include <QTextStream>

DataBase::DataBase (QObject *parent) : QObject (parent) {
	QSqlError err = init ();

	if (err.type () != QSqlError::NoError) {
		qWarning () << err;
		invalid = true;
	}
	else {
		invalid = false;
	}
}

QList <QObject *> DataBase::top9 () {
	QList <QObject *> ret;

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
			DialDescription *dial_descript = new DialDescription ();

			dial_descript->setCount (q.value (count_index).toInt ());
			dial_descript->setUrl (q.value (url_index).toString ());
			dial_descript->setTitle (q.value (name_index).toString ());

			ret << dial_descript;
		}
	}

	return ret;
}

void DataBase::add_visit (QString url, QString name) {
	QSqlQuery	q (db);
	int			site_id;
	QString		site_url;

	if (!site_exp.exactMatch (url)) {
		qWarning () << "The getted url is not valid" << url;
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

	if (!tables.contains ("versions", Qt::CaseInsensitive)) {

		QSqlError returned = transact_file (q, ":/init/create_v1.sql");
		if (returned.type () != QSqlError::NoError) {
			return returned;
		}

#ifdef ICL_ADD_TEST_DB_DATA
		returned = transact_file (q, ":/init/create_testdata.sql");
		if (returned.type () != QSqlError::NoError) {
			return returned;
		}
#endif
	}

	// Later add db update code for backward compatibility if will be necessary

	return q.lastError ();
}

void DataBase::file_to_sql (const QString &filename) {
	QFile		file (filename);
	QTextStream stream (&file);

	file.open (QFile::ReadOnly);
	sql = stream.readAll ();
}

void DataBase::print_error (const QSqlQuery &query) {
	qWarning () << query.lastError ();
}

QSqlError DataBase::transact_file (QSqlQuery &q, const QString &filename) {
	file_to_sql (filename);

	QStringList sqls = sql.trimmed ().split (';', QString::SkipEmptyParts);

	for (const QString &str : sqls) {
		if (!q.exec (str)) {
			return q.lastError ();
		}
	}

	return q.lastError ();
}
