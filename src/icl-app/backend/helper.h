#ifndef icL_app_Helper
#define icL_app_Helper

#include <QColor>
#include <QObject>
#include <QUrl>

class QQuickTextDocument;

/**
 * \~english
 * The namespace app contains all class, needed for developement of application
 * and database.
 * \~russian
 * Пространство имён app содержит все классы, которые нужны для разработки
 * приложении и баз данных.
 */
namespace icL::app {

/**
 * \~english @brief The Helper class export some C++ only Qt functionallity to
 * QML
 */
class Helper : public QObject
{
	Q_OBJECT

public:
	/**
	 * \~english
	 * @brief Helper - default constructor
	 * @param parent - qt's parent object, usualy nullptr
	 */
	explicit Helper(QObject * parent = nullptr);


	/**
	 * \~english
	 * @brief mix - blend 2 color by quadric function (x^2)
	 * @param color1 - begin color
	 * @param color2 - end color
	 * @param alpha - blending coeficient
	 * @return
	 */
	Q_INVOKABLE QColor
				mix(const QColor & color1, const QColor & color2, qreal alpha);

	/**
	 * \~english
	 * @brief linearMix - blend 2 by linear function (x)
	 * @param color1 - begin color
	 * @param color2 - end color
	 * @param alpha - blending coeficient
	 * @return
	 */
	Q_INVOKABLE QColor
				linearMix(const QColor & color1, const QColor & color2, qreal alpha);

	/**
	 * \~english
	 * @brief cacheDir - get user cache directory
	 * @param profileName - name of user profile
	 * @return user cache directory absolute path
	 */
	Q_INVOKABLE QString cacheDir(const QString & profileName);

	/**
	 * \~english
	 * @brief dataDir - get user data directory
	 * @param profileName - name of user profile
	 * @return absolute path of user data directory
	 */
	Q_INVOKABLE QString dataDir(const QString & profileName);

	/**
	 * \~english
	 * @brief profileDir - get user profile directory
	 * @param profileName - name of user profile
	 * @return absolute path of user data directory
	 */
	Q_INVOKABLE QString profileDir(const QString & profileName);

	/**
	 * \~english
	 * @brief urlFromUserInput - call QUrl::fromUserInput(url)
	 * @param input url argument of QUrl::fromUserInput
	 * @return an url from user input
	 */
	Q_INVOKABLE QUrl urlFromUserInput(const QString & input);

	/**
	 * \~english
	 * @brief symbolWidth - width of symbol of monospace font
	 * @param fontSize - size of font in pixels
	 * @return width of symbol of monospace font in pixels
	 */
	Q_INVOKABLE int symbolWidth(int fontSize);

	/**
	 * \~english
	 * @brief setTabsize - set tab size for text document
	 * @param fontSize - size of font in pixels
	 * @param quickTextDocument - document to set tab size
	 */
	Q_INVOKABLE void setTabsize(
	  int fontSize, QQuickTextDocument * quickTextDocument);

signals:

public slots:

private:
	/**
	 * \~english
	 * @brief makeDirIfNotExist - make a directory if it doesn't exist
	 * @param dirpath - absolute path of directory
	 */
	void makeDirIfNotExist(const QString & dirpath);

	/**
	 * \~english @brief m_cache_dir - cached user cache directory
	 */
	QString m_cache_dir;

	/**
	 * \~english @brief m_config_dir - cached user configuration directory
	 */
	QString m_config_dir;

	/**
	 * \~english @brief m_data_dir - cached user data directory
	 */
	QString m_data_dir;
};

}  // namespace icL::app

#endif  // icL_app_Helper
