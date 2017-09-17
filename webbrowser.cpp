#include "webbrowser.h"
#include "cpp_backend/functions/server.h"

#include <QCoreApplication>
#include <QQmlContext>
#include <QThread>

WebBrowser *WebBrowser::m_instance = nullptr;

WebBrowser::WebBrowser (QWidget *parent)
	: QMainWindow (parent) {

	if (m_instance == nullptr) {
		m_instance = this;
	}

	// TODO: Load last size
	resize (800, 600);


	// I don't use a qt quick window because it can't be move be mouse by default
	// This is necessary for frameless window
	QUrl source_mainqml ("qrc:/main.qml");
	quick_receiver = new QQuickWidget (source_mainqml);
	quick_receiver->setResizeMode (QQuickWidget::SizeRootObjectToView);
//	qApp->

	// Export the singletons to QML
	QQmlContext *context = quick_receiver->rootContext ();

	context->setContextProperty ("server", server);
	context->setContextProperty ("browser", browser);

	setCentralWidget (quick_receiver);
	// TODO: Make configurable: Use system window frame
//	setWindowFlags (windowFlags () | Qt::FramelessWindowHint);
}

WebBrowser::~WebBrowser () {

}

void WebBrowser::get (const QString &url) {
	// TODO: Write this function
}

void WebBrowser::waitForPageLoading () {
	// TODO: Write this function
}

void WebBrowser::runJS (const QString &code) {
	// TODO: Write this function
}

bool WebBrowser::simulate_click (int x, int y) {
	if (x < m_webEngineX ||
		y < m_webEngineY ||
		x >= m_webEngineX + m_webEngineWidth ||
		y >= m_webEngineY + m_webEngineHeight) {
		return false;
	}

	QPoint point (x + m_webEngineX, y + m_webEngineY);

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
	QKeyEvent	*press		= new QKeyEvent (QEvent::KeyPress, key, modifier, text);
	QKeyEvent	*release	= new QKeyEvent (QEvent::KeyRelease, key, modifier, text);

	QCoreApplication::postEvent (this->quick_receiver, press);
	// TODO: Make the delay configurable
	QThread::msleep (60);
	QCoreApplication::postEvent (this->quick_receiver, release);
}

WebBrowser * WebBrowser::instance () {
	return m_instance;
}

int WebBrowser::webEngineHeight () const {
	return m_webEngineHeight;
}

int WebBrowser::webEngineX () const {
	return m_webEngineX;
}

int WebBrowser::webEngineY () const {
	return m_webEngineY;
}

int WebBrowser::webEngineWidth () const {
	return m_webEngineWidth;
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
