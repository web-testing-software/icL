#include "browser.h"

namespace icL::toolkit::panels {

Browser::Browser(QObject * parent)
	: QObject(parent) {}

bool Browser::leftPanel() const {
	return m_leftPanel;
}

bool Browser::navigationBar() const {
	return m_navigationBar;
}

bool Browser::devTools() const {
	return m_devTools;
}

void Browser::setLeftPanel(bool leftPanel) {
	if (m_leftPanel == leftPanel)
		return;

	m_leftPanel = leftPanel;
	emit leftPanelChanged(m_leftPanel);
}

void Browser::setNavigationBar(bool navigationBar) {
	if (m_navigationBar == navigationBar)
		return;

	m_navigationBar = navigationBar;
	emit navigationBarChanged(m_navigationBar);
}

void Browser::setDevTools(bool devTools) {
	if (m_devTools == devTools)
		return;

	m_devTools = devTools;
	emit devToolsChanged(m_devTools);
}

}  // namespace icL::toolkit::panels
