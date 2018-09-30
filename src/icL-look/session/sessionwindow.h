#ifndef icL_look_session_SessionWindow
#define icL_look_session_SessionWindow

#include "centralside.h"
#include "floating.h"
#include "leftside.h"
#include "topbar.h"



/**
 * The icL.look.session namespace defines a look for session window
 */
namespace icL::look::session {

/**
 * @brief The SessionWindow class describes a look for session window
 */
class SessionWindow : public base::Base
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(CentralSide* center READ center   WRITE setCenter   NOTIFY centerChanged)
	Q_PROPERTY(Floating*  floating READ floating WRITE setFloating NOTIFY floatingChanged)
	Q_PROPERTY(LeftSide*      left READ left     WRITE setLeft     NOTIFY leftChanged)
	Q_PROPERTY(TopBar*         top READ top      WRITE setTop      NOTIFY topChanged)
	// clang-format on

	CentralSide * m_center   = nullptr;
	Floating *    m_floating = nullptr;
	LeftSide *    m_left     = nullptr;
	TopBar *      m_top      = nullptr;

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
	 * @brief setUp set up the state from JSON object
	 * @param obj is the configuration object
	 */
	void setUp(const QJsonObject & obj);

signals:
	void centerChanged(CentralSide * center);
	void floatingChanged(Floating * floating);
	void leftChanged(LeftSide * left);
	void topChanged(TopBar * top);

public slots:
	/**
	 * @brief setCenter changes the look of central widget
	 * @param center is the new look for the central widget
	 */
	void setCenter(CentralSide * center);

	/**
	 * @brief setFloating changes the look of floating panel
	 * @param floating is the new look for the floating panel
	 */
	void setFloating(Floating * floating);

	/**
	 * @brief setLeft changes the look of left panel
	 * @param left is the new look for the left panel
	 */
	void setLeft(LeftSide * left);

	/**
	 * @brief setTop changes the look of the top bar
	 * @param top is the new look for the top bar
	 */
	void setTop(TopBar * top);
};

}  // namespace icL::look::session

#endif  // icL_look_session_SessionWindow
