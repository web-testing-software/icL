#ifndef DIALDESCRIPTION_H
#define DIALDESCRIPTION_H

#include <QObject>

class DialDescription : public QObject
{
	Q_OBJECT

	Q_PROPERTY (int count READ count WRITE setCount NOTIFY countChanged)
	Q_PROPERTY (QString title READ title WRITE setTitle NOTIFY titleChanged)
	Q_PROPERTY (QString url READ url WRITE setUrl NOTIFY urlChanged)

	int m_count;
	QString m_title;
	QString m_url;

public:
	explicit DialDescription (QObject *parent = nullptr);

	int count () const;
	QString title () const;
	QString url () const;

signals:

	void countChanged (int count);
	void titleChanged (QString title);
	void urlChanged (QString url);

public slots:
	void setCount (int count);
	void setTitle (const QString &title);
	void setUrl (const QString &url);
};

#endif // DIALDESCRIPTION_H
