#include "scrollbar.h"

#include <QDebug>
#include <QJsonObject>

namespace icL::look {

ScrollBar::ScrollBar(QObject * parent)
    : BaseLook(parent) {}

QColor ScrollBar::background() const {
    return m_background;
}

QColor ScrollBar::bar() const {
    return m_bar;
}

QColor ScrollBar::barHover() const {
    return m_barHover;
}

void ScrollBar::setBackground(const QColor & background) {
    if (m_background == background)
        return;

    m_background = background;
    emit backgroundChanged(m_background);
}

void ScrollBar::setBar(const QColor & bar) {
    if (m_bar == bar)
        return;

    m_bar = bar;
    emit barChanged(m_bar);
}

void ScrollBar::setBarHover(const QColor & barHover) {
    if (m_barHover == barHover)
        return;

    m_barHover = barHover;
    emit barHoverChanged(m_barHover);
}

void ScrollBar::setUp(const QJsonObject & obj) {
    m_background = objToColor(obj.value("background").toObject());
    m_bar        = objToColor(obj.value("bar").toObject());
    m_barHover   = objToColor(obj.value("bar-hover").toObject());

    emit backgroundChanged(m_background);
    emit barChanged(m_bar);
    emit barHoverChanged(m_barHover);
}

QJsonObject ScrollBar::getUp() {
    return {{"background", colorToObj(m_background)},
            {"bar", colorToObj(m_bar)},
            {"bar-hover", colorToObj(m_barHover)}};
}

}  // namespace icL::look
