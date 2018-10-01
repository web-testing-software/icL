#include "linkadv.h"

#include "text.h"

#include <QJsonObject>

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

QJsonObject LinkAdv::getUp() {
	auto obj = Link::getUp();

	obj["active-hover"] = m_activeHover->getUp();

	return obj;
}

}  // namespace icL::look::base
