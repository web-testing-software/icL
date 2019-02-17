#include "link.h"

#include "textlook.h"

#include <QJsonObject>

namespace icL::look {

Link::Link(QObject * parent)
    : BaseLook(parent) {
    m_active = new TextLook(this);
    m_hover  = new TextLook(this);
    m_normal = new TextLook(this);
}

Link::~Link() {
    delete m_normal;
    delete m_hover;
    delete m_active;
}

TextLook * Link::normal() const {
    return m_normal;
}

TextLook * Link::hover() const {
    return m_hover;
}

TextLook * Link::active() const {
    return m_active;
}

void Link::setUp(const QJsonObject & obj) {
    m_active->setUp(obj.value("active").toObject());
    m_hover->setUp(obj.value("hover").toObject());
    m_normal->setUp(obj.value("normal").toObject());
}

QJsonObject Link::getUp() {
    return {{"active", m_active->getUp()},
            {"hover", m_hover->getUp()},
            {"normal", m_normal->getUp()}};
}

}  // namespace icL::look
