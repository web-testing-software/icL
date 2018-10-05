#ifndef icL_look_session_TopBar
#define icL_look_session_TopBar

#include "../base/baselook.h"

#include <QColor>



namespace icL::look {

class TextLook;
class LinkAdv;
class EffectAdv;

class TopBar : public BaseLook
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(LinkAdv*      tab READ tab    NOTIFY tabChanged)
	Q_PROPERTY(LinkAdv*      url READ url    NOTIFY urlChanged)
	Q_PROPERTY(EffectAdv* button READ button NOTIFY buttonChanged)
	Q_PROPERTY(EffectAdv*   tool READ tool   NOTIFY toolChanged)
	Q_PROPERTY(TextLook*   input READ input  NOTIFY inputChanged)
	Q_PROPERTY(QColor cursor READ cursor WRITE setCursor NOTIFY cursorChanged)
	// clang-format on

	LinkAdv *   m_tab    = nullptr;
	LinkAdv *   m_url    = nullptr;
	EffectAdv * m_button = nullptr;
	EffectAdv * m_tool   = nullptr;
	TextLook *  m_input  = nullptr;
	QColor      m_cursor;

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
	LinkAdv * tab() const;

	/**
	 * @brief url is a look of an url bar
	 * @return the look for an url bar
	 */
	LinkAdv * url() const;

	/**
	 * @brief button is look for a title bar button
	 * @return the look for title bar buttons
	 */
	EffectAdv * button() const;

	/**
	 * @brief tool is a look for a tool icon
	 * @return the look for tool icons
	 */
	EffectAdv * tool() const;

	/**
	 * @brief input is a look for an url input
	 * @return the look for url inputs
	 */
	TextLook * input() const;

	/**
	 * @brief cursor is the color of text input cursor
	 * @return the color for text input cursors
	 */
	QColor cursor() const;

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;

signals:
	void cursorChanged(QColor cursor);
	void tabChanged(LinkAdv * tab);
	void urlChanged(LinkAdv * url);
	void buttonChanged(EffectAdv * button);
	void toolChanged(EffectAdv * tool);
	void inputChanged(TextLook * input);

public slots:
	/**
	 * @brief setCursor changes the color of text cursor
	 * @param cursor is the new color for text cursor
	 */
	void setCursor(QColor cursor);
};

}

#endif  // icL_look_session_TopBar
