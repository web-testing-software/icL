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

struct Tab
{
	QString name;
	QString url;
	int     framesCount;
	QString id;
};

struct Session
{
	QString id;
	int     tabsCount;
};

class Server
{
public:
	virtual void newLog(int level, const QString & message) = 0;

	// Session functions
	virtual void newSession()               = 0;
	virtual void deleteSession()            = 0;
	virtual int  status()                   = 0;
	virtual int  implicitTimeout()          = 0;
	virtual int  pageLoadTimeout()          = 0;
	virtual int  scriptTimeout()            = 0;
	virtual void setImplicitTimeout(int ms) = 0;
	virtual void setPageLoadTimeOut(int ms) = 0;
	virtual void setScriptTimeout(int ms)   = 0;

	// icL sessions functions
	virtual void           switchSessionTo(const QString & sessionId) = 0;
	virtual QList<Session> sessions()                                 = 0;

	// Navigation functions
	virtual void    setUrl(const QString & url) = 0;
	virtual QString url()                       = 0;
	virtual bool    canGoBack()                 = 0;  // icL
	virtual void    back()                      = 0;
	virtual bool    canGoForward()              = 0;  // icL
	virtual void    forward()                   = 0;
	virtual void    refresh()                   = 0;
	virtual QString title()                     = 0;

	// Windows and frames
	virtual QString     window()                        = 0;
	virtual void        closeWindow()                   = 0;
	virtual void        focusWindow(const QString & id) = 0;
	virtual QStringList windows()                       = 0;
	virtual void        switchToFrame(int id)           = 0;
	virtual void        switchtoFrame(WebElement * el)  = 0;
	virtual void        switchToParent()                = 0;

	// Window move and resize
	virtual QRect windowRect()                      = 0;
	virtual void  setWindowRect(const QRect & rect) = 0;
	virtual void  maximize()                        = 0;
	virtual void  minimize()                        = 0;
	virtual void  fullscreen()                      = 0;
	virtual void  restore()                         = 0;  // icL

	// Find elements
	virtual WebElement * findCssSelector(
	  WebElement * element, const QString & s) = 0;
	virtual WebElement * findLinkText(
	  WebElement * element, const QString & text) = 0;
	virtual WebElement * findPLinkText(
	  WebElement * element, const QString & text) = 0;
	virtual WebElement * findTagName(
	  WebElement * element, const QString & tag) = 0;
	virtual WebElement * findXpath(
	  WebElement * element, const QString & xpath) = 0;
	virtual WebElement * allCssSelector(
	  WebElement * element, const QString & s) = 0;
	virtual WebElement * allLinkText(
	  WebElement * element, const QString & text) = 0;
	virtual WebElement * allPLinkText(
	  WebElement * element, const QString & text) = 0;
	virtual WebElement * allTagName(
	  WebElement * element, const QString & tag) = 0;
	virtual WebElement * allXpath(
	  WebElement * element, const QString & xpath) = 0;

	// Elements manipulation
	virtual WebElement * active()                                         = 0;
	virtual bool         selected(WebElement * el)                        = 0;
	virtual QVariant     attribute(WebElement * el, const QString & name) = 0;
	virtual QVariant     property(WebElement * el, const QString & name)  = 0;
	virtual QVariant     css(WebElement * el, const QString & name)       = 0;
	virtual QVariant     text(WebElement * el)                            = 0;
	virtual QVariant     name(WebElement * el)                            = 0;
	virtual QRect        rect(WebElement * el)                            = 0;
	virtual bool         enabled(WebElement * el)                         = 0;
	virtual void         click(WebElement * el)                           = 0;
	virtual void         clear(WebElement * el)                           = 0;
	virtual void         value(WebElement * el, const QString & val)      = 0;
	virtual void         paste(WebElement * el, const QString & val)      = 0;

	// document
	virtual QString  source() = 0;
	virtual QVariant executeSync(
	  const QString & code, const QVariantList & args) = 0;
	virtual void executeAsync(
	  const QString & code, const QVariantList & args) = 0;
	virtual QVariant executeJs(const QString & code)   = 0;

	// cookie
	virtual QJsonArray  cookies()                                        = 0;
	virtual QJsonObject cookie(const QString & name)                     = 0;
	virtual void        udpCookie(const QString & name, QJsonObject obj) = 0;
	virtual void        deleteCookie(const QString & name)               = 0;
	virtual void        deleteAllCookies()                               = 0;

	// Actions
	// to be written later

	// Alert
	virtual void    alertDimiss()                       = 0;
	virtual void    alertAccept()                       = 0;
	virtual QString alertText()                         = 0;
	virtual void    alertSendText(const QString & text) = 0;

	// Screenshots
	virtual QImage screenshot()                = 0;
	virtual QImage screenshot(WebElement * el) = 0;

	// icL additional methods
	virtual WebElement * at(WebElement * el, int n)                        = 0;
	virtual WebElement * filter(WebElement * el, const QString & selector) = 0;
	virtual WebElement * contains(
	  WebElement * el, const QString & _template)                           = 0;
	virtual WebElement * next(WebElement * el)                              = 0;
	virtual WebElement * prev(WebElement * el)                              = 0;
	virtual WebElement * parent(WebElement * el)                            = 0;
	virtual WebElement * child(WebElement * el, int n)                      = 0;
	virtual WebElement * closest(WebElement * el, const QString & selector) = 0;

	// icL tabs interface
	virtual void toTabByName(const QString & _template)     = 0;
	virtual void toTabByName(const QRegExp & regexp)        = 0;
	virtual void toTabByUrl(const QString & _template)      = 0;
	virtual void toTabByUrl(const QRegExp & regexp)         = 0;
	virtual void toTabByIndex(int index)                    = 0;
	virtual void closeAllTabs()                             = 0;
	virtual void closeTabsToTheRight()                      = 0;
	virtual void closeOtherTabs()                           = 0;
	virtual void closeTabsByName(const QString & _template) = 0;
	virtual void closeTabsByName(const QRegExp & regexp)    = 0;
	virtual void closeTabsByUrl(const QString & _template)  = 0;
	virtual void closeTabsByUrl(const QRegExp & regexp)     = 0;
	virtual void closeTab()                                 = 0;
	virtual void newTab()                                   = 0;

	virtual QList<Tab> allTabs() = 0;
};

}  // namespace icL::memory

#endif  // icL_memory_interfaces_h
