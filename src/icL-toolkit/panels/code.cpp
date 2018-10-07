#include "code.h"

namespace icL::toolkit::panels {

Code::Code(QObject * parent)
	: QObject(parent) {}

bool Code::leftPanel() const {
	return m_leftPanel;
}

bool Code::browser() const {
	return m_browser;
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
