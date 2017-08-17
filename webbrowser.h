#ifndef WEBBROWSER_H
#define WEBBROWSER_H

#include <QMainWindow>
#include <QQuickWidget>
#include <QWidget>

/**
 * @brief The WebBrowser class - main window
 */
class WebBrowser : public QMainWindow
{
	Q_OBJECT

	// Write only properties, to get information from qml
	Q_PROPERTY (int webEngineX WRITE setWebEngineX)
	Q_PROPERTY (int webEngineY WRITE setWebEngineY)
	Q_PROPERTY (int webEngineWidth WRITE setWebEngineWidth)
	Q_PROPERTY (int webEngineHeight WRITE setWebEngineHeight)

public:
	WebBrowser (QWidget *parent = 0);
	~WebBrowser ();

	/**
	 * @brief emulate_click - emulate click on web engine view
	 * @param x - the x coord of the mouse
	 * @param y - the y coord of the mouse
	 * @return false if the (x,y) is out of view, true otherwise
	 */
	bool emulate_click (int x, int y);

	/**
	 * @brief emulate_key - emulate key down and up on browser window
	 * @param key - the emulatated key for QKeyEvent
	 * @param modifier - the emulated modifier for QKeyEvent
	 * @param text - the text to print on screen
	 */
	void emulate_key (Qt::Key key, Qt::KeyboardModifier modifier, const QString &text);

public slots:

	// Setters for write only properties

	void setWebEngineX (int webEngineX);

	void setWebEngineY (int webEngineY);

	void setWebEngineWidth (int webEngineWidth);

	void setWebEngineHeight (int webEngineHeight);

private:
	QQuickWidget *quick_receiver;

	int m_webEngineX;
	int m_webEngineY;
	int m_webEngineWidth;
	int m_webEngineHeight;
};

#endif // WEBBROWSER_H
