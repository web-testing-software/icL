#ifndef icL_look_session_TopBar
#define icL_look_session_TopBar

#include "../base/effectadv.h"
#include "../base/linkadv.h"

#include <QObject>

namespace icL::look::session {

class TopBar : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(base::LinkAdv*      tab READ tab    WRITE setTab    NOTIFY tabChanged)
	Q_PROPERTY(base::LinkAdv*      url READ url    WRITE setUrl    NOTIFY urlChanged)
	Q_PROPERTY(base::EffectAdv* button READ button WRITE setButton NOTIFY buttonChanged)
	Q_PROPERTY(base::EffectAdv*   tool READ tool   WRITE setTool   NOTIFY toolChanged)
	Q_PROPERTY(base::Text*       input READ input  WRITE setInput  NOTIFY inputChanged)
	Q_PROPERTY(QColor           cursor READ cursor WRITE setCursor NOTIFY cursorChanged)
	// clang-format on

	base::LinkAdv *   m_tab    = nullptr;
	base::LinkAdv *   m_url    = nullptr;
	base::EffectAdv * m_button = nullptr;
	base::EffectAdv * m_tool   = nullptr;
	base::Text *      m_input  = nullptr;
	QColor            m_cursor;

public:
	/**
	 * @brief TopBar is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit TopBar(QObject * parent = nullptr);

	~TopBar();

	/**
	 * @brief tab is a look of a tab
	 * @return the look for a tab
	 */
	base::LinkAdv * tab() const;

	/**
	 * @brief url is a look of an url bar
	 * @return the look for an url bar
	 */
	base::LinkAdv * url() const;

	/**
	 * @brief button is look for a title bar button
	 * @return the look for title bar buttons
	 */
	base::EffectAdv * button() const;

	/**
	 * @brief tool is a look for a tool icon
	 * @return the look for tool icons
	 */
	base::EffectAdv * tool() const;

	/**
	 * @brief input is a look for an url input
	 * @return the look for url inputs
	 */
	base::Text * input() const;

	/**
	 * @brief cursor is the color of text input cursor
	 * @return the color for text input cursors
	 */
	QColor cursor() const;

signals:
	void tabChanged(base::LinkAdv * tab);
	void urlChanged(base::LinkAdv * url);
	void buttonChanged(base::EffectAdv * button);
	void toolChanged(base::EffectAdv * tool);
	void inputChanged(base::Text * input);
	void cursorChanged(QColor cursor);

public slots:
	/**
	 * @brief setTab changes the look of tabs
	 * @param tab is the new look for tabs
	 */
	void setTab(base::LinkAdv * tab);

	/**
	 * @brief setUrl changes the look of url bar
	 * @param url is the new look for url bar
	 */
	void setUrl(base::LinkAdv * url);

	/**
	 * @brief setButton changes the look of title bar buttons
	 * @param button is the new look for title bar buttons
	 */
	void setButton(base::EffectAdv * button);

	/**
	 * @brief setTool changes the look of tool buttons
	 * @param tool is the new look for tool buttons
	 */
	void setTool(base::EffectAdv * tool);

	/**
	 * @brief setInput changes the look of url input
	 * @param input is the new look for urm inputs
	 */
	void setInput(base::Text * input);

	/**
	 * @brief setCursor changes the color of text cursor
	 * @param cursor is the new color for text cursor
	 */
	void setCursor(QColor cursor);
};

}  // namespace icL::look::session

#endif  // icL_look_session_TopBar
