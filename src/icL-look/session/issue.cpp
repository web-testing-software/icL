#include "issue.h"

#include "../base/effect.h"
#include "../base/linkadv.h"

#include <QJsonObject>

namespace icL::look {

Issue::Issue(QObject * parent)
    : LinkAdv(parent) {
    m_effect = new Effect(this);
}

Issue::~Issue() {
    delete m_effect;
}

Effect * Issue::effect() const {
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

}  // namespace icL::look
