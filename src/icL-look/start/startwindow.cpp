#include "startwindow.h"

#include "../base/textlook.h"
#include "side.h"

#include <QJsonObject>

namespace icL::look {

StartWindow::StartWindow(QObject * parent)
    : BaseLook(parent) {
    m_header    = new TextLook(this);
    m_left      = new Side(this);
    m_right     = new Side(this);
    m_underline = new TextLook(this);
}

StartWindow::~StartWindow() {
    delete m_header;
    delete m_left;
    delete m_right;
    delete m_underline;
}

TextLook * StartWindow::header() const {
    return m_header;
}

Side * StartWindow::left() const {
    return m_left;
}

Side * StartWindow::right() const {
    return m_right;
}

TextLook * StartWindow::underline() const {
    return m_underline;
}

void StartWindow::setUp(const QJsonObject & obj) {
    m_header->setUp(obj.value("header").toObject());
    m_left->setUp(obj.value("left").toObject());
    m_right->setUp(obj.value("right").toObject());
    m_underline->setUp(obj.value("underline").toObject());
}

QJsonObject StartWindow::getUp() {
    return {{"header", m_header->getUp()},
            {"left", m_left->getUp()},
            {"right", m_right->getUp()},
            {"underline", m_underline->getUp()}};
}

}  // namespace icL::look
