#ifndef icL_driver_w3c_W3C
#define icL_driver_w3c_W3C

#include <icl-memory/interlevel/interfaces.h>
#include <icl-memory/interlevel/node.h>

#include <QJsonObject>
#include <QNetworkReply>
#include <QObject>
#include <QRect>
#include <QSslError>

/**
 * The w3c namespace contains all realisations of W3C webdriver API
 */
namespace icL::driver::w3c {

/**
 * \~english @brief The W3c class - Base W3C webdriver API realisation
 */
class W3c
	: public QObject
	, public memory::Node
	, public memory::Server
{
public:
	W3c();

	// memory::Server interface
public:
	void newLog(int level, const QString & message) override;

	// Session functions
	void newSession() override;
	void deleteSession() override;
	int  status() override;
	int  implicitTimeout() override;
	int  pageLoadTimeout() override;
	int  scriptTimeout() override;
	void setImplicitTimeout(int ms) override;
	void setPageLoadTimeOut(int ms) override;
	void setScriptTimeout(int ms) override;

	// icL sessions functions
	void                   switchSessionTo(const QString & sessionId) override;
	QList<memory::Session> sessions() override;

	// Navigation functions
	void    setUrl(const QString & url) override;
	QString url() override;
	bool    canGoBack() override;  // icL
	void    back() override;
	bool    canGoForward() override;  // icL
	void    forward() override;
	void    refresh() override;
	QString title() override;

	// Windows and frames
	QString     window() override;
	void        closeWindow() override;
	void        focusWindow(const QString & id) override;
	QStringList windows() override;
	void        switchToFrame(int id) override;
	void        switchtoFrame(memory::WebElement * el) override;
	void        switchToParent() override;

	// Window move and resize
	QRect windowRect() override;
	void  setWindowRect(const QRect & rect) override;
	void  maximize() override;
	void  minimize() override;
	void  fullscreen() override;
	void  restore() override;  // icL

	// Find elements
	memory::WebElement * findCssSelector(
	  memory::WebElement * element, const QString & s) override;
	memory::WebElement * findLinkText(
	  memory::WebElement * element, const QString & text) override;
	memory::WebElement * findPLinkText(
	  memory::WebElement * element, const QString & text) override;
	memory::WebElement * findTagName(
	  memory::WebElement * element, const QString & tag) override;
	memory::WebElement * findXpath(
	  memory::WebElement * element, const QString & xpath) override;
	memory::WebElement * allCssSelector(
	  memory::WebElement * element, const QString & s) override;
	memory::WebElement * allLinkText(
	  memory::WebElement * element, const QString & text) override;
	memory::WebElement * allPLinkText(
	  memory::WebElement * element, const QString & text) override;
	memory::WebElement * allTagName(
	  memory::WebElement * element, const QString & tag) override;
	memory::WebElement * allXpath(
	  memory::WebElement * element, const QString & xpath) override;

	// Elements manipulation
	memory::WebElement * active() override;
	bool                 selected(memory::WebElement * el) override;
	QVariant attribute(memory::WebElement * el, const QString & name) override;
	QVariant property(memory::WebElement * el, const QString & name) override;
	QVariant css(memory::WebElement * el, const QString & name) override;
	QVariant text(memory::WebElement * el) override;
	QVariant name(memory::WebElement * el) override;
	QRect    rect(memory::WebElement * el) override;
	bool     enabled(memory::WebElement * el) override;
	void     click(memory::WebElement * el) override;
	void     clear(memory::WebElement * el) override;
	void     value(memory::WebElement * el, const QString & val) override;
	void     paste(memory::WebElement * el, const QString & val) override;

	// document
	QString  source() override;
	QVariant executeSync(
	  const QString & code, const QVariantList & args) override;
	void executeAsync(const QString & code, const QVariantList & args) override;
	QVariant executeJs(const QString & code) override;

	// cookie
	QJsonArray  cookies() override;
	QJsonObject cookie(const QString & name) override;
	void        udpCookie(QJsonObject obj) override;
	void        deleteCookie(const QString & name) override;
	void        deleteAllCookies() override;

	// Actions
	// to be written later

	// Alert
	void    alertDimiss() override;
	void    alertAccept() override;
	QString alertText() override;
	void    alertSendText(const QString & text) override;

	// Screenshots
	QImage screenshot() override;
	QImage screenshot(memory::WebElement * el) override;

	// icL additional methods
	memory::WebElement * at(memory::WebElement * el, int n) override;
	memory::WebElement * filter(
	  memory::WebElement * el, const QString & selector) override;
	memory::WebElement * contains(
	  memory::WebElement * el, const QString & _template) override;
	memory::WebElement * next(memory::WebElement * el) override;
	memory::WebElement * prev(memory::WebElement * el) override;
	memory::WebElement * parent(memory::WebElement * el) override;
	memory::WebElement * child(memory::WebElement * el, int n) override;
	memory::WebElement * children(memory::WebElement * el) override;
	memory::WebElement * closest(
	  memory::WebElement * el, const QString & selector) override;

	// icL tabs interface
	void toTabByName(const QString & _template) override;
	void toTabByName(const QRegExp & regexp) override;
	void toTabByUrl(const QString & _template) override;
	void toTabByUrl(const QRegExp & regexp) override;
	void toTabByIndex(int index) override;
	void closeAllTabs() override;
	void closeTabsToTheRight() override;
	void closeOtherTabs() override;
	void closeTabsByName(const QString & _template) override;
	void closeTabsByName(const QRegExp & regexp) override;
	void closeTabsByUrl(const QString & _template) override;
	void closeTabsByUrl(const QRegExp & regexp) override;
	void closeTab() override;
	void newTab() override;

protected:
	/**
	 * \~english
	 * @brief sendError - process w3c errors from http response
	 * @param obj - returned JSON object by http request
	 */
	void sendError(QJsonObject & obj);

	/**
	 * \~english
	 * @brief prepareToMakeSession - prepare JSON object to be to /session
	 * @param obj - JSON object reference
	 */
	virtual void prepareToMakeSession(QJsonObject & obj) = 0;

	/**
	 * \~english
	 * @brief _get - make a get request
	 * @param url - relative URL
	 * @return response body parsed to JSON object
	 */
	QJsonObject _get(const QString & url);

	/**
	 * \~english
	 * @brief _delete - make a delete request
	 * @param url - relative URL
	 * @return response body parsed to JSON object
	 */
	QJsonObject _delete(const QString & url);

	/**
	 * \~english
	 * @brief _post - make a post request
	 * @param url - relative URL
	 * @param obj - JSON object to serialize and send like request body
	 * @return response body parsed to JSON object
	 */
	QJsonObject _post(const QString & url, QJsonObject & obj);

	/**
	 * @brief getTimeout - GET /session/{session id}/timeout
	 * @param name - name of timeout
	 * @return timeout value
	 */
	int getTimeout(const QString & name);

	/**
	 * @brief setTimeout - POST /session/{session id}/timeout
	 * @param name - name of timeout
	 * @param value - value to set
	 */
	void setTimeout(const QString & name, int value);

public slots:
	/**
	 * \~english
	 * @brief finished - triggered when a connection inited by nm finished
	 * @param reply - network HTTP reply object
	 */
	void finished(QNetworkReply * reply);

private:
	/**
	 * \~english @brief nm - automate sendind of get, post and delete http
	 * requests
	 */
	QNetworkAccessManager nm;

	/**
	 * \~english @brief base_url - {server ip}:{server port}
	 */
	QString base_url;

	/**
	 * \~english @brief session_id - current session id
	 */
	QString session_id;

	/**
	 * \~english @brief _sessions - list of all active sessions id
	 */
	QStringList _sessions;

	/**
	 * \~english @brief _return - return object from finished slot to _get,
	 * _post, _delete functions
	 */
	QJsonObject _return;

	/**
	 * \~english @brief wait - wait http request to finish, block thread
	 */
	volatile std::atomic_bool wait = false;

	/**
	 * \~english
	 * @brief finish - finish network reply processing
	 * @param reply - network reply to delete later
	 */
	void finish(QNetworkReply * reply);
};

}  // namespace icL::driver::w3c

#endif  // icL_driver_w3c_W3C
