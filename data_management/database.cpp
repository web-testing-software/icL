#include "database.h"

#include <QDebug>
#include <QFile>
#include <QSqlQuery>
#include <QTextStream>

DataBase::DataBase (QObject *parent) : QObject (parent) {

}

QList<DialDescription> DataBase::top9()
{
	QList<DialDescription> ret;

	if (invalid) {
		return ret;
	}

	QSqlQuery q(db);
	QFile top9_file (":/select/top9.sql");
	QTextStream top9_stream (&top9_file);
	QString sql;

	top9_file.open (QFile::ReadOnly);
	sql = top9_stream.readAll ();
	if (!q.exec (sql)) {
		qWarning() << q.lastError ().text ();
	}
	else {
		// This indexes need to be updated on request select params changed
		const int name_index = 0;
		const int url_index = 1;
		const int count_index = 2;

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

QSqlError DataBase::init() {
	db = QSqlDatabase::addDatabase ("QSQLITE");
	db.setDatabaseName ("ic-lightning-browser.db");

	if (!db.open ()) {
		return db.lastError ();
	}

	QStringList tables = db.tables ();
	QSqlQuery	q(db);
	QString		sql;

	if (!tables.contains ("versions", Qt::CaseInsensitive)) {
		QFile		create_v1 (":/init/create_v1.sql");
		QTextStream create_v1_stream (&create_v1);

		create_v1.open (QFile::ReadOnly);
		sql = create_v1_stream.readAll ();
		if (!q.exec (sql)) {
			return q.lastError ();
		}

#ifdef ICL_ADD_TEST_DB_DATA
		QFile		test_data (":/init/create_testdata.sql");
		QTextStream test_data_stream (&test_data);

		test_data.open (QFile::ReadOnly);
		sql = test_data_stream.readAll ();
		if (!q.exec (sql)) {
			return q.lastError ();
		}
#endif
	}

	// Later add db update code for backward compatibility if will be necessary
}
