#ifndef EFFECTADV_H
#define EFFECTADV_H

#include "effect.h"

namespace icL::look::base {

/**
 * @brief The EffectAdv class
 */
class EffectAdv : public Effect
{
	Q_OBJECT

	Q_PROPERTY(QColor activeHover READ activeHover WRITE setActiveHover NOTIFY
																		activeHoverChanged)

	QColor m_activeHover;

public:
	/**
	 * @brief EffectAdv is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit EffectAdv(QObject * parent = nullptr);

	/**
	 * @brief activeHover is the color for link in active and hover state
	 * @return the color for link in active and hover state
	 */
	QColor activeHover() const;

signals:
	void activeHoverChanged(QColor activeHover);

public slots:
	/**
	 * @brief setActiveHover changes the link color for active and hover state
	 * @param activeHover is the new link color for active and hover state
	 */
	void setActiveHover(QColor activeHover);
};

}  // namespace icL::look::base

#endif  // EFFECTADV_H
