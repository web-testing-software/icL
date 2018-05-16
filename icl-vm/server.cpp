#include "server.h"

#include <utility>

#include <QStringList>
#include <QThread>


namespace icL {

Server::Server(memory::InterLevel * il, QObject * parent)
	: QObject(parent)
	, memory::Node(il) {

	connect(this, &Server::invoke_executeJS, this, &Server::release_executeJS);
	connect(this, &Server::invoke_goTo, this, &Server::release_goTo);
	connect(
	  this, &Server::invoke_waitForPageLoading, this,
	  &Server::release_waitForPageLoading);
	connect(
	  this, &Server::invoke_showErrorDialog, this,
	  &Server::release_showErrorDialog);
}

bool Server::goTo(const QString & url) {
	if (waitFor != WaitFor::Nothing) {
		return false;
	}

	waitFor   = WaitFor::GoTo;
	working   = true;
	this->url = url;

	emit invoke_goTo();
	while (working) {
		;
	}
	return variant.toBool();
}

bool Server::waitForPageLoading() {
	if (waitFor != WaitFor::Nothing) {
		return false;
	}

	waitFor = WaitFor::PageLoading;
	working = true;

	emit invoke_waitForPageLoading();
	while (working) {
		;
	}

	return variant.toBool();
}

QVariant Server::executeJS(const QString & code) {
	if (waitFor != WaitFor::Nothing) {
		return false;
	}

	waitFor    = WaitFor::ExecuteJS;
	working    = true;
	this->code = code;

	emit invoke_executeJS();
	while (working) {
		;
	}
	return variant;
}


void Server::finish_PageLoading(bool success) {
	if (waitFor == WaitFor::GoTo || waitFor == WaitFor::PageLoading) {
		variant = success;
		waitFor = WaitFor::Nothing;
		working = false;
	}
}

void Server::finish_executeJS(QVariant variant) {
	if (waitFor == WaitFor::ExecuteJS) {
		this->variant = std::move(variant);
		this->waitFor = WaitFor::Nothing;
		this->working = false;
	}
}

QQuickItem * Server::webEngine() const {
	return m_webEngine;
}

void Server::setWebEngine(QQuickItem * webEngine) {
	if (m_webEngine == webEngine) {
		return;
	}

	m_webEngine = webEngine;
	emit webEngineChanged(m_webEngine);
}

void Server::simulateClick(int x, int y) {
	// TODO: Add a coods check later
	//	if (x < m_webEngineX ||
	//			y < m_webEngineY ||
	//			x >= m_webEngineX + m_webEngineWidth ||
	//			y >= m_webEngineY + m_webEngineHeight) {
	//			return false;
	//		}

	QPoint point(x, y);

	//	The click event is a series of press and release of left mouse button

	QMouseEvent * press = new QMouseEvent(
	  QEvent::MouseButtonPress, point, Qt::LeftButton,
	  Qt::MouseButton::NoButton, Qt::NoModifier);
	QMouseEvent * release = new QMouseEvent(
	  QEvent::MouseButtonRelease, point, Qt::LeftButton,
	  Qt::MouseButton::NoButton, Qt::NoModifier);

	QCoreApplication::postEvent(m_webEngine, press);
	// TODO: Make the delay configurable
	QThread::msleep(300);
	QCoreApplication::postEvent(m_webEngine, release);
}

void Server::simulateKey(QChar & ch) {
	QKeyEvent * press =
	  new QKeyEvent(QEvent::KeyPress, Qt::Key_A, Qt::NoModifier, QString(ch));
	QKeyEvent * release =
	  new QKeyEvent(QEvent::KeyRelease, Qt::Key_A, Qt::NoModifier, QString(ch));


	QCoreApplication::postEvent(m_webEngine, press);
	// TODO: Make the delay configurable
	QThread::msleep(60);
	QCoreApplication::postEvent(m_webEngine, release);
}

void Server::release_goTo() {
	//	webBrowser->get (url);
}

void Server::release_waitForPageLoading() {
	//	webBrowser->waitForPageLoading ();
}

void Server::release_executeJS() {
	//	webBrowser->runJS (code);
}

}  // namespace icL
