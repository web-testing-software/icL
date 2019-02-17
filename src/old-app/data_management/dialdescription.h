#ifndef icL_app_DialDescription
#define icL_app_DialDescription

#include <QObject>



namespace icL::app {

/**
 * \~english
 * @brief The DialDescription class describes a speed dial (QML compatible)
 */
class DialDescription : public QObject
{
	Q_OBJECT

	/// \~english How many times user has accesed this site.
	Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
	/// \~english The site main page title.
	Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
	/// \~english The url of the main page.
	Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)

	/// \~english title property field.
	QString m_title;
	/// \~english url property field.
	QString m_url;
	/// \~english count property field.
	int m_count;

public:
	explicit DialDescription(QObject * parent = nullptr);

	/// \~english count property getter.
	int count() const;
	/// \~english title property getter.
	QString title() const;
	/// \~english url property getter.
	QString url() const;

signals:
	/// \~english count property signal.
	void countChanged(int count);
	/// \~english title property signal.
	void titleChanged(QString title);
	/// \~english url property signal.
	void urlChanged(QString url);

public slots:
	/// \~english count property setter.
	void setCount(int count);
	/// \~english title property setter.
	void setTitle(const QString & title);
	/// \~english url proerty setter.
	void setUrl(const QString & url);
};

}  // namespace icL::app

#endif  // icL_app_DialDescription
