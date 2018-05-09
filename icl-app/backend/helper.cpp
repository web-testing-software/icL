#include "helper.h"

#include <QDir>
#include <QStandardPaths>
#include <QtMath>

Helper::Helper (QObject *parent) : QObject (parent) {
	m_cache_dir		= QStandardPaths::writableLocation (QStandardPaths::CacheLocation);
	m_config_dir	= QStandardPaths::writableLocation (QStandardPaths::ConfigLocation);
	m_data_dir		= QStandardPaths::writableLocation (QStandardPaths::DataLocation);
}

/**
 * @brief Helper::mix - mix two colors (not linear)
 * @param color1 - first color
 * @param color2 - second color
 * @param alpha - blend coefficient
 * @return blended color
 */
QColor Helper::mix (const QColor &color1, const QColor &color2, qreal alpha) {
	int r	= color1.red ();
	int g	= color1.green ();
	int b	= color1.blue ();

	if (color1.lightness () > color2.lightness () ) {
		alpha = qSqrt (alpha);
	}
	else {
		alpha *= alpha;
	}

	QColor ret;

	ret.setRgb (r + static_cast <int> ( ( color2.red () - r ) * alpha ),
				g + static_cast <int> ( ( color2.green () - g ) * alpha ),
				b + static_cast <int> ( ( color2.blue () - b ) * alpha ) );

	return ret;
}

/**
 * @brief Helper::linearMix mix two colors (linear)
 * @param color1 - first color
 * @param color2 - second color
 * @param alpha - blend coefficient
 * @return blended color
 */
QColor Helper::linearMix (const QColor &color1, const QColor &color2, qreal alpha) {
	int		r	= color1.red ();
	int		g	= color1.green ();
	int		b	= color1.blue ();
	QColor	ret;

	ret.setRgb (r + static_cast <int> ( ( color2.red () - r ) * alpha ),
				g + static_cast <int> ( ( color2.green () - g ) * alpha ),
				b + static_cast <int> ( ( color2.blue () - b ) * alpha ) );

	return ret;
}

/**
 * @brief Helper::cacheDir - the dir to store cache
 * @param profileName - local user profile
 * @return absolute path
 */
QString Helper::cacheDir (const QString &profileName) {
	QString dirpath = m_cache_dir + "/" + profileName;

	makeDirIfNotExist (dirpath);
	return dirpath;
}


/**
 * @brief Helper::dataDir - the dir to store database
 * @param profileName - local user profile
 * @return absolute path
 */
QString Helper::dataDir (const QString &profileName) {
	QString dirpath = m_data_dir + "/" + profileName;

	makeDirIfNotExist (dirpath);
	return dirpath;
}

/**
 * @brief Helper::profileDir - the dir to store chromium data
 * @param profileName - local user profile
 * @return absolute path
 */
QString Helper::profileDir (const QString &profileName) {
	QString dirpath = m_config_dir + "/profile/" + profileName;

	makeDirIfNotExist (dirpath);
	return dirpath;
}

/**
 * @brief Helper::urlFromUserInput - this function is not aviable in QML
 * @param input - url as string (text inserted by user)
 * @return fixed url
 */
QUrl Helper::urlFromUserInput (const QString &input) {
	return QUrl::fromUserInput (input);
}

/**
 * @brief Helper::makeDirIfNotExist - make new directory if it not exist
 * @param dirpath - directory path
 */
void Helper::makeDirIfNotExist (const QString &dirpath) {
	QDir dir (dirpath);

	if (!dir.exists () ) {
		dir.mkpath (".");
	}
}
