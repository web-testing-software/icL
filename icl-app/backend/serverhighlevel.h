#ifndef SERVERHIGHLEVEL_H
#define SERVERHIGHLEVEL_H

#include <QObject>

#include <icl-vm/server.h>

namespace icL::app {

class ServerHighLevel : public QObject, public icL::Server
{
	Q_OBJECT

	Q_PROPERTY(QQuickItem * webEngine READ webEngine WRITE setWebEngine NOTIFY
																		webEngineChanged)
public:
	ServerHighLevel();

	/**
	 * @brief goTo - go to url and wait for page loading
	 * @param url - url to go, format: user input
	 * @return true if page was successful loaded, otherwise false
	 */
	virtual bool goTo(const QString & url) override;

	/**
	 * @brief waitForPageLoading - stop exeuting until the page is complete
	 * loaded
	 * @return true if page was successful loaded, otherwise false
	 */
	virtual bool waitForPageLoading() override;

	/**
	 * @brief executeJS - execute synchronously js code
	 * @param code - code to execute
	 * @return the returned value from js world
	 */
	virtual QVariant executeJS(const QString & code) override;

	void logOut(int level, const QString & message) override;

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


	// Properties

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

signals:
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

private:
	// These varibles are used to transfer data between threads
	QString      url, code;
	QVariant     variant;

	WaitFor waitFor = WaitFor::Nothing;

	// This sync variable which is used on serveral threads
	volatile bool working = false;
};

}  // namespace icL::app

#endif  // SERVERHIGHLEVEL_H
