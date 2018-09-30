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

void Issue::setEffect(base::Effect * effect) {
	if (m_effect == effect)
		return;

	m_effect = effect;
	emit effectChanged(m_effect);
}

}  // namespace icL::look::session
