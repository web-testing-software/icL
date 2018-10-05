#ifndef icL_look_base_LinkAdv
#define icL_look_base_LinkAdv

#include "link.h"



namespace icL::look {

/**
 * @brief The LinkAdv class describes a look for advanced links
 */
class LinkAdv : public Link
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(TextLook * activeHover READ activeHover NOTIFY activeHoverChanged)
	// clang-format on

	TextLook * m_activeHover = nullptr;

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
	TextLook * activeHover() const;

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;

signals:
	void activeHoverChanged(TextLook * activeHover);
};

}

#endif  // icL_look_base_LinkAdv
