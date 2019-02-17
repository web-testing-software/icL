#include "code.h"

#include <QJsonObject>

namespace icL::toolkit::panels {

Code::Code(QObject * parent)
    : BasePanels(parent) {}

bool Code::leftPanel() const {
    return m_leftPanel;
}

bool Code::browser() const {
    return m_browser;
}

void Code::setUp(const QJsonObject & obj) {
    BasePanels::setUp(obj);

    m_leftPanel = obj.value("left-panel").toBool();
    m_browser   = obj.value("browser").toBool();
}

QJsonObject Code::getUp() {
    auto obj = BasePanels::getUp();

    obj["left-panel"] = m_leftPanel;
    obj["browser"]    = m_browser;

    return obj;
}

void Code::setLeftPanel(bool leftPanel) {
    if (m_leftPanel == leftPanel)
        return;

    m_leftPanel = leftPanel;
    emit leftPanelChanged(m_leftPanel);
}

void Code::setBrowser(bool browser) {
    if (m_browser == browser)
        return;

    m_browser = browser;
    emit browserChanged(m_browser);
}

}  // namespace icL::toolkit::panels
