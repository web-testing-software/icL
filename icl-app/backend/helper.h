#ifndef HELPER_H
#define HELPER_H

#include <QColor>
#include <QObject>
#include <QQuickItem>

/**
 * @brief The Helper class export some C++ only Qt functionallity to QML
 */
class Helper : public QObject
{
	Q_OBJECT

public:
	explicit Helper (QObject *parent = nullptr);

	Q_INVOKABLE QColor mix (const QColor& color1, const QColor& color2, qreal alpha);
	Q_INVOKABLE QColor linearMix (const QColor& color1, const QColor& color2, qreal alpha);

	Q_INVOKABLE QString cacheDir (const QString& profileName);
	Q_INVOKABLE QString dataDir (const QString& profileName);
	Q_INVOKABLE QString profileDir (const QString& profileName);

	Q_INVOKABLE QUrl urlFromUserInput (const QString& input);
signals:

public slots:

private:
	void makeDirIfNotExist(const QString& dirpath);

	QString m_cache_dir;
	QString m_config_dir;
	QString m_data_dir;
};

#endif // HELPER_H