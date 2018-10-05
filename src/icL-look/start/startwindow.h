#ifndef icL_look_start_StartWindow
#define icL_look_start_StartWindow

#include "../base/baselook.h"



class TextLook;
class Side;

/**
 * @brief The StartWindow class describes a look for start window
 */
class StartWindow : public BaseLook
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(TextLook*    header READ header    NOTIFY headerChanged)
	Q_PROPERTY(Side*     left READ left      NOTIFY leftChanged)
	Q_PROPERTY(Side*    right READ right     NOTIFY rightChanged)
	Q_PROPERTY(TextLook* underline READ underline NOTIFY underlineChanged)
	// clang-format on

	TextLook * m_header    = nullptr;
	Side *       m_left      = nullptr;
	Side *       m_right     = nullptr;
	TextLook * m_underline = nullptr;

public:
	/**
	 * @brief StartWindow is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit StartWindow(QObject * parent = nullptr);

	~StartWindow();

	/**
	 * @brief header is the look for window header
	 * @return the look for window header
	 */
	TextLook * header() const;

	/**
	 * @brief left is look for the left side
	 * @return the look for left side
	 */
	Side * left() const;

	/**
	 * @brief right is look for the right side
	 * @return the look for the right side
	 */
	Side * right() const;

	/**
	 * @brief underline is the look for bottom line
	 * @return the look for bottom line
	 */
	TextLook * underline() const;

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;

signals:
	void underlineChanged(TextLook * underline);
	void rightChanged(Side * right);
	void leftChanged(Side * left);
	void headerChanged(TextLook * header);
};

#endif  // icL_look_start_StartWindow
