#include "linkadv.h"

namespace icL::look::base {

LinkAdv::LinkAdv(QObject * parent)
	: Link(parent) {
	m_activeHover = new Text(this);
}

LinkAdv::~LinkAdv() {
	icL_dropField(m_activeHover);
}

Text * LinkAdv::activeHover() const {
	return m_activeHover;
}

void LinkAdv::setActiveHover(Text * activeHover) {
	if (m_activeHover == activeHover) {
		return;
	}

	m_activeHover = activeHover;
	emit activeHoverChanged(m_activeHover);
}

}  // namespace icL::look::base
