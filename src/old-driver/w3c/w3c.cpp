#include "w3c.h"

#include <QApplication>
#include <QClipboard>
#include <QDataStream>
#include <QImage>
#include <QJsonArray>
#include <QJsonDocument>
#include <QStringBuilder>
#include <QThread>

namespace old::driver::w3c {

W3c::W3c() {
	connect(&nm, &QNetworkAccessManager::finished, this, &W3c::finished);
}

void W3c::newLog(int level, const QString & message) {
	qDebug() << "icL log:" << level << message;
}

// Session functions

void W3c::newSession() {
	QJsonDocument doc;
	QJsonObject   body;
	QJsonObject   capabilities;
	QString       sessionId;

	if (base_url.isEmpty()) {
		il->vm->exception(
		  {-2001, "Failed to create session: W3C Driver not inited!"});
		return;
	}

	capabilities["alwaysMatch"] = QJsonObject();
	capabilities["firstMatch"]  = QJsonArray();
	body["capabilities"]        = capabilities;

	prepareToMakeSession(body);

	doc.setObject(body);
	wait = true;

	nm.post(QNetworkRequest(QUrl(base_url % "/session")), doc.toJson());

	while (wait) {
		// Wait for page to load
		QThread::msleep(1);
	}

	if (_return["value"].isObject()) {
		QJsonObject value = _return["value"].toObject();

		if (value["sessionId"].isString()) {
			sessionId = value["sessionId"].toString();

			_sessions.append(sessionId);
			session_id = sessionId;
		}
	}

	if (sessionId.isEmpty()) {
		sendError(_return);
	}
}

void W3c::deleteSession() {
	QJsonObject obj = _delete("");

	checkErrors();
}

int W3c::status() {
	wait = true;
	nm.get(QNetworkRequest(QUrl(base_url % "/status")));

	while (wait) {
		// Wait for page to load
		QThread::msleep(1);
	}

	if (_return["status"].isDouble()) {
		return _return["status"].toInt();
	}

	return -1;
}

int W3c::implicitTimeout() {
	return getTimeout("implicit");
}

int W3c::pageLoadTimeout() {
	return getTimeout("pageLoad");
}

int W3c::scriptTimeout() {
	return getTimeout("script");
}

void W3c::setImplicitTimeout(int ms) {
	setTimeout("implicit", ms);
}

void W3c::setPageLoadTimeOut(int ms) {
	setTimeout("pageLoad", ms);
}

void W3c::setScriptTimeout(int ms) {
	setTimeout("script", ms);
}

// icL sessions functions

void W3c::switchSessionTo(const QString & sessionId) {
	if (_sessions.contains(sessionId)) {
		session_id = sessionId;
	}
	else {
		il->vm->exception({-2004, "No such session " % sessionId});
	}
}

QList<memory::Session> W3c::sessions() {
	QString                current_session = session_id;
	QList<memory::Session> ret;

	for (const auto & str : _sessions) {
		memory::Session sess;

		sess.id        = str;
		session_id     = str;
		sess.tabsCount = windows().length();

		ret.append(sess);
	}

	session_id = current_session;

	return ret;
}

// Navigation functions

void W3c::setUrl(const QString & url) {
	QJsonObject request;
	QJsonObject response;

	request["url"] = url;
	response       = _post("/url", request);

	checkErrors();
}

QString W3c::url() {
	QJsonObject response = _get("/url");

	if (response["value"].isString()) {
		return response["value"].toString();
	}

	sendError(response);
	return {};
}

bool W3c::canGoBack() {
	return true;  // There is not a w3c implementation
}

void W3c::back() {
	_post("/back", {});
	checkErrors();
}

bool W3c::canGoForward() {
	return true;  // There is not a w3c implementation
}

void W3c::forward() {
	_post("/forward", {});
	checkErrors();
}

void W3c::refresh() {
	_post("/refresh", {});
	checkErrors();
}

QString W3c::title() {
	QJsonObject response = _get("/title");

	if (response["value"].isString()) {
		return response["value"].toString();
	}

	sendError(response);
	return {};
}

// Windows and frames

QString W3c::window() {
	QJsonObject response = _get("/window");

	if (response["value"].isString()) {
		return response["value"].toString();
	}

	sendError(response);
	return {};
}

void W3c::closeWindow() {
	_delete("/window");
	checkErrors();
}

void W3c::focusWindow(const QString & id) {
	QJsonObject request;

	request["handle"] = id;
	_post("/window", request);
	checkErrors();
}

QStringList W3c::windows() {
	QJsonObject response = _get("/window/handles");
	QStringList ret;

	if (response["value"].isArray()) {
		for (const auto obj : response["value"].toArray()) {
			ret.append(obj.toString());
		}
	}
	else {
		sendError(response);
	}

	return ret;
}

void W3c::switchToFrame(int id) {
	QJsonObject request;

	request["id"] = id;
	_post("/frame", request);
	checkErrors();
}

void W3c::switchtoFrame(memory::WebElement * el) {
	QJsonObject request;
	QJsonObject element;

	element[memory::W3cElement::indentifier] = el->variable();
	request["id"]                            = element;
	_post("/frame", request);
	checkErrors();
}

void W3c::switchToParent() {
	_post("/frame/parent", {});
	checkErrors();
}

// Window move and resize

QRect W3c::windowRect() {
	QJsonObject response = _get("/window/rect");

	return valueToRect(response);
}

QRect W3c::setWindowRect(const QRect & rect) {
	QJsonObject request;
	QJsonObject response;

	if (rect.x() >= 0) {
		request["x"] = rect.x();
	}

	if (rect.y() >= 0) {
		request["y"] = rect.y();
	}

	if (rect.width() >= 0) {
		request["width"] = rect.width();
	}

	if (rect.height() >= 0) {
		request["height"] = rect.height();
	}

	response = _post("/window/rect", request);

	return valueToRect(response);
}

void W3c::maximize() {
	prepareWindow();
	_post("/window/maximize", {});
	checkErrors();
}

void W3c::minimize() {
	prepareWindow();
	_post("/window/minimize", {});
	checkErrors();
}

void W3c::fullscreen() {
	prepareWindow();
	_post("/window/fullscreen", {});
	checkErrors();
}

void W3c::restore() {
	setWindowRect(last_win_rect);
	win_normal_mode = true;
}

// Find elements

memory::WebElement * W3c::findCssSelector(
  memory::WebElement * element, const QString & s) {
	return findElement(element, "css selector", s);
}

memory::WebElement * W3c::findLinkText(
  memory::WebElement * element, const QString & text) {
	return findElement(element, "link text", text);
}

memory::WebElement * W3c::findPLinkText(
  memory::WebElement * element, const QString & text) {
	return findElement(element, "partial link text", text);
}

memory::WebElement * W3c::findTagName(
  memory::WebElement * element, const QString & tag) {
	return findElement(element, "tag name", tag);
}

memory::WebElement * W3c::findXpath(
  memory::WebElement * element, const QString & xpath) {
	return findElement(element, "xpath", xpath);
}

memory::WebElement * W3c::allCssSelector(
  memory::WebElement * element, const QString & s) {
	return findElements(element, "css selector", s);
}

memory::WebElement * W3c::allLinkText(
  memory::WebElement * element, const QString & text) {
	return findElements(element, "link text", text);
}

memory::WebElement * W3c::allPLinkText(
  memory::WebElement * element, const QString & text) {
	return findElements(element, "partial link text", text);
}

memory::WebElement * W3c::allTagName(
  memory::WebElement * element, const QString & tag) {
	return findElements(element, "tag name", tag);
}

memory::WebElement * W3c::allXpath(
  memory::WebElement * element, const QString & xpath) {
	return findElements(element, "xpath", xpath);
}

// Elements manipulation

memory::WebElement * W3c::active() {
	QJsonObject          response = _get("/element/active");
	memory::W3cElement * ret      = new memory::W3cElement;

	if (response["value"].isObject()) {
		QJsonObject value = response["value"].toObject();

		if (value[memory::W3cElement::indentifier].isString()) {
			ret->variables.append(
			  value[memory::W3cElement::indentifier].toString());
		}
	}

	return ret;
}

bool W3c::selected(memory::WebElement * el) {
	return elementHttpBool(el, "/selected");
}

QVariant W3c::attribute(memory::WebElement * el, const QString & name) {
	return elementHttpText(el, "/attribute/" % name);
}

QVariant W3c::property(memory::WebElement * el, const QString & name) {
	QJsonObject   response = elementHttp(el, "/property/" % name);
	QJsonValueRef value    = response["value"];

	return valueToVariant(value);
}

QVariant W3c::css(memory::WebElement * el, const QString & name) {
	return elementHttpText(el, "/css/" % name);
}

QVariant W3c::text(memory::WebElement * el) {
	return elementHttpText(el, "/text");
}

QVariant W3c::name(memory::WebElement * el) {
	return elementHttpText(el, "/name");
}

QRect W3c::rect(memory::WebElement * el) {
	return valueToRect(elementHttp(el, "/rect"));
}

bool W3c::enabled(memory::WebElement * el) {
	return elementHttpBool(el, "/enabled");
}

void W3c::click(memory::WebElement * el) {
	elementHttp(el, "/click", true);
	checkErrors();
}

void W3c::clear(memory::WebElement * el) {
	elementHttp(el, "/clear", true);
	checkErrors();
}

void W3c::value(memory::WebElement * el, const QString & val) {
	QJsonObject request;

	request["value"] = val;
	_post("/element/" % el->variable() % "/value", request);

	checkErrors();
}

void W3c::paste(memory::WebElement * el, const QString & val) {
	QApplication::clipboard()->setText(val);

	value(el, "\uE009V");  // send Ctrl+V
}

// document

QString W3c::source() {
	QJsonObject response = _get("/source");

	if (response["value"].isString()) {
		return response["value"].toString();
	}

	return {};
}

QVariant W3c::executeSync(const QString & code, const QVariantList & args) {
	//
}

void W3c::executeAsync(const QString & code, const QVariantList & args) {}

QVariant W3c::executeJs(const QString & code) {}

// cookie

QJsonArray W3c::cookies() {}

QJsonObject W3c::cookie(const QString & name) {}

void W3c::udpCookie(QJsonObject obj) {}

void W3c::deleteCookie(const QString & name) {}

void W3c::deleteAllCookies() {}

// Alert

void W3c::alertDimiss() {}

void W3c::alertAccept() {}

QString W3c::alertText() {}

void W3c::alertSendText(const QString & text) {}

// Screenshots

QImage W3c::screenshot() {}

QImage W3c::screenshot(memory::WebElement * el) {}

// icL additional methods

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

// icL tabs interface

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

// protected functions

void W3c::sendError(const QJsonObject & obj) {
	il->vm->exception({-7575, "Undefined error;"});
	qDebug() << obj;
}

QJsonObject W3c::_get(const QString & url) {
	if (session_id.isEmpty()) {
		il->vm->exception({-2002, "No current session: GET request to `" % url %
		                            "` was canceled."});
		return {};
	}

	wait = true;
	nm.get(QNetworkRequest(QUrl(base_url % "/session/" % session_id)));

	while (wait) {
		// wainting
		QThread::msleep(1);
	}

	return _return;
}

QJsonObject W3c::_delete(const QString & url) {
	if (session_id.isEmpty()) {
		il->vm->exception({-2002, "No current session: DELETE request to `" %
		                            url % "` was canceled."});
		return {};
	}

	wait = true;
	nm.deleteResource(
	  QNetworkRequest(QUrl(base_url % "/session/" % session_id)));

	while (wait) {
		// wainting
		QThread::msleep(1);
	}

	return _return;
}

QJsonObject W3c::_post(const QString & url, const QJsonObject & obj) {
	if (session_id.isEmpty()) {
		il->vm->exception({-2002, "No current session: GET request to `" % url %
		                            "` was canceled."});
		return {};
	}

	QJsonDocument doc;

	doc.setObject(obj);
	wait = true;
	nm.post(
	  QNetworkRequest(QUrl(base_url % "/session/" % session_id)), doc.toJson());

	while (wait) {
		// wainting
		QThread::msleep(1);
	}

	return _return;
}

int W3c::getTimeout(const QString & name) {

	QJsonObject obj = _get("/timeouts");
	int         ret = -1;

	if (obj["value"].isObject()) {
		QJsonObject value = obj["value"].toObject();

		if (value[name].isDouble()) {
			ret = value[name].toInt();
		}
	}

	if (ret == -1) {
		il->vm->exception({-2003, "Failed to extract timeout " % name});
	}

	return ret;
}

void W3c::setTimeout(const QString & name, int value) {
	QJsonObject request;
	QJsonObject response;

	request["implicit"] = value;
	response            = _post("/timeouts", request);

	if (!response["value"].isNull()) {
		sendError(response);
	}
}

QRect W3c::valueToRect(const QJsonObject & obj) {
	if (obj["value"].isObject()) {
		QJsonObject value = obj["value"].toObject();

		if (
		  value["x"].isDouble() && value["y"].isDouble() &&
		  value["width"].isDouble() && value["height"].isDouble()) {
			QRect ret;

			ret.setX(value["x"].toInt());
			ret.setY(value["y"].toInt());
			ret.setWidth(value["width"].toInt());
			ret.setHeight(value["height"].toInt());

			return ret;
		}
	}

	sendError(obj);
	return {};
}

void W3c::prepareWindow() {
	if (win_normal_mode) {
		last_win_rect   = windowRect();
		win_normal_mode = false;
	}
}

memory::WebElement * W3c::findElement(
  memory::WebElement * el, const QString & by, const QString & value) {
	QString              url;
	QJsonObject          request;
	QJsonObject          response;
	memory::W3cElement * ret = new memory::W3cElement;

	if (el == nullptr) {
		url = "/element";
	}
	else {
		url = "/element/" % el->variable() % "/element";
	}

	request["using"] = by;
	request["value"] = value;

	response = _post(url, request);

	if (response["value"].isObject()) {
		QJsonObject value = response["value"].toObject();

		if (value[memory::W3cElement::indentifier].isString()) {
			ret->variables.append(
			  value[memory::W3cElement::indentifier].toString());
		}
	}

	return ret;
}

memory::WebElement * W3c::findElements(
  memory::WebElement * el, const QString & by, const QString & value) {
	QString              url;
	QJsonObject          request;
	QJsonObject          response;
	memory::W3cElement * ret = new memory::W3cElement;

	if (el == nullptr) {
		url = "/elements";
	}
	else {
		url = "/element/" % el->variable() % "/elements";
	}

	request["using"] = by;
	request["value"] = value;

	response = _post(url, request);

	if (response["value"].isArray()) {
		for (const auto & ref : response["value"].toArray()) {
			QJsonObject value = ref.toObject();

			if (value[memory::W3cElement::indentifier].isString()) {
				ret->variables.append(
				  value[memory::W3cElement::indentifier].toString());
			}
		}
	}

	return ret;
}

QJsonObject W3c::elementHttp(
  memory::WebElement * el, const QString & url, bool post) {
	QString url2 = "/element/" % el->variable() % url;

	if (post) {
		return _post(url2, {});
	}

	return _get(url2);
}

QString W3c::elementHttpText(memory::WebElement * el, const QString & url) {
	QJsonObject response = elementHttp(el, url);

	if (response["value"].isString()) {
		return response["value"].toString();
	}

	return {};
}

bool W3c::elementHttpBool(memory::WebElement * el, const QString & url) {
	QJsonObject response = elementHttp(el, url);

	if (response["value"].isBool()) {
		return response["value"].toBool();
	}

	return false;
}

QVariant W3c::valueToVariant(QJsonValueRef & value) {
	if (value.isNull()) {
		return {};
	}
	else if (value.isBool() || value.isDouble() || value.isString()) {
		return value.toVariant();
	}
	else if (value.isArray()) {
		QStringList list;

		for (const auto & ref : value.toArray()) {
			if (ref.isString()) {
				list.append(ref.toString());
			}
			else {
				list.clear();
				break;
			}
		}

		// If no errors ocurrer
		if (!list.isEmpty() || value.toArray().isEmpty()) {
			return list;
		}
	}

	return {};
}

QJsonValue W3c::variantToValue(QVariant var) {
	//
}

bool W3c::checkErrors() {
	if (!_return["value"].isNull()) {
		sendError(_return);
		return true;
	}

	return false;
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
		il->vm->exception({-2000, "Failed to parse reply:" % stream.readAll() %
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

}  // namespace old::driver::w3c
