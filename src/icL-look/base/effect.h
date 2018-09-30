#ifndef EFFECT_H
#define EFFECT_H

#include "base.h"

#include <QColor>



namespace icL::look::base {

/**
 * @brief The Effect class decribes a look for an effect
 */
class Effect : public base::Base
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(QColor normal READ normal WRITE setNormal NOTIFY normalChanged)
	Q_PROPERTY(QColor  hover READ hover  WRITE setHover  NOTIFY hoverChanged)
	Q_PROPERTY(QColor active READ active WRITE setActive NOTIFY activeChanged)
	// clang-format on

	QColor m_normal;
	QColor m_hover;
	QColor m_active;

public:
	/**
	 * @brief Effect is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit Effect(QObject * parent = nullptr);

	/**
	 * @brief normal is the default effect color
	 * @return the default effect color
	 */
	QColor normal() const;

	/**
	 * @brief hover is the effect color for hover state
	 * @return the effect color for hover state
	 */
	QColor hover() const;

	/**
	 * @brief active is the effect color for active state
	 * @return the effect color for active state
	 */
	QColor active() const;

	/**
	 * @brief setUp set up the state from JSON object
	 * @param obj is the configuration object
	 */
	void setUp(const QJsonObject & obj);

signals:
	void normalChanged(QColor normal);
	void hoverChanged(QColor hover);
	void activeChanged(QColor active);

public slots:
	/**
	 * @brief setNormal changes the default effect color
	 * @param normal is the new default effect color
	 */
	void setNormal(QColor normal);

	/**
	 * @brief setHover changes the effect color for hover state
	 * @param hover is the new effect color for hover state
	 */
	void setHover(QColor hover);

	/**
	 * @brief setActive changes the effect color for active state
	 * @param active is the new effect color for active state
	 */
	void setActive(QColor active);
};

}  // namespace icL::look::base

#endif  // EFFECT_H
