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

void LinkAdv::setUp(const QJsonObject & obj) {
	Link::setUp(obj);

	m_activeHover->setUp(obj.value("active-hover").toObject());
}

}  // namespace icL::look::base
