#include "webbrowser.h"

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

bool WebBrowser::emulate_click (int x, int y) {

}

void WebBrowser::emulate_key (Qt::Key key, Qt::KeyboardModifier modifier, const QString &text) {

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
