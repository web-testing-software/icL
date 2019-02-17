#include "line.h"

#include "charformatbase.h"

#include <QJsonObject>

namespace icL::look {

Line::Line(QObject * parent)
    : BaseLook(parent) {
    m_lineBg     = QColor(Qt::transparent);
    m_lineNumber = new CharFormatBase(this);
}

Line::~Line() {
    delete m_lineNumber;
}

QColor Line::lineBg() const {
    return m_lineBg;
}

CharFormatBase * Line::lineNumber() const {
    return m_lineNumber;
}

void Line::setUp(const QJsonObject & obj) {
    m_lineNumber->setUp(obj.value("line-number").toObject());
    m_lineBg = objToColor(obj.value("line-bg").toObject());

    emit lineBgChanged(m_lineBg);
}

QJsonObject Line::getUp() {
    return {{"line-number", m_lineNumber->getUp()},
            {"line-bg", colorToObj(m_lineBg)}};
}

void Line::setLineBg(const QColor & lineBg) {
    if (m_lineBg == lineBg)
        return;

    m_lineBg = lineBg;
    emit lineBgChanged(m_lineBg);
}

CLine::CLine(QObject * parent)
    : Line(parent) {}

QColor CLine::edited() const {
    return m_edited;
}

QColor CLine::saved() const {
    return m_saved;
}

void CLine::setEdited(const QColor & edited) {
    if (m_edited == edited)
        return;

    m_edited = edited;
    emit editedChanged(m_edited);
}

void CLine::setSaved(const QColor & saved) {
    if (m_saved == saved)
        return;

    m_saved = saved;
    emit savedChanged(m_saved);
}

void CLine::setUp(const QJsonObject & obj) {
    Line::setUp(obj);

    m_edited = objToColor(obj.value("edited").toObject());
    m_saved  = objToColor(obj.value("saved").toObject());

    emit editedChanged(m_edited);
    emit savedChanged(m_saved);
}

QJsonObject CLine::getUp() {
    auto obj = Line::getUp();

    obj["edited"] = colorToObj(m_edited);
    obj["saved"]  = colorToObj(m_saved);

    return obj;
}

}  // namespace icL::look
