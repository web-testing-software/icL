#include "effectadv.h"

namespace icL::look::base {

EffectAdv::EffectAdv(QObject * parent)
	: Effect(parent) {}

QColor EffectAdv::activeHover() const {
	return m_activeHover;
}

void EffectAdv::setActiveHover(QColor activeHover) {
	if (m_activeHover == activeHover)
		return;

	m_activeHover = activeHover;
	emit activeHoverChanged(m_activeHover);
}

}  // namespace icL::look::base
