#include "effectadv.h"

namespace icL::look::base {

EffectAdv::EffectAdv(QObject * parent)
	: Effect(parent) {
	m_activeHover = QColor(Qt::transparent);
}

QColor EffectAdv::activeHover() const {
	return m_activeHover;
}

void EffectAdv::setUp(const QJsonObject & obj) {
	Effect::setUp(obj);

	m_activeHover = objToColor(obj.value("active-hover").toObject());

	emit activeHoverChanged(m_activeHover);
}

QJsonObject EffectAdv::getUp() {
	auto obj = Effect::getUp();

	obj["active-hover"] = colorToObj(m_activeHover);

	return obj;
}

void EffectAdv::setActiveHover(QColor activeHover) {
	if (m_activeHover == activeHover)
		return;

	m_activeHover = activeHover;
	emit activeHoverChanged(m_activeHover);
}

}  // namespace icL::look::base
