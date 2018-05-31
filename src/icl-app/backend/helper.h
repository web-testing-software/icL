#ifndef icL_app_Helper
#define icL_app_Helper

#include <QColor>
#include <QObject>
#include <QUrl>

class QQuickTextDocument;

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
 * @brief The Helper class export some C++ only Qt functionallity to QML
 */
class Helper : public QObject
{
	Q_OBJECT

public:
	explicit Helper(QObject * parent = nullptr);

	Q_INVOKABLE QColor
				mix(const QColor & color1, const QColor & color2, qreal alpha);
	Q_INVOKABLE QColor
				linearMix(const QColor & color1, const QColor & color2, qreal alpha);

	Q_INVOKABLE QString cacheDir(const QString & profileName);
	Q_INVOKABLE QString dataDir(const QString & profileName);
	Q_INVOKABLE QString profileDir(const QString & profileName);

	Q_INVOKABLE QUrl urlFromUserInput(const QString & input);

	Q_INVOKABLE int  symbolWidth(int fontSize);
	Q_INVOKABLE void setTabsize(
	  int fontSize, QQuickTextDocument * quickTextDocument);

signals:

public slots:

private:
	void makeDirIfNotExist(const QString & dirpath);

	QString m_cache_dir;
	QString m_config_dir;
	QString m_data_dir;
};

}  // namespace icL::app

#endif  // icL_app_Helper
