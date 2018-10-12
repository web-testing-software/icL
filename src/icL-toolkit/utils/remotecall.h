#ifndef icL_toolkit_utils_RemoteCall
#define icL_toolkit_utils_RemoteCall

#include <QObject>
#include <QVariant>



namespace icL::toolkit::utils {

/**
 * @brief The RemoteArg class describes a function argument
 */
class RemoteArg : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(QString   name READ name  NOTIFY nameChanged)
	Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)
	// clang-format on

public:
	/**
	 * @brief RemoteArg is the default construtor
	 * @param name is the name of argument
	 */
	RemoteArg(const QString & name);

	/**
	 * @brief name is the name of argument
	 * @return the argument name
	 */
	QString name() const;

	/**
	 * @brief value is the value of argument
	 * @return the value of argument
	 */
	QVariant value() const;

signals:
	void nameChanged(QString name);
	void valueChanged(QVariant value);

public slots:
	/**
	 * @brief setValue set up the value of argument
	 * @param value is the new argument value
	 */
	void setValue(QVariant value);

private:
	QString  m_name;
	QVariant m_value;
};

/**
 * @brief The RemoteCall class describe a remote function call
 */
class RemoteCall : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(int       id READ id   NOTIFY idChanged)
	Q_PROPERTY(QString name READ name NOTIFY nameChanged)

	Q_PROPERTY(QList<RemoteArg*> args READ args NOTIFY argsChanged)
	// clang-format on

public:
	/**
	 * @brief RemoteCall is the default constuctor
	 * @param id is the id of function
	 * @param name is the display name
	 * @param args is the list or requested args
	 */
	RemoteCall(int id, QString name, QList<RemoteArg *> args);

	~RemoteCall();

	/**
	 * @brief id is the id of function
	 * @return the id of function
	 */
	int     id() const;

	/**
	 * @brief name is the display name of function
	 * @return the display name of function
	 */
	QString name() const;

	/**
	 * @brief args is the list of needed args
	 * @return the list of requested args
	 */
	QList<RemoteArg *> args() const;

public slots:

signals:
	void idChanged(int id);
	void nameChanged(QString name);
	void argsChanged(QList<RemoteArg *> args);

private:
	int     m_id;
	QString m_name;

	QList<RemoteArg *> m_args;
};

using Actions = QList<RemoteCall*>;

}  // namespace icL::toolkit::utils

#endif  // icL_toolkit_utils_RemoteCall
