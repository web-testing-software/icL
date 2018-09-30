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

}  // namespace icL::look::session
