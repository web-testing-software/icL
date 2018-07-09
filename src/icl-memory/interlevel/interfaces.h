#ifndef icL_memory_interfaces_h
#define icL_memory_interfaces_h

#include "../structures/functioncontainer.h"
#include "../structures/return.h"
#include "../structures/webelement.h"


namespace icL::inter {
class Flayer;
}

/**
 *  icL
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
 *  '-> memory
 */
namespace icL::memory {

class Exception;

class Interpreter
{
public:
	virtual void newSignal(int code, const QString & name) = 0;

	virtual inter::Flayer & getFlayer() = 0;
};

class VirtualMachine
{
public:
	virtual void exception(const Exception & exc) = 0;

	virtual QString * source()          = 0;
	virtual QVariant  getConsoleValue() = 0;
};

enum class SelectionColor { Parsing, Executing, NewStack, Destroying, Error };

class VMStack
{
public:
	virtual void interrupt(
	  FunctionCall fcall, std::function<void(Return &)> feedback) = 0;

	virtual const QString & getWorkingDir()    = 0;
	virtual const QString & getCrossfirePass() = 0;

	virtual void highlight(int pos1, int pos2)       = 0;
	virtual void exit(const memory::Exception & exc) = 0;

	virtual void setSColor(SelectionColor scolor) = 0;
};

/**
 * @brief The Tab struct - decribe a tab, or a window in case of w3c webdriver
 */
struct Tab
{
	QString id;           ///< tab or window uuid
	QString name;         ///< page title
	QString url;          ///< page url
	int     framesCount;  ///< number of frames in window
};

/**
 * @brief The Session struct - decribe a session
 */
struct Session
{
	QString id;         ///< session uuid
	int     tabsCount;  ///< number of tabs
};

class Server
{
public:
	/**
	 * @brief newLog - send new log to icL console
	 * @param level - 0 - info, 1 - warning, 2 - error
	 * @param message - error message
	 */
	virtual void newLog(int level, const QString & message) = 0;

	// Session functions

	/**
	 * @brief newSession - w3c POST /session
	 */
	virtual void newSession() = 0;

	/**
	 * @brief deleteSession - w3c DELETE /session/{session id}
	 */
	virtual void deleteSession() = 0;

	/**
	 * @brief status - w3c GET /status
	 * @return {returned object}.status as int
	 */
	virtual int status() = 0;

	/**
	 * @brief implicitTimeout - w3c GET /session/{session id}/timeouts
	 * @return {returned object}.implicit
	 */
	virtual int implicitTimeout() = 0;

	/**
	 * @brief pageLoadTimeout - w3c GET /session/{session id}/timeouts
	 * @return {returned object}.pageLoad
	 */
	virtual int pageLoadTimeout() = 0;

	/**
	 * @brief scriptTimeout - w3c GET /session/{session id}/timeouts
	 * @return {returned object}.script
	 */
	virtual int scriptTimeout() = 0;

	/**
	 * @brief setImplicitTimeout - w3c POST /session/{session id}/timeouts
	 * @param ms - {sended object}.implicit
	 */
	virtual void setImplicitTimeout(int ms) = 0;

	/**
	 * @brief setPageLoadTimeOut - w3c POST /session/{session id}/timeouts
	 * @param ms - {sended object}.pageLoad
	 */
	virtual void setPageLoadTimeOut(int ms) = 0;

	/**
	 * @brief setScriptTimeout - w3c POST /session/{session id}/timeouts
	 * @param ms - {sended object}.script
	 */
	virtual void setScriptTimeout(int ms) = 0;

	// icL sessions functions

	/**
	 * @brief switchSessionTo - icL switch current sessin
	 * @param sessionId - the session id to focus
	 */
	virtual void switchSessionTo(const QString & sessionId) = 0;

	/**
	 * @brief sessions - icL get the list of current active sessions
	 * @return a list of current active sessions
	 */
	virtual QList<Session> sessions() = 0;

	// Navigation functions

	/**
	 * @brief setUrl - w3c POST /session/{session id}/url
	 * @param url - {sended object}.url
	 */
	virtual void setUrl(const QString & url) = 0;

