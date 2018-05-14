#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>



/**
 *  icL
 *  |- @namespace app
 *	|- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::app {

/**
 * @brief The DataBase class - control the main database
 */
class DataBase : public QObject
{
	Q_OBJECT
public:
	explicit DataBase(QObject* parent = nullptr);

	Q_INVOKABLE QList<QObject*> top9();

	void add_visit(const QString& url, const QString& name);

signals:

public slots:

private:
	QSqlError init();
	void      file_to_sql(const QString& filename);
	void      print_error(const QSqlQuery& query);
	QSqlError transact_file(QSqlQuery& q, const QString& filename);

	QSqlDatabase db;
	QString      sql;
	bool         invalid;

	QRegExp site_exp = QRegExp(R"(https?://((\w+\.)+\w+)/?.*)");
};

}  // namespace icL::app

#endif  // DATABASE_H
