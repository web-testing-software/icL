#include "helper.h"

#include <QDir>
#include <QStandardPaths>
#include <QtMath>

Helper::Helper (QObject *parent) : QObject (parent) {
	m_cache_dir		= QStandardPaths::writableLocation (QStandardPaths::CacheLocation);
	m_config_dir	= QStandardPaths::writableLocation (QStandardPaths::ConfigLocation);
	m_data_dir		= QStandardPaths::writableLocation (QStandardPaths::DataLocation);
}

QColor Helper::mix (QColor color1, QColor color2, qreal alpha) {
	int r	= color1.red ();
	int g	= color1.green ();
	int b	= color1.blue ();

	if (color1.lightness () > color2.lightness ()) {
		alpha = qSqrt (alpha);
	}
	else {
		alpha *= alpha;
	}

	QColor ret;

	ret.setRgb (r + ( color2.red () - r ) * alpha,
				g + ( color2.green () - g ) * alpha,
				b + ( color2.blue () - b ) * alpha);

	return ret;
}

QColor Helper::linearMix (QColor color1, QColor color2, qreal alpha) {
	int		r	= color1.red ();
	int		g	= color1.green ();
	int		b	= color1.blue ();
	QColor	ret;

	ret.setRgb (r + ( color2.red () - r ) * alpha,
				g + ( color2.green () - g ) * alpha,
				b + ( color2.blue () - b ) * alpha);

	return ret;
}

QString Helper::cacheDir (const QString &profileName) {
	QString dirpath = m_cache_dir + "/" + profileName;

	makeDirIfNotExist (dirpath);
	return dirpath;
}

QString Helper::dataDir (const QString &profileName) {
	QString dirpath = m_data_dir + "/" + profileName;

	makeDirIfNotExist (dirpath);
	return dirpath;
}

QString Helper::profileDir (const QString &profileName) {
	QString dirpath = m_config_dir + "/profile/" + profileName;

	makeDirIfNotExist (dirpath);
	return dirpath;
}

QUrl Helper::urlFromUserInput (const QString &input) {
	return QUrl::fromUserInput (input);
}

void Helper::makeDirIfNotExist (const QString &dirpath) {
	QDir dir (dirpath);

	if (!dir.exists ()) {
		dir.mkpath (".");
	}
}