	/**
	 * @brief url - w3c GET /session/{session id}/url
	 * @return {returned object}.value
	 */
	virtual QString url() = 0;

	/**
	 * @brief canGoBack - icL
	 * @return the "back" button aviability
	 */
	virtual bool canGoBack() = 0;

	/**
	 * @brief back - w3c POST /session/{session id}/back
	 */
	virtual void back() = 0;

	/**
	 * @brief canGoForward - icL
	 * @return the "forward" button aviability
	 */
	virtual bool canGoForward() = 0;

	/**
	 * @brief forward - w3c POST /session/{session id}/forward
	 */
	virtual void forward() = 0;

	/**
	 * @brief refresh - w3c POST /session/{session id}/refresh
	 */
	virtual void refresh() = 0;

	/**
	 * @brief title - w3c GET /session/{session id}/title
	 * @return {returned object}.value
	 */
	virtual QString title() = 0;

	// Windows and frames

	/**
	 * @brief window - w3c GET /session/{session id}/window
	 * @return {returned object}.value
	 */
	virtual QString window() = 0;

	/**
	 * @brief closeWindow - w3c DELETE /session/{session id}/window
	 */
	virtual void closeWindow() = 0;

	/**
	 * @brief focusWindow - w3c POST /session/{session id}/window
	 * @param id - {sended object}.handle
	 */
	virtual void focusWindow(const QString & id) = 0;

	/**
	 * @brief windows - w3c GET /session/{session id}/window/handles
	 * @return {returned object}.value
	 */
	virtual QStringList windows() = 0;

	/**
	 * @brief switchToFrame - w3c POST /session/{session id}/frame
	 * @param id - {sended object}.id
	 */
	virtual void switchToFrame(int id) = 0;

	/**
	 * @brief switchToFrame - w3c POST /session/{session id}/frame
	 * @param id - {sended object}.id
	 */
	virtual void switchtoFrame(WebElement * el) = 0;
	/**
	 * @brief switchToParent - w3c POST /session/{session id}/frame/parent
	 */
	virtual void switchToParent() = 0;

	// Window move and resize

	/**
	 * @brief windowRect - w3c GET /session/{session id}/window/rect
	 * @return {returned object}.value
	 */
	virtual QRect windowRect() = 0;

	/**
	 * @brief setWindowRect - w3c POST /session/{session id}/window/rect
	 * @param rect - {sended object}
	 */
	virtual void setWindowRect(const QRect & rect) = 0;

	/**
	 * @brief maximize - w3c POST /session/{session id}/window/maximize
	 */
	virtual void maximize() = 0;

	/**
	 * @brief minimize - w3c POST /session/{session id}/window/minimize
	 */
	virtual void minimize() = 0;

	/**
	 * @brief fullscreen - w3c POST /session/{session id}/window/fullscreen
	 */
	virtual void fullscreen() = 0;

	/**
	 * @brief restore - icL restore window from maximized / minimised /
	 * fullscreen states
	 */
	virtual void restore() = 0;

	// Find elements

	/**
	 * @brief findCssSelector - w3c POST /session/{session id}/element or POST
	 * /session/{session id}/element/{element id}/element
	 * @param element - element to find in or nullptr
	 * @param s - css selector
	 * @return {returned object}.value
	 */
	virtual WebElement * findCssSelector(
	  WebElement * element, const QString & s) = 0;

	/**
	 * @brief findLinkText - w3c POST /session/{session id}/element or POST
	 * /session/{session id}/element/{element id}/element
	 * @param element - element to find in or nullptr
	 * @param text - link text
	 * @return {returned object}.value
	 */
	virtual WebElement * findLinkText(
	  WebElement * element, const QString & text) = 0;

	/**
	 * @brief findPLinkText - w3c POST /session/{session id}/element or POST
	 * /session/{session id}/element/{element id}/element
	 * @param element - element to find in or nullptr
	 * @param text - partial link text
	 * @return {returned object}.value
	 */
	virtual WebElement * findPLinkText(
	  WebElement * element, const QString & text) = 0;

