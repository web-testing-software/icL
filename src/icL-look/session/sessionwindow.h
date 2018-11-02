#ifndef icL_look_SessionWindow
#define icL_look_SessionWindow

#include "../base/baselook.h"



namespace icL::look {

class CentralSide;
class Floating;
class LeftSide;
class TopBar;
class Static;

/**
 * @brief The SessionWindow class describes a look for session window
 */
class SessionWindow : public BaseLook
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::look::CentralSide* center READ center   NOTIFY centerChanged)
	Q_PROPERTY(icL::look::Floating*  floating READ floating NOTIFY floatingChanged)
	Q_PROPERTY(icL::look::LeftSide*      left READ left     NOTIFY leftChanged)
	Q_PROPERTY(icL::look::TopBar*         top READ top      NOTIFY topChanged)
	Q_PROPERTY(icL::look::Static*        main READ main     NOTIFY mainChanged)
	// clang-format on

public:
	/**
	 * @brief SessionWindow is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit SessionWindow(QObject * parent = nullptr);

	~SessionWindow();

	/**
	 * @brief center is the look of central widget
	 * @return the look for the central widget
	 */
	CentralSide * center() const;

	/**
	 * @brief floating is the look of floating panel
	 * @return the look for the floating panel
	 */
	Floating * floating() const;

	/**
	 * @brief left is the look of left panel
	 * @return the look for the left panel
	 */
	LeftSide * left() const;

	/**
	 * @brief top is the look for top bar
	 * @return the look for the top bar
	 */
	TopBar * top() const;

	/**
	 * @brief main is the look of main panel
	 * @return the look for main panel
	 */
	Static * main() const;

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;

signals:
	void centerChanged(CentralSide * center);
	void floatingChanged(Floating * floating);
	void leftChanged(LeftSide * left);
	void topChanged(TopBar * top);
	void mainChanged(Static * main);

private:
	CentralSide * m_center   = nullptr;
	Floating *    m_floating = nullptr;
	LeftSide *    m_left     = nullptr;
	TopBar *      m_top      = nullptr;
	Static *      m_main     = nullptr;
};

}  // namespace icL::look

#endif  // icL_look_SessionWindow
