//#include "server.h"

//#include <utility>

//#include <QStringList>
//#include <QThread>

//namespace icL {

//Server::Server(QObject * parent)
//	: QObject(parent)
//	, memory::Node(nullptr) {

//	connect(this, &Server::invoke_executeJS, this, &Server::release_executeJS);
//	connect(this, &Server::invoke_goTo, this, &Server::release_goTo);
//	connect(
//	  this, &Server::invoke_waitForPageLoading, this,
//	  &Server::release_waitForPageLoading);
//	connect(
//	  this, &Server::invoke_mouseEvent, this, &Server::release_mouseEvent);
//	connect(this, &Server::invoke_keyEvent, this, &Server::release_keyEvent);
//}

//bool Server::goTo(const QString & url) {
//	if (waitFor != WaitFor::Nothing) {
//		return false;
//	}

//	waitFor   = WaitFor::GoTo;
//	working   = true;
//	this->url = url;

//	emit invoke_goTo();
//	while (working) {
//		;
//	}

//	QThread::msleep(150);
//	return variant.toBool();
//}

//bool Server::waitForPageLoading() {
//	if (waitFor != WaitFor::Nothing) {
//		return false;
//	}

//	waitFor = WaitFor::PageLoading;
//	working = true;

//	emit invoke_waitForPageLoading();
//	while (working) {
//		;
//	}

//	return variant.toBool();
//}

//QVariant Server::executeJS(const QString & code) {
//	if (waitFor != WaitFor::Nothing) {
//		return false;
//	}

//	waitFor    = WaitFor::ExecuteJS;
//	working    = true;
//	this->code = code;

//	emit invoke_executeJS();
//	while (working) {
//		;
//	}
//	return variant;
//}


//void Server::finish_PageLoading(bool success) {
//	if (waitFor == WaitFor::GoTo || waitFor == WaitFor::PageLoading) {
//		variant = success;
//		waitFor = WaitFor::Nothing;
//		working = false;
//	}
//}

//void Server::finish_executeJS(QVariant variant) {
//	if (waitFor == WaitFor::ExecuteJS) {
//		this->variant = std::move(variant);
//		this->waitFor = WaitFor::Nothing;
//		this->working = false;
//	}
//}

//QQuickItem * Server::webEngine() const {
//	return m_webEngine;
//}

//void Server::setInterlevel(memory::InterLevel * il) {
//	this->il = il;
//}

//void Server::setWebEngine(QQuickItem * webEngine) {
//	if (m_webEngine == webEngine) {
//		return;
//	}

//	m_webEngine = webEngine;
//	emit webEngineChanged(m_webEngine);
//}

//void Server::simulateClick(int x, int y) {
//	QPoint point(x, y);

//	qDebug() << x << y << point;

//	//	The click event is a series of press and release of left mouse button

//	QMouseEvent * press = new QMouseEvent(
//	  QEvent::MouseButtonPress, point, Qt::LeftButton,
//	  Qt::MouseButton::NoButton, Qt::NoModifier);
//	QMouseEvent * release = new QMouseEvent(
//	  QEvent::MouseButtonRelease, point, Qt::LeftButton,
//	  Qt::MouseButton::NoButton, Qt::NoModifier);

//	emit invoke_mouseEvent(press);
//	// TODO: Make the delay configurable
//	QThread::msleep(280);
//	emit invoke_mouseEvent(release);
//	QThread::msleep(200);
//}

//void Server::simulateKey(const QChar & ch) {
//	QKeyEvent * press =
//	  new QKeyEvent(QEvent::KeyPress, Qt::Key_A, Qt::NoModifier, QString(ch));
//	QKeyEvent * release =
//	  new QKeyEvent(QEvent::KeyRelease, Qt::Key_A, Qt::NoModifier, QString(ch));

//	emit invoke_keyEvent(press);
//	// TODO: Make the delay configurable
//	QThread::msleep(50);
//	emit invoke_keyEvent(release);
//	QThread::msleep(10);
//}

//QVariant Server::runJS(const QString & code) {
//	return executeJS(code);
//}

//bool Server::click(int x, int y) {
//	if (
//	  x < 0 || y < 0 || x >= m_webEngine->width() ||
//	  y >= m_webEngine->height()) {
//		return false;
//	}

//	simulateClick(x, y);
//	return true;
//}

//void Server::keys(const QString & keys) {
//	for (const QChar & ch : keys) {
//		simulateKey(ch);
//	}
//}

//void Server::newLog(int level, const QString & message) {
//	qDebug() << level << message;

//	emit request_LogOut(level, message);
//}

//bool Server::get(const QString & url) {
//	return goTo(url);
//}

//void Server::release_goTo() {
//	emit request_UrlLoad(url);
//}

//void Server::release_waitForPageLoading() {
//	// Noting to do, just wait
//}

//void Server::release_executeJS() {
//	emit request_JsRun(code);
//}

//void Server::release_mouseEvent(QMouseEvent *ev) {
//	if (m_eventHandler == nullptr) {
//		m_eventHandler = m_webEngine->childAt(0, 0);
//	}

//	QCoreApplication::postEvent(m_eventHandler, ev);
//	QCoreApplication::processEvents();
//}

//void Server::release_keyEvent(QKeyEvent * ev) {
//	if (m_eventHandler == nullptr) {
//		m_eventHandler = m_webEngine->childAt(0, 0);
//	}

//	QCoreApplication::postEvent(m_eventHandler, ev);
//}

//}  // namespace icL
