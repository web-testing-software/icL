#ifndef icL_look_base_Link
#define icL_look_base_Link

#include "base.h"

#include <QObject>



namespace icL::look::base {

class Text;

/**
 * @brief The Link class describes a look for links
 */
class Link : public base::Base
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(Text * normal READ normal)
	Q_PROPERTY(Text *  hover READ hover)
	Q_PROPERTY(Text * active READ active)
	// clang-format on

	Text * m_normal = nullptr;
	Text * m_hover  = nullptr;
	Text * m_active = nullptr;

public:
	/**
	 * @brief Link is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit Link(QObject * parent = nullptr);

	~Link();

	/**
	 * @brief normal is the default text color
	 * @return the default text color
	 */
	Text * normal() const;

	/**
	 * @brief hover is the hovered text color
	 * @return the hovered text color
	 */
	Text * hover() const;

	/**
	 * @brief active is the active link color
	 * @return the active link color
	 */
	Text * active() const;

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;
};

}  // namespace icL::look::base

#endif  // icL_look_base_Link
