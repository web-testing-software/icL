#include "centralside.h"

#include "../base/textlook.h"
#include "../start/input.h"
#include "issue.h"

#include <QJsonObject>

namespace icL::look {

CentralSide::CentralSide(QObject * parent)
    : BaseLook(parent) {
    m_command = m_errorResult = m_okResult = QColor(Qt::transparent);

    m_error      = new Issue(this);
    m_warn       = new Issue(this);
    m_header     = new TextLook(this);
    m_input      = new Input(this);
    m_underdigit = new LinkAdv(this);
    m_undertext  = new LinkAdv(this);
}

CentralSide::~CentralSide() {
    delete m_error;
    delete m_header;
    delete m_input;
    delete m_underdigit;
    delete m_undertext;
    delete m_warn;
}

TextLook * CentralSide::header() const {
    return m_header;
}

Issue * CentralSide::warn() const {
    return m_warn;
}

Issue * CentralSide::error() const {
    return m_error;
}

LinkAdv * CentralSide::undertext() const {
    return m_undertext;
}

LinkAdv * CentralSide::underdigit() const {
    return m_underdigit;
}

QColor CentralSide::command() const {
    return m_command;
}

QColor CentralSide::errorResult() const {
    return m_errorResult;
}

QColor CentralSide::okResult() const {
    return m_okResult;
}

Input * CentralSide::input() const {
    return m_input;
}

void CentralSide::setUp(const QJsonObject & obj) {
    m_header->setUp(obj.value("header").toObject());
    m_warn->setUp(obj.value("warn").toObject());
    m_error->setUp(obj.value("error").toObject());
    m_undertext->setUp(obj.value("undertext").toObject());
    m_underdigit->setUp(obj.value("underdigit").toObject());
    m_input->setUp(obj.value("input").toObject());

    m_command     = objToColor(obj.value("command").toObject());
    m_errorResult = objToColor(obj.value("error-result").toObject());
    m_okResult    = objToColor(obj.value("ok-result").toObject());

    emit commandChanged(m_command);
    emit errorResultChanged(m_errorResult);
    emit okResultChanged(m_okResult);
}

QJsonObject CentralSide::getUp() {
    return {{"header", m_header->getUp()},
            {"warn", m_warn->getUp()},
            {"error", m_error->getUp()},
            {"undertext", m_undertext->getUp()},
            {"underdigit", m_underdigit->getUp()},
            {"input", m_input->getUp()},
            {"command", colorToObj(m_command)},
            {"error-result", colorToObj(m_errorResult)},
            {"ok-result", colorToObj(m_okResult)}};
}

void CentralSide::setCommand(const QColor & command) {
    if (m_command == command)
        return;

    m_command = command;
    emit commandChanged(m_command);
}

void CentralSide::setErrorResult(const QColor & errorResult) {
    if (m_errorResult == errorResult)
        return;

    m_errorResult = errorResult;
    emit errorResultChanged(m_errorResult);
}

void CentralSide::setOkResult(const QColor & okResult) {
    if (m_okResult == okResult)
        return;

    m_okResult = okResult;
    emit okResultChanged(m_okResult);
}

}  // namespace icL::look
