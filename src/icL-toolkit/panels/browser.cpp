#include "browser.h"

#include <QJsonObject>

namespace icL::toolkit::panels {

Browser::Browser(QObject * parent)
    : BasePanels(parent) {}

bool Browser::leftPanel() const {
	return m_leftPanel;
}

bool Browser::devTools() const {
	return m_devTools;
}

void Browser::setUp(const QJsonObject & obj) {
	BasePanels::setUp(obj);

	m_leftPanel = obj.value("left-panel").toBool();
	m_devTools  = obj.value("dev-tools").toBool();
}

QJsonObject Browser::getUp() {
	auto obj = BasePanels::getUp();

	obj["left-panel"] = m_leftPanel;
	obj["dev-tools"]  = m_devTools;

	return obj;
}

void Browser::setLeftPanel(bool leftPanel) {
	if (m_leftPanel == leftPanel)
		return;

	m_leftPanel = leftPanel;
	emit leftPanelChanged(m_leftPanel);
}

void Browser::setDevTools(bool devTools) {
	if (m_devTools == devTools)
		return;

	m_devTools = devTools;
	emit devToolsChanged(m_devTools);
}

}  // namespace icL::toolkit::panels
