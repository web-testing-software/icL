#include "w3c.h"

#include <QDataStream>
#include <QImage>
#include <QJsonArray>
#include <QJsonDocument>
#include <QStringBuilder>

namespace icL::driver {

W3c::W3c() {
	connect(&nm, &QNetworkAccessManager::finished, this, &W3c::finished);
}

void W3c::newLog(int level, const QString & message) {
	qDebug() << "icL log:" << level << message;
}

void W3c::newSession() {}

void W3c::deleteSession() {}

int W3c::status() {}

int W3c::implicitTimeout() {}

int W3c::pageLoadTimeout() {}

int W3c::scriptTimeout() {}

void W3c::setImplicitTimeout(int ms) {}

void W3c::setPageLoadTimeOut(int ms) {}

void W3c::setScriptTimeout(int ms) {}

void W3c::switchSessionTo(const QString & sessionId) {}

QList<memory::Session> W3c::sessions() {}

void W3c::setUrl(const QString & url) {}

QString W3c::url() {}

bool W3c::canGoBack() {}

void W3c::back() {}

bool W3c::canGoForward() {}

void W3c::forward() {}

void W3c::refresh() {}

QString W3c::title() {}

QString W3c::window() {}

void W3c::closeWindow() {}

void W3c::focusWindow(const QString & id) {}

QStringList W3c::windows() {}

void W3c::switchToFrame(int id) {}

void W3c::switchtoFrame(memory::WebElement * el) {}

void W3c::switchToParent() {}

QRect W3c::windowRect() {}

void W3c::setWindowRect(const QRect & rect) {}

void W3c::maximize() {}

void W3c::minimize() {}

void W3c::fullscreen() {}

void W3c::restore() {}

memory::WebElement * W3c::findCssSelector(
  memory::WebElement * element, const QString & s) {}

memory::WebElement * W3c::findLinkText(
  memory::WebElement * element, const QString & text) {}

memory::WebElement * W3c::findPLinkText(
  memory::WebElement * element, const QString & text) {}

memory::WebElement * W3c::findTagName(
  memory::WebElement * element, const QString & tag) {}

memory::WebElement * W3c::findXpath(
  memory::WebElement * element, const QString & xpath) {}

memory::WebElement * W3c::allCssSelector(
  memory::WebElement * element, const QString & s) {}

memory::WebElement * W3c::allLinkText(
  memory::WebElement * element, const QString & text) {}

memory::WebElement * W3c::allPLinkText(
  memory::WebElement * element, const QString & text) {}

memory::WebElement * W3c::allTagName(
  memory::WebElement * element, const QString & tag) {}

memory::WebElement * W3c::allXpath(
  memory::WebElement * element, const QString & xpath) {}

memory::WebElement * W3c::active() {}

bool W3c::selected(memory::WebElement * el) {}

QVariant W3c::attribute(memory::WebElement * el, const QString & name) {}

QVariant W3c::property(memory::WebElement * el, const QString & name) {}

QVariant W3c::css(memory::WebElement * el, const QString & name) {}

QVariant W3c::text(memory::WebElement * el) {}

QVariant W3c::name(memory::WebElement * el) {}

QRect W3c::rect(memory::WebElement * el) {}

bool W3c::enabled(memory::WebElement * el) {}

void W3c::click(memory::WebElement * el) {}

void W3c::clear(memory::WebElement * el) {}

void W3c::value(memory::WebElement * el, const QString & val) {}

void W3c::paste(memory::WebElement * el, const QString & val) {}

QString W3c::source() {}

QVariant W3c::executeSync(const QString & code, const QVariantList & args) {}

void W3c::executeAsync(const QString & code, const QVariantList & args) {}

QVariant W3c::executeJs(const QString & code) {}

QJsonArray W3c::cookies() {}

QJsonObject W3c::cookie(const QString & name) {}

void W3c::udpCookie(const QString & name, QJsonObject obj) {}

void W3c::deleteCookie(const QString & name) {}

void W3c::deleteAllCookies() {}

void W3c::alertDimiss() {}

void W3c::alertAccept() {}

QString W3c::alertText() {}

void W3c::alertSendText(const QString & text) {}

QImage W3c::screenshot() {}

QImage W3c::screenshot(memory::WebElement * el) {}

memory::WebElement * W3c::at(memory::WebElement * el, int n) {}

memory::WebElement * W3c::filter(
  memory::WebElement * el, const QString & selector) {}

memory::WebElement * W3c::contains(
  memory::WebElement * el, const QString & _template) {}

memory::WebElement * W3c::next(memory::WebElement * el) {}

memory::WebElement * W3c::prev(memory::WebElement * el) {}

memory::WebElement * W3c::parent(memory::WebElement * el) {}

memory::WebElement * W3c::child(memory::WebElement * el, int n) {}

memory::WebElement * W3c::closest(
  memory::WebElement * el, const QString & selector) {}

void W3c::toTabByName(const QString & _template) {}

void W3c::toTabByName(const QRegExp & regexp) {}

void W3c::toTabByUrl(const QString & _template) {}

void W3c::toTabByUrl(const QRegExp & regexp) {}

void W3c::toTabByIndex(int index) {}

void W3c::closeAllTabs() {}

void W3c::closeTabsToTheRight() {}

void W3c::closeOtherTabs() {}

void W3c::closeTabsByName(const QString & _template) {}

void W3c::closeTabsByName(const QRegExp & regexp) {}

void W3c::closeTabsByUrl(const QString & _template) {}

void W3c::closeTabsByUrl(const QRegExp & regexp) {}

void W3c::closeTab() {}

void W3c::newTab() {}

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
