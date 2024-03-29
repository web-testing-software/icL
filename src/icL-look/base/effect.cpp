#include "effect.h"

#include <QJsonObject>

namespace icL::look {

Effect::Effect(QObject * parent)
    : BaseLook(parent) {
    m_active = m_hover = m_normal = QColor(Qt::transparent);
}

QColor Effect::normal() const {
    return m_normal;
}

QColor Effect::hover() const {
    return m_hover;
}

QColor Effect::active() const {
    return m_active;
}

void Effect::setUp(const QJsonObject & obj) {
    m_normal = objToColor(obj.value("normal").toObject());
    m_hover  = objToColor(obj.value("hover").toObject());
    m_active = objToColor(obj.value("active").toObject());

    emit activeChanged(m_active);
    emit hoverChanged(m_hover);
    emit normalChanged(m_normal);
}

QJsonObject Effect::getUp() {
    return {{"normal", colorToObj(m_normal)},
            {"hover", colorToObj(m_hover)},
            {"active", colorToObj(m_active)}};
}

void Effect::setNormal(const QColor & normal) {
    if (m_normal == normal)
        return;

    m_normal = normal;
    emit normalChanged(m_normal);
}

void Effect::setHover(const QColor & hover) {
    if (m_hover == hover)
        return;

    m_hover = hover;
    emit hoverChanged(m_hover);
}

void Effect::setActive(const QColor & active) {
    if (m_active == active)
        return;

    m_active = active;
    emit activeChanged(m_active);
}

}  // namespace icL::look
