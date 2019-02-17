#include "charformat.h"

#include <QJsonObject>

namespace icL::look {

CharFormat::CharFormat(QObject * parent)
    : CharFormatBase(parent) {
    m_undercolor = QColor(Qt::transparent);
    m_underline  = 0;
}

int CharFormat::underline() const {
    return m_underline;
}

QColor CharFormat::undercolor() const {
    return m_undercolor;
}

void CharFormat::setUp(const QJsonObject & obj) {
    CharFormatBase::setUp(obj);

    m_undercolor = objToColor(obj.value("undercolor").toObject());
    m_underline  = obj.value("underline").toInt();
}

QJsonObject CharFormat::getUp() {
    auto obj = CharFormatBase::getUp();

    obj["undercolor"] = colorToObj(m_undercolor);
    obj["underline"]  = m_underline;

    return obj;
}

void CharFormat::setUnderline(int underline) {
    if (m_underline == underline)
        return;

    m_underline = underline;
    emit underlineChanged(m_underline);
}

void CharFormat::setUndercolor(const QColor & undercolor) {
    if (m_undercolor == undercolor)
        return;

    m_undercolor = undercolor;
    emit undercolorChanged(m_undercolor);
}

}  // namespace icL::look
