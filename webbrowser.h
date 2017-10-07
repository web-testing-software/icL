#ifndef WEBBROWSER_H
#define WEBBROWSER_H

#include <QMainWindow>
#include <QQuickWidget>
#include <QWidget>

#define webBrowser WebBrowser::instance ()

/**
 * @brief The WebBrowser class - main window
 */
class WebBrowser : public QMainWindow
{
	Q_OBJECT

private:
	static WebBrowser *m_instance;

	// Write only properties, to get information from qml
	Q_PROPERTY (int webEngineX READ webEngineX WRITE setWebEngineX)
	Q_PROPERTY (int webEngineY READ webEngineY WRITE setWebEngineY)
	Q_PROPERTY (int webEngineWidth READ webEngineWidth WRITE setWebEngineWidth)
	Q_PROPERTY (int webEngineHeight READ webEngineHeight WRITE setWebEngineHeight)

public:
	WebBrowser (QWidget *parent = 0);
	~WebBrowser ();

	// Bridge functions, between C++ and QML WebEngineView

	/**
	 * @brief get - load a new web page in current tab
	 * @param url - new page url, format: user input
	 */
	void get (const QString &url);

	/**
	 * @brief waitForPageLoading - wait for page to load
	 */
	void waitForPageLoading ();

	/**
	 * @brief runJS - run JS code asyncronously
	 * @param code - code to run
	 */
	void runJS (const QString &code);

	// Simulation functions

	/**
	 * @brief emulate_click - emulate click on web engine view
	 * @param x - the x coord of the mouse
	 * @param y - the y coord of the mouse
	 * @return false if the (x,y) is out of view, true otherwise
	 */
	bool simulate_click (int x, int y);

	/**
	 * @brief emulate_key - emulate key down and up on browser window
	 * @param key - the emulatated key for QKeyEvent
	 * @param modifier - the emulated modifier for QKeyEvent
	 * @param text - the text to print on screen
	 */
	void simulate_key (Qt::Key key, Qt::KeyboardModifier modifier, const QString &text);

	// Singleton functions

	static WebBrowser* instance ();

	// Getters for properties

	int webEngineHeight () const;

	int webEngineX () const;

	int webEngineY () const;

	int webEngineWidth () const;

public slots:

	// Setters for properties

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
