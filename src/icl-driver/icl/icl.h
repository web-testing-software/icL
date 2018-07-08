#ifndef icL_driver_icl_Icl
#define icL_driver_icl_Icl

#include <icl-memory/interlevel/interfaces.h>
#include <icl-memory/interlevel/node.h>


namespace icL::driver::icl {

class Icl
	: public memory::Node
	, public memory::Server
{
public:
	Icl();

protected:
	virtual QVariant runJS(const QString & code) = 0;
	virtual bool     click(int x, int y)         = 0;
	virtual void     keys(const QString & keys)  = 0;
	virtual bool     get(const QString & url)    = 0;


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

	// Navigation functions
	void    setUrl(const QString & url) override;
	QString url() override;
	bool    canGoBack() override;  // icL
	void    back() override;
	bool    conGoForward() override;  // icL
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
	void        udpCookie(const QString & name, QJsonObject obj) override;
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
};

}  // namespace icL::driver::icl

#endif  // icL_driver_icl_Icl
