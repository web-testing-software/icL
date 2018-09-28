#ifndef icL_look_base_LinkAdv
#define icL_look_base_LinkAdv

#include "link.h"

#include <QObject>

namespace icL::look::base {

/**
 * @brief The LinkAdv class describes a look for advanced links
 */
class LinkAdv : public Link
{
	Q_OBJECT

	Q_PROPERTY(Text * activeHover READ activeHover WRITE setActiveHover NOTIFY
																		activeHoverChanged)

	Text * m_activeHover = nullptr;

public:
	/**
	 * @brief LinkAdv is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit LinkAdv(QObject * parent = nullptr);

	~LinkAdv();

	/**
	 * @brief activeHover is the color of active and hovered link
	 * @return the color for an active and hovered link
	 */
	Text * activeHover() const;

signals:
	void activeHoverChanged(Text * activeHover);

public slots:
	/**
	 * @brief setActiveHover
	 * @param activeHover
	 */
	void setActiveHover(Text * activeHover);
};

}  // namespace icL::look::base

#endif  // icL_look_base_LinkAdv
