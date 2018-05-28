#ifndef icL_Server
#define icL_Server

#include <icl-memory/interlevel/interfaces.h>
#include <icl-memory/interlevel/interlevel.h>
#include <icl-memory/interlevel/node.h>

#include <QObject>
#include <QQuickItem>
#include <QString>
#include <QVariant>

/**
 * > icL
 *  |- app
 *  |- context
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
namespace icL {

/**
 * @brief The Server class - class to sync two treads
 */
class Server
	: public QObject
	, public memory::Node
	, public memory::Server
{
	Q_OBJECT

	Q_PROPERTY(QQuickItem * webEngine READ webEngine WRITE setWebEngine NOTIFY
																		webEngineChanged)

	enum class WaitFor { GoTo, PageLoading, ExecuteJS, ErrorDialog, Nothing };

public:
	explicit Server(memory::InterLevel * il, QObject * parent = nullptr);

	/**
	 * @brief goTo - go to url and wait for page loading
	 * @param url - url to go, format: user input
	 * @return true if page was successful loaded, otherwise false
	 */
	bool goTo(const QString & url);

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
	QVariant executeJS(const QString & code);

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
	 * @brief webEngine - QML use only
	 * @return WebEngineView*
	 */
	QQuickItem * webEngine() const;

public slots:
	/**
	 * @brief setWebEngine - QML use only
	 * @param WebEngineView*
	 */
	void setWebEngine(QQuickItem * webEngine);

protected:
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
	void simulateKey(const QChar & ch);

private:
	// memory.Server interface
	virtual QVariant runJS(const QString & code);
	virtual bool     click(int x, int y);
	virtual void     keys(const QString & keys);
	virtual void     newLog(int level, const QString & message);
	virtual bool     get(const QString & url);

signals:
	void ready();

	// Singnals to run needed function on main thread
	void invoke_goTo();
	void invoke_waitForPageLoading();
	void invoke_executeJS();
	void invoke_showErrorDialog();

	void webEngineChanged(QQuickItem * webEngine);

	// signals for QML
	void request_UrlLoad(const QString & url);
	void request_JsRun(const QString & code);
	void request_LogOut(int level, const QString & mess);

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
	QString      url, code;
	QVariant     variant;
	QQuickItem * m_webEngine;

	WaitFor waitFor = WaitFor::Nothing;

	// This sync variable which is used on serveral threads
	volatile bool working = false;
};

}  // namespace icL

#endif  // icL_Server
