#ifndef icL_Server
#define icL_Server

#include <icl-memory/interlevel/interlevel.h>
#include <icl-memory/interlevel/node.h>

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
	: public memory::ServerLowLevel
	, public memory::Node
{
protected:
	enum class WaitFor { GoTo, PageLoading, ExecuteJS, ErrorDialog, Nothing };

public:
	Server();

	~Server();

	/**
	 * @brief goTo - go to url and wait for page loading
	 * @param url - url to go, format: user input
	 * @return true if page was successful loaded, otherwise false
	 */
	virtual bool goTo(const QString & url) = 0;

	/**
	 * @brief waitForPageLoading - stop exeuting until the page is complete
	 * loaded
	 * @return true if page was successful loaded, otherwise false
	 */
	virtual bool waitForPageLoading() = 0;

	/**
	 * @brief executeJS - execute synchronously js code
	 * @param code - code to execute
	 * @return the returned value from js world
	 */
	virtual QVariant executeJS(const QString & code) = 0;

	virtual void logOut(int level, const QString & message) = 0;

	void setInterlevel(memory::InterLevel * il);

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

public:
	// memory.ServerLowLevel interface
	virtual QVariant runJS(const QString & code) override;
	virtual bool     click(int x, int y) override;
	virtual void     keys(const QString & keys) override;
	virtual void     newLog(int level, const QString & message) override;
	virtual bool     get(const QString & url) override;

protected:
	QQuickItem * m_webEngine;
};

}  // namespace icL

#endif  // icL_Server
