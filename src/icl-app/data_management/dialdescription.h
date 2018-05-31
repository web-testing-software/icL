#ifndef icL_app_DialDescription
#define icL_app_DialDescription

#include <QObject>



/**
 *  icL
 *  |-> app
 *  |- context
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
 * @brief The DialDescription class - describe a speed dial (QML compatible)
 */
class DialDescription : public QObject
{
	Q_OBJECT

	Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
	Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
	Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)

	QString m_title;
	QString m_url;
	int     m_count;

public:
	explicit DialDescription(QObject * parent = nullptr);

	int     count() const;
	QString title() const;
	QString url() const;

signals:

	void countChanged(int count);
	void titleChanged(QString title);
	void urlChanged(QString url);

public slots:
	void setCount(int count);
	void setTitle(const QString & title);
	void setUrl(const QString & url);
};

}  // namespace icL::app

#endif  // icL_app_DialDescription
