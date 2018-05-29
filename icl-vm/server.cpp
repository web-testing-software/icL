#include "server.h"

#include <utility>

#include <QStringList>
#include <QThread>


namespace icL {

Server::Server()
	: memory::Node(nullptr) {
}

Server::~Server() {
	// Nothing to free
}

void Server::setInterlevel(memory::InterLevel * il) {
	this->il = il;
}

void Server::simulateClick(int x, int y) {
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

void Server::simulateKey(const QChar & ch) {
	QKeyEvent * press =
	  new QKeyEvent(QEvent::KeyPress, Qt::Key_A, Qt::NoModifier, QString(ch));
	QKeyEvent * release =
	  new QKeyEvent(QEvent::KeyRelease, Qt::Key_A, Qt::NoModifier, QString(ch));


	QCoreApplication::postEvent(m_webEngine, press);
	// TODO: Make the delay configurable
	QThread::msleep(60);
	QCoreApplication::postEvent(m_webEngine, release);
}

QVariant Server::runJS(const QString & code) {
	return executeJS(code);
}

bool Server::click(int x, int y) {
	if (
	  x < 0 || y < 0 || x >= m_webEngine->width() ||
	  y >= m_webEngine->height()) {
		return false;
	}

	simulateClick(x, y);
	return true;
}

void Server::keys(const QString & keys) {
	for (const QChar & ch : keys) {
		simulateKey(ch);
	}
}

void Server::newLog(int level, const QString & message) {
	logOut(level, message);
}

bool Server::get(const QString & url) {
	return goTo(url);
}

}  // namespace icL
