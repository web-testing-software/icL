#include "topbar.h"

#include "../base/effectadv.h"
#include "../base/linkadv.h"
#include "../base/textlook.h"

#include <QJsonObject>

namespace icL::look {

TopBar::TopBar(QObject * parent)
    : BaseLook(parent) {
    m_cursor = QColor(Qt::transparent);
    m_button = new EffectAdv(this);
    m_input  = new TextLook(this);
    m_tab    = new LinkAdv(this);
    m_tool   = new EffectAdv(this);
    m_url    = new LinkAdv(this);
}

TopBar::~TopBar() {
    delete m_button;
    delete m_input;
    delete m_tab;
    delete m_tool;
    delete m_url;
}

LinkAdv * TopBar::tab() const {
    return m_tab;
}

LinkAdv * TopBar::url() const {
    return m_url;
}

EffectAdv * TopBar::button() const {
    return m_button;
}

EffectAdv * TopBar::tool() const {
    return m_tool;
}

TextLook * TopBar::input() const {
    return m_input;
}

QColor TopBar::cursor() const {
    return m_cursor;
}

void TopBar::setUp(const QJsonObject & obj) {
    m_tab->setUp(obj.value("tab").toObject());
    m_url->setUp(obj.value("url").toObject());
    m_button->setUp(obj.value("button").toObject());
    m_tool->setUp(obj.value("tool").toObject());
    m_input->setUp(obj.value("input").toObject());

    m_cursor = objToColor(obj.value("cursor").toObject());

    emit cursorChanged(m_cursor);
}

QJsonObject TopBar::getUp() {
    return {{"tab", m_tab->getUp()},
            {"url", m_url->getUp()},
            {"button", m_button->getUp()},
            {"tool", m_tool->getUp()},
            {"input", m_input->getUp()}};
}

void TopBar::setCursor(const QColor & cursor) {
    if (m_cursor == cursor)
        return;

    m_cursor = cursor;
    emit cursorChanged(m_cursor);
}

}  // namespace icL::look
