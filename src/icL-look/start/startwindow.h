#ifndef icL_look_start_StartWindow
#define icL_look_start_StartWindow

#include "side.h"



/**
 * The icL.look.start namespace contains look for the start window
 */
namespace icL::look::start {

/**
 * @brief The StartWindow class describes a look for start window
 */
class StartWindow : public base::Base
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(base::Text*    header READ header)
	Q_PROPERTY(Side*            left READ left)
	Q_PROPERTY(Side*           right READ right)
	Q_PROPERTY(base::Text* underline READ underline)
	// clang-format on

	base::Text * m_header    = nullptr;
	Side *       m_left      = nullptr;
	Side *       m_right     = nullptr;
	base::Text * m_underline = nullptr;

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
	base::Text * header() const;

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
	base::Text * underline() const;

	void setUp(const QJsonObject & obj) override;
};

}  // namespace icL::look::start

#endif  // icL_look_start_StartWindow
