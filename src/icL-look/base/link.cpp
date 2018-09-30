#include "link.h"

namespace icL::look::base {

Link::Link(QObject * parent)
	: Base(parent) {
	m_active = new Text(this);
	m_hover  = new Text(this);
	m_normal = new Text(this);
}

Link::~Link() {
	icL_dropField(m_normal);
	icL_dropField(m_hover);
	icL_dropField(m_active);
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

void Link::setUp(const QJsonObject & obj) {
	m_active->setUp(obj.value("active").toObject());
	m_hover->setUp(obj.value("hover").toObject());
	m_normal->setUp(obj.value("normal").toObject());

	emit activeChanged(m_active);
	emit hoverChanged(m_hover);
	emit normalChanged(m_normal);
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
