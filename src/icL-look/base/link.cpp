#include "link.h"

namespace icL::look::base {

Link::Link(QObject * parent)
	: QObject(parent) {}

Link::~Link() {
	icL_dropField (m_normal);
	icL_dropField (m_hover);
	icL_dropField (m_active);
}

Text * Link::normal() const {
	return m_normal;
}

Text * Link::hover() const {
	return m_hover;
}

Text * Link::active() const {
	return m_active;
}

void Link::setNormal(Text * normal) {
	if (m_normal == normal) {
		return;
	}

	m_normal = normal;
	emit normalChanged(m_normal);
}

void Link::setHover(Text * hover) {
	if (m_hover == hover) {
		return;
	}

	m_hover = hover;
	emit hoverChanged(m_hover);
}

void Link::setActive(Text * active) {
	if (m_active == active) {
		return;
	}

	m_active = active;
	emit activeChanged(m_active);
}

}  // namespace icL::look::base
