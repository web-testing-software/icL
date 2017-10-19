#include "webbrowser.h"
#include "backend/functions/server.h"

#include <QCoreApplication>
#include <QScreen>
#include <QQmlContext>
#include <QQuickItem>
#include <QQuickWindow>
#include <QThread>
#include <QDateTime>

WebBrowser *WebBrowser::m_instance = nullptr;

WebBrowser::WebBrowser (QWidget *parent)
	: QMainWindow (parent) {

	if (m_instance == nullptr) {
		m_instance = this;
	}

	// TODO: Load last size
	resize (800, 600);
	setMinimumSize (QSize (400, 400));


	// I don't use a qt quick window because it can't be move be mouse by default
	// This is necessary for frameless window
	QUrl source_mainqml ("qrc:/main.qml");
	quick_receiver = new QQuickWidget ();
	quick_receiver->setResizeMode (QQuickWidget::SizeRootObjectToView);
	quick_receiver->setClearColor (QColor (0, 0, 0, 0));

	// Export the singletons to QML
	QQmlContext *context = quick_receiver->rootContext ();

	context->setContextProperty ("server", server);
	context->setContextProperty ("web_browser", webBrowser);
//	context->setContextProperty ("qml_window", quick_receiver->quickWindow ());

	quick_receiver->setSource (source_mainqml);
	setCentralWidget (quick_receiver);
	// TODO: Make configurable: Use system window frame
	setWindowFlags (windowFlags () | Qt::FramelessWindowHint);
	setAttribute (Qt::WA_NoSystemBackground, true);
	setAttribute (Qt::WA_TranslucentBackground, true);
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

	return true;
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

bool WebBrowser::isFocused () const {
	return m_isFocused;
}

bool WebBrowser::isMaximized () const {
	return m_isMaximized;
}

void WebBrowser::beginWindowMove (int x, int y, int flag) {
	if (flag != 0x0) {
		_winBeginX		= this->x ();
		_winBeginY		= this->y ();
		_winBeginWidth	= this->width ();
		_winBeginHeight = this->height ();
		_mouseBeginX	= x;
		_mouseBeginY	= y;
		_moveFlag		= flag;
		focus_proxy		= focusProxy ();

		grabMouse ();
	}
}

bool WebBrowser::event (QEvent *event) {
	if (event->type () == QEvent::WindowActivate) {
		setIsFocused (true);
	}
	else if (event->type () == QEvent::WindowDeactivate) {
		setIsFocused (false);
	}

	return QMainWindow::event (event);
}

void WebBrowser::mouseMoveEvent (QMouseEvent *event) {
	if (_moveFlag == 0x0) {
		return;
	}

	QPointF screenPos	= event->screenPos ();
	int		dx			=  screenPos.x () - _mouseBeginX;
	int		dy			=  screenPos.y () - _mouseBeginY;
	int		newX		= _winBeginX;
	int		newY		= _winBeginY;
	int		newWidth	= _winBeginWidth;
	int		newHeight	= _winBeginHeight;

	if (_moveFlag & static_cast <int> ( MoveFlag::H_MOVE )) {
		newX += dx;
	}
	if (_moveFlag & static_cast <int> ( MoveFlag::V_MOVE )) {
		newY += dy;
	}
	if (_moveFlag & static_cast <int> ( MoveFlag::H_RESIZE )) {
		newWidth += _moveFlag & static_cast <int> ( MoveFlag::H_MOVE ) ? -dx : dx;
	}
	if (_moveFlag & static_cast <int> ( MoveFlag::V_RESIZE )) {
		newHeight += _moveFlag & static_cast <int> ( MoveFlag::V_MOVE ) ? -dy : dy;
	}

	move (newX, newY);
	resize (newWidth, newHeight);
}

void WebBrowser::mouseReleaseEvent (QMouseEvent *) {
	if (_moveFlag != 0x0) {
		_moveFlag = 0x0;
		releaseMouse ();

		// QML loss focus, return focus
		QPoint		point (0, 0);
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
		QCoreApplication::postEvent (this->quick_receiver, release);
	}
}

void WebBrowser::resizeEvent (QResizeEvent *) {
	setIsMaximized (QWidget::isMaximized ());
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

void WebBrowser::setIsFocused (bool isFocused) {
	if (m_isFocused == isFocused) {
		return;
	}

	m_isFocused = isFocused;
	emit isFocusedChanged (m_isFocused);
}

void WebBrowser::setIsMaximized (bool isMaximized) {
	if (m_isMaximized == isMaximized) {
		return;
	}

	m_isMaximized = isMaximized;
	emit isMaximizedChanged (m_isMaximized);
}

