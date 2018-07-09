#include "w3c.h"

#include <QDataStream>
#include <QJsonDocument>
#include <QStringBuilder>

namespace icL::driver {

W3c::W3c() {
	connect(&nm, &QNetworkAccessManager::finished, this, &W3c::finished);
}

void W3c::sendError(QJsonObject & obj) {
	il->vm->exception({-7575, "Undefined error;"});
	qDebug() << obj;
}

QJsonObject W3c::_get(const QString & url) {
	wait = true;
	nm.get(QNetworkRequest(QUrl(base_url % "/session/" % session_id)));

	while (wait) {
		// wainting
	}

	return _return;
}

QJsonObject W3c::_delete(const QString & url) {
	wait = true;
	nm.deleteResource(
	  QNetworkRequest(QUrl(base_url % "/session/" % session_id)));

	while (wait) {
		// wainting
	}

	return _return;
}

QJsonObject W3c::_post(const QString & url, QJsonObject & obj) {
	QJsonDocument doc;

	doc.setObject(obj);
	wait = true;
	nm.post(
	  QNetworkRequest(QUrl(base_url % "/session/" % session_id)), doc.toJson());

	while (wait) {
		// wainting
	}

	return _return;
}

void W3c::finished(QNetworkReply * reply) {
	if (
	  reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() !=
	  200) {
		il->vm->exception(
		  {-7575, "HTTP Request error: " % reply->errorString()});
		finish(reply);
		return;
	}

	QJsonDocument   doc;
	QJsonParseError parseError;
	QTextStream     stream(reply);

	doc.fromJson(stream.readAll().toUtf8(), &parseError);

	if (parseError.error != QJsonParseError::NoError) {
		il->vm->exception({-7575, "Failed to parse reply:" % stream.readAll() %
									"\nError: " % parseError.errorString()});
		finish(reply);
		return;
	}

	finish(reply);
	_return = doc.object();
}

void W3c::finish(QNetworkReply * reply) {
	_return = {};
	wait    = false;
	reply->deleteLater();
}

}  // namespace icL::driver
