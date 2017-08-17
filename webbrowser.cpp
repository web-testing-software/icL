#include "webbrowser.h"

#include <QCoreApplication>
#include <QThread>

WebBrowser::WebBrowser (QWidget *parent)
	: QMainWindow (parent) {

	// TODO: Load last size
	resize (800, 600);


	// I don't use a qt quick window because it can't be move be mouse by default
	// This is necessary for frameless window
	QUrl source_mainqml ("qrc:/main.qml");
	quick_receiver = new QQuickWidget (source_mainqml);
	quick_receiver->setResizeMode (QQuickWidget::SizeRootObjectToView);

	setCentralWidget (quick_receiver);
	// TODO: Make configurable: Use system window frame
	setWindowFlags (windowFlags () | Qt::FramelessWindowHint);
}

WebBrowser::~WebBrowser () {

}

bool WebBrowser::simulate_click (int x, int y) {
	if (x < m_webEngineX ||
		y < m_webEngineY ||
		x >= m_webEngineX + m_webEngineWidth ||
		y >= m_webEngineY + m_webEngineHeight) {
		return false;
	}

	QPoint point (x, y);

//	The click event is a series of press and release of left mouse button

	QMouseEvent *press = new QMouseEvent (QEvent::MouseButtonPress,
										  point,
										  Qt::LeftButton,
										  Qt::MouseButton::NoButton,
										  Qt::NoModifier);
	QMouseEvent *release = new QMouseEvent (QEvent::MouseButtonRelease,
											point,
											Qt::LeftButton,
											Qt::MouseButton::NoButton,
											Qt::NoModifier);

	QCoreApplication::postEvent (this->quick_receiver, press);
	// TODO: Make the delay configurable
	QThread::msleep (300);
	QCoreApplication::postEvent (this->quick_receiver, release);
}

void WebBrowser::simulate_key (Qt::Key key, Qt::KeyboardModifier modifier, const QString &text) {
	QKeyEvent *press		= new QKeyEvent (QEvent::KeyPress, key, modifier, text);
	QKeyEvent *release	= new QKeyEvent (QEvent::KeyRelease, key, modifier, text);

	QCoreApplication::postEvent (this->quick_receiver, press);
	// TODO: Make the delay configurable
	QThread::msleep (60);
	QCoreApplication::postEvent (this->quick_receiver, release);
}

void WebBrowser::setWebEngineX (int webEngineX) {
	m_webEngineX = webEngineX;
}

void WebBrowser::setWebEngineY (int webEngineY) {
	m_webEngineY = webEngineY;
}

void WebBrowser::setWebEngineWidth (int webEngineWidth) {
	m_webEngineWidth = webEngineWidth;
}

void WebBrowser::setWebEngineHeight (int webEngineHeight) {
	m_webEngineHeight = webEngineHeight;
}
