#ifndef icL_look_base_Link
#define icL_look_base_Link

#include "text.h"

#include <QObject>

namespace icL::look::base {

/**
 * @brief The Link class describes a look for links
 */
class Link : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(Text * normal READ normal WRITE setNormal NOTIFY normalChanged)
	Q_PROPERTY(Text * hover READ hover WRITE setHover NOTIFY hoverChanged)
	Q_PROPERTY(Text * active READ active WRITE setActive NOTIFY activeChanged)
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

signals:
	void normalChanged(Text * normal);
	void hoverChanged(Text * hover);
	void activeChanged(Text * active);

public slots:
	/**
	 * @brief setNormal changes the default text color
	 * @param normal is the new default text color
	 */
	void setNormal(Text * normal);

	/**
	 * @brief setHover changes the hovered text color
	 * @param hover is the new hovered text color
	 */
	void setHover(Text * hover);

	/**
	 * @brief setActive changes the active text color
	 * @param active is the new active text color
	 */
	void setActive(Text * active);
};

}  // namespace icL::look::base

#endif  // icL_look_base_Link
