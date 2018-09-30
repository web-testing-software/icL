#include "effect.h"

namespace icL::look::base {

Effect::Effect(QObject * parent)
	: QObject(parent) {}

QColor Effect::normal() const {
	return m_normal;
}

QColor Effect::hover() const {
	return m_hover;
}

QColor Effect::active() const {
	return m_active;
}

void Effect::setNormal(QColor normal) {
	if (m_normal == normal)
		return;

	m_normal = normal;
	emit normalChanged(m_normal);
}

void Effect::setHover(QColor hover) {
	if (m_hover == hover)
		return;

	m_hover = hover;
	emit hoverChanged(m_hover);
}

void Effect::setActive(QColor active) {
	if (m_active == active)
		return;

	m_active = active;
	emit activeChanged(m_active);
}

}  // namespace icL::look::base