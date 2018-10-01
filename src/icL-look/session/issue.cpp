#include "issue.h"

namespace icL::look::session {

Issue::Issue(QObject * parent)
	: LinkAdv(parent) {
	m_effect = new base::Effect(this);
}

Issue::~Issue() {
	icL_dropField(m_effect);
}

base::Effect * Issue::effect() const {
	return m_effect;
}

void Issue::setUp(const QJsonObject & obj) {
	LinkAdv::setUp(obj);

	m_effect->setUp(obj.value("effect").toObject());
}

QJsonObject Issue::getUp() {
	auto obj = LinkAdv::getUp();

	obj["effect"] = m_effect->getUp();

	return obj;
}

}  // namespace icL::look::session
