#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QQuickItem>
#include <QString>
#include <QVariant>

/**
 *  @namespace vm
 *	|- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace vm {

/**
 * @brief The Server class - class to sync two treads
 */
class Server : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QQuickItem* webEngine READ webEngine WRITE setWebEngine NOTIFY
																	   webEngineChanged)

	enum class WaitFor { GoTo, PageLoading, ExecuteJS, ErrorDialog, Nothing };

public:
	explicit Server(QObject* parent = nullptr);

	/**
	 * @brief goTo - go to url and wait for page loading
	 * @param url - url to go, format: user input
	 * @return true if page was successful loaded, otherwise false
	 */
	bool goTo(const QString& url);

	/**
	 * @brief waitForPageLoading - stop exeuting until the page is complete
	 * loaded
	 * @return true if page was successful loaded, otherwise false
	 */
	bool waitForPageLoading();

	/**
	 * @brief executeJS - execute synchronously js code
	 * @param code - code to execute
	 * @return the returned value from js world
	 */
	QVariant executeJS(const QString& code);

	/**
	 * @brief showErrorDialog - show a dialog window, which contains all occurer
	 * errors
	 * @return true if the user is agree to ignore errors, otherwise false
	 */
	bool showErrorDialog();

	/**
	 * @brief addToErrorsStack - add new error in the errors stack
	 * @param error
	 */
	void addToErrorsStack(const QString& error);

	/**
	 * @brief getErrorsStr - return errros and clear the errors stack
	 * @return all errors as string
	 */
	QString getErrorsStr();

	/**
	 * @brief instance - class Server is a singleton
	 * @return the first instance of Server
	 */
	//	static Server* instance ();

	/**
	 * @brief check_success - commom errors catching
	 * @param success - a bool to check
	 * @param func - the function name, which we get or not a error
	 */
	void check_success(bool success, const QString& func);

	// Functions to call from qml

	/**
	 * @brief finish_waitForPageLoading - called on page load finished
	 * @param success - the page was loaded successful
	 */
	Q_INVOKABLE void finish_PageLoading(bool success);
	/**
	 * @brief finish_executeJS - called on script execution end
	 * @param variant - the value returned by script
	 */
	Q_INVOKABLE void finish_executeJS(QVariant variant);
	/**
	 * @brief finish_showErrorDialog - called on user decision
	 * @param skip - true if user request to skip errors
	 */
	Q_INVOKABLE void finish_showErrorDialog(bool skip);

	/**
	 * @brief webEngine - QML use only
	 * @return WebEngineView*
	 */
	QQuickItem* webEngine() const;

public slots:
	/**
	 * @brief setWebEngine - QML use only
	 * @param WebEngineView*
	 */
	void setWebEngine(QQuickItem* webEngine);

	/**
	 * @brief simulateClick - simulate a mouse click on WebView
	 * @param x - coordinate of x axes
	 * @param y - coordinate of y axes
	 */
	void simulateClick(int x, int y);

	/**
	 * @brief simulateKeyPress - simulate of pressing and release of a key
	 * @param ch - event.text in js
	 */
	void simulateKey(QChar& ch);

signals:
	void ready();

	// Singnals to run needed function on main thread
	void invoke_goTo();
	void invoke_waitForPageLoading();
	void invoke_executeJS();
	void invoke_showErrorDialog();

	void webEngineChanged(QQuickItem* webEngine);

private slots:
	// Functions, which will be executed on main thread
	void release_goTo();
	void release_waitForPageLoading();
	void release_executeJS();
	void release_showErrorDialog();

private:
	// The stack of errors
	QStringList errors_stack;

	// These varibles are used to transfer data between threads
	QString     url, code;
	QVariant    variant;
	QQuickItem* m_webEngine;

	WaitFor waitFor = WaitFor::Nothing;

	// Configure if need to stop executing on error
	bool stop_on_error = true;

	// This sync variable which is used on serveral threads
	volatile bool working = false;
};

}  // namespace vm

#endif  // SERVER_H
