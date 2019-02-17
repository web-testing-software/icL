#ifndef icL_app_Database
#define icL_app_Database

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>



namespace icL::app {

/**
 * \~english
 * @brief The DataBase class controls the main database.
 */
class DataBase : public QObject
{
	Q_OBJECT
public:
	/// \~english Default cntructor, iniialize the database.
	explicit DataBase(QObject * parent = nullptr);

	/// \~english Get the list of the most popular sites.
	Q_INVOKABLE QList<QObject *> top9();

	/// \~english Register the site visite.
	void add_visit(const QString & url, const QString & name);

signals:

public slots:

private:
	/// \~english initialize the database, if the build is debug, add test data.
	QSqlError init();

	/**
	 * \~english
	 * @brief file_to_sql copies file to sql field.
	 * @param filename - the name of the file to copy.
	 *
	 * file_to_sql opens a file in text mode, after copy all file content to
	 * QString and execute it in sql field.
	 */
	void file_to_sql(const QString & filename);

	/**
	 * \~english
	 * @brief print_error prints a error of the SQL query.
	 * @param query - reference to query object.
	 * @todo Print error to screen (!console).
	 */
	void print_error(const QSqlQuery & query);

	/**
	 * \~english
	 * @brief transact_file - execute a SQL file.
	 * @param q - reference to query object, which will execute SQL command.
	 * @param filename - path to the SQL file to execute.
	 * @return First triggered error on execute of SQL commands.
	 *
	 * transact_file will copy the file content to RAM using file_to_sql,
	 * after will split the file contents, and execute each command. The SQLite
	 * database support only command execution, to run files was developed this
	 * function.
	 */
	QSqlError transact_file(QSqlQuery & q, const QString & filename);

	/// \~english The datbase object.
	QSqlDatabase db;
	/// \~english This private field is used to transmite data beetween methods.
	QString sql;
	/// \~english The database failed to initialize, restrict is future use.
	bool invalid;

	/// \~english Regular expression to extract domain name from URL.
	QRegExp site_exp = QRegExp(R"(https?://((\w+\.)+\w+)/?.*)");
};

}  // namespace icL::app

#endif  // icL_app_Database