	/**
	 * @brief findTagName - w3c POST /session/{session id}/element or POST
	 * /session/{session id}/element/{element id}/element
	 * @param element - element to find in or nullptr
	 * @param tag - tag name
	 * @return {returned object}.value
	 */
	virtual WebElement * findTagName(
	  WebElement * element, const QString & tag) = 0;

	/**
	 * @brief findXpath - w3c POST /session/{session id}/element or POST
	 * /session/{session id}/element/{element id}/element
	 * @param element - element to find in or nullptr
	 * @param xpath - xpath
	 * @return {returned object}.value
	 */
	virtual WebElement * findXpath(
	  WebElement * element, const QString & xpath) = 0;

	/**
	 * @brief allCssSelector - w3c POST /session/{session id}/element or POST
	 * /session/{session id}/element/{element id}/element
	 * @param element - element to find in or nullptr
	 * @param s - css selector
	 * @return {returned object}.value
	 */
	virtual WebElement * allCssSelector(
	  WebElement * element, const QString & s) = 0;

	/**
	 * @brief allLinkText - w3c POST /session/{session id}/elements or POST
	 * /session/{session id}/element/{element id}/elements
	 * @param element - element to find in or nullptr
	 * @param text - link text
	 * @return {returned object}.value
	 */
	virtual WebElement * allLinkText(
	  WebElement * element, const QString & text) = 0;

	/**
	 * @brief allPLinkText - w3c POST /session/{session id}/elements or POST
	 * /session/{session id}/element/{element id}/elements
	 * @param element - element to find in or nullptr
	 * @param text - partial link text
	 * @return {returned object}.value
	 */
	virtual WebElement * allPLinkText(
	  WebElement * element, const QString & text) = 0;

	/**
	 * @brief allTagName - w3c POST /session/{session id}/elements or POST
	 * /session/{session id}/element/{element id}/elements
	 * @param element - element to find in or nullptr
	 * @param tag - tag name
	 * @return {returned object}.value
	 */
	virtual WebElement * allTagName(
	  WebElement * element, const QString & tag) = 0;

	/**
	 * @brief allXpath - w3c POST /session/{session id}/elements or POST
	 * /session/{session id}/element/{element id}/elements
	 * @param element - element to find in or nullptr
	 * @param xpath - xpath
	 * @return {returned object}.value
	 */
	virtual WebElement * allXpath(
	  WebElement * element, const QString & xpath) = 0;

	// Elements manipulation

	/**
	 * @brief active - w3c GET /session/{session id}/element/active
	 * @return {returned object}.value
	 */
	virtual WebElement * active() = 0;

	/**
	 * @brief selected - w3c GET /session/{session id}/element/{element
	 * id}/selected
	 * @param el - {element id}
	 * @return {returned object}.value
	 */
	virtual bool selected(WebElement * el) = 0;

	/**
	 * @brief attribute - w3c GET /session/{session id}/element/{element
	 * id}/attribute/{name}
	 * @param el - {element id}
	 * @param name - {name}
	 * @return {returned object}.value
	 */
	virtual QVariant attribute(WebElement * el, const QString & name) = 0;

	/**
	 * @brief property - w3c GET /session/{session id}/element/{element
	 * id}/property/{name}
	 * @param el - {element id}
	 * @param name - {name}
	 * @return {returned object}.value
	 */
	virtual QVariant property(WebElement * el, const QString & name) = 0;

	/**
	 * @brief css - w3c GET /session/{session id}/element/{element
	 * id}/css/{property name}
	 * @param el - {element id}
	 * @param name - {property name}
	 * @return {returned object}.value
	 */
	virtual QVariant css(WebElement * el, const QString & name) = 0;

	/**
	 * @brief text - w3c GET /session/{session id}/element/{element id}/text
	 * @param el - {element id}
	 * @return {returned object}.value
	 */
	virtual QVariant text(WebElement * el) = 0;

	/**
	 * @brief name - w3c GET /session/{session id}/element/{element id}/name
	 * @param el - {element id}
	 * @return {returned object}.value
	 */
	virtual QVariant name(WebElement * el) = 0;

	/**
	 * @brief rect - w3c GET /session/{session id}/element/{element id}/rect
	 * @param el - {element id}
	 * @return {returned object}.value
	 */
	virtual QRect rect(WebElement * el) = 0;

	/**
	 * @brief enabled - w3c GET /session/{session id}/element/{element
	 * id}/enabled
	 * @param el - {element id}
	 * @return {returned object}.value
	 */
	virtual bool enabled(WebElement * el) = 0;

	/**
	 * @brief click - w3c POST /session/{session id}/element/{element id}/click
	 * @param el - {element id}
	 */
	virtual void click(WebElement * el) = 0;

	/**
	 * @brief clear - w3c POST /session/{session id}/element/{element id}/clear
	 * @param el - {element id}
	 */
	virtual void clear(WebElement * el) = 0;

	/**
	 * @brief value - w3c POST /session/{session id}/element/{element id}/value
	 * @param el - {element id}
	 * @param val - {sended object}.value
	 */
	virtual void value(WebElement * el, const QString & val) = 0;

	/**
	 * @brief paste - icL alternative to value
	 * @param el - {element id}
	 * @param val - string to copy to clipboard
	 */
	virtual void paste(WebElement * el, const QString & val) = 0;

	// document

	/**
	 * @brief source - w3c GET /session/{session id}/source
	 * @return {returned object}.value
	 */
	virtual QString source() = 0;

	/**
	 * @brief executeSync - w3c POST /session/{session id}/execute/sync
	 * @param code - {sended object}.script
	 * @param args - {sended object}.args
	 * @return {returned object}.value
	 */
	virtual QVariant executeSync(
	  const QString & code, const QVariantList & args) = 0;

	/**
	 * @brief executeAsync - w3c POST /session/{session id}/execute/async
	 * @param code - {sended object}.script
	 * @param args - {sended object}.args
	 */
	virtual void executeAsync(
	  const QString & code, const QVariantList & args) = 0;

	/**
	 * @brief executeJs - icL execute javascipt method
	 * @param code - code to run
	 * @return script result console value
	 */
	virtual QVariant executeJs(const QString & code) = 0;

	// cookie

	/**
	 * @brief cookies - w3c GET /session/{session id}/cookie
	 * @return {returned object}.value
	 */
	virtual QJsonArray cookies() = 0;

	/**
	 * @brief cookie - w3c GET /session/{session id}/cookie/{name}
	 * @param name - {name}
	 * @return {returned object}.value
	 */
	virtual QJsonObject cookie(const QString & name) = 0;

	/**
	 * @brief udpCookie - w3c POST /session/{session id}/cookie
	 * @param obj - {sended object}.cookie
	 */
	virtual void udpCookie(QJsonObject obj) = 0;

	/**
	 * @brief deleteCookie - w3c DELETE	/session/{session id}/cookie/{name}
	 * @param name - {name}
	 */
	virtual void deleteCookie(const QString & name) = 0;

	/**
	 * @brief deleteAllCookies - w3c DELETE	/session/{session id}/cookie
	 */
	virtual void deleteAllCookies() = 0;

	// Actions
	// to be written later

	// Alert

	/**
	 * @brief alertDimiss - w3c POST /session/{session id}/alert/dismiss
	 */
	virtual void alertDimiss() = 0;

	/**
	 * @brief alertAccept - w3c POST /session/{session id}/alert/accept
	 */
	virtual void alertAccept() = 0;

	/**
	 * @brief alertText - w3c GET /session/{session id}/alert/text
	 * @return {returned object}.value
	 */
	virtual QString alertText() = 0;

	/**
	 * @brief alertSendText - w3c POST /session/{session id}/alert/text
	 * @param text - {sended object}.text
	 */
	virtual void alertSendText(const QString & text) = 0;

	// Screenshots

	/**
	 * @brief screenshot - w3c GET /session/{session id}/screenshot
	 * @return {returned object}.value
	 */
	virtual QImage screenshot() = 0;

	/**
	 * @brief screenshot - GET /session/{session id}/element/{element
	 * id}/screenshot
	 * @param el - {element id}
	 * @return {returned object}.value
	 */
	virtual QImage screenshot(WebElement * el) = 0;

	// icL additional methods

	/**
	 * @brief at - get nth element
	 * @param el - elements container
	 * @param n - element order number
	 * @return a new element object
	 */
	virtual WebElement * at(WebElement * el, int n) = 0;

	/**
	 * @brief filter - filter elements from continer
	 * @param el - elements container
	 * @param selector - selector to match
	 * @return a new element object
	 */
	virtual WebElement * filter(WebElement * el, const QString & selector) = 0;

	/**
	 * @brief contains - filter elements by content
	 * @param el - elements container
	 * @param _template - string template to check innerText
	 * @return a new element object
	 */
	virtual WebElement * contains(
	  WebElement * el, const QString & _template) = 0;

	/**
	 * @brief next - next sibling element
	 * @param el - elements container
	 * @return a new element object
	 */
	virtual WebElement * next(WebElement * el) = 0;

	/**
	 * @brief prev - previous sibling element
	 * @param el - elements container
	 * @return a new element object
	 */
	virtual WebElement * prev(WebElement * el) = 0;

	/**
	 * @brief parent - parent node
	 * @param el - elements container
	 * @return a new element object
	 */
	virtual WebElement * parent(WebElement * el) = 0;

	/**
	 * @brief child - get child by index
	 * @param el - elements container
	 * @param n - index of child
	 * @return a new element object
	 */
	virtual WebElement * child(WebElement * el, int n) = 0;

	/**
	 * @brief children - get children of element
	 * @param el - elements container
	 * @return a new element object
	 */
	virtual WebElement * children(WebElement * el) = 0;

	/**
	 * @brief closest - get closest element
	 * @param el - elements container
	 * @param selector - selector to match
	 * @return a new element object
	 */
	virtual WebElement * closest(WebElement * el, const QString & selector) = 0;

	// icL tabs interface

	/**
	 * @brief toTabByName - switch tab by tab name
	 * @param _template - string template to match
	 */
	virtual void toTabByName(const QString & _template) = 0;

	/**
	 * @brief toTabByName - switch tab by tab name
	 * @param regexp - regular expression to match
	 */
	virtual void toTabByName(const QRegExp & regexp) = 0;

	/**
	 * @brief toTabByUrl - switch tab by page url
	 * @param _template - string template to match
	 */
	virtual void toTabByUrl(const QString & _template) = 0;

	/**
	 * @brief toTabByUrl - switch tab by page url
	 * @param regexp - regular expression to match
	 */
	virtual void toTabByUrl(const QRegExp & regexp) = 0;

	/**
	 * @brief toTabByIndex - switch tab by index
	 * @param index - index of tab to focus
	 */
	virtual void toTabByIndex(int index) = 0;

	/**
	 * @brief closeAllTabs - close all tab from session (chrome are closing automatically)
	 */
	virtual void closeAllTabs() = 0;

	/**
	 * @brief closeTabsToTheRight - close tabs to the right
	 */
	virtual void closeTabsToTheRight() = 0;

	/**
	 * @brief closeOtherTabs - close other tabss
	 */
	virtual void closeOtherTabs() = 0;

	/**
	 * @brief closeTabsByName - close tabs by name matching
	 * @param _template - string template to match
	 */
	virtual void closeTabsByName(const QString & _template) = 0;

	/**
	 * @brief closeTabsByName - close tabs by name matching
	 * @param regexp - regular expression to match
	 */
	virtual void closeTabsByName(const QRegExp & regexp) = 0;

	/**
	 * @brief closeTabsByUrl - close tabs by url matching
	 * @param _template - string template to match
	 */
	virtual void closeTabsByUrl(const QString & _template) = 0;

	/**
	 * @brief closeTabsByUrl - close tabs by url matching
	 * @param regexp - regular expression to match
	 */
	virtual void closeTabsByUrl(const QRegExp & regexp) = 0;

	/**
	 * @brief closeTab - close current tab
	 */
	virtual void closeTab() = 0;

	/**
	 * @brief newTab - open a new tab
	 */
	virtual void newTab() = 0;

	/**
	 * @brief allTabs - get the list of tabs
	 * @return a list of tabs
	 */
	virtual QList<Tab> allTabs() = 0;
};

}  // namespace icL::memory

#endif  // icL_memory_interfaces_h
