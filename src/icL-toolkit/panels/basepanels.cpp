#include "basepanels.h"

namespace icL::toolkit::panels {

BasePanels::BasePanels(QObject * parent)
	: QObject(parent) {}

bool BasePanels::navigationBar() const {
	return m_navigationBar;
}

bool BasePanels::orientationH() const {
	return m_orientationH;
}

void BasePanels::setNavigationBar(bool navigationBar) {
	if (m_navigationBar == navigationBar)
		return;

	m_navigationBar = navigationBar;
	emit navigationBarChanged(m_navigationBar);
}

void BasePanels::setOrientationH(bool orientationH) {
	if (m_orientationH == orientationH)
		return;

	m_orientationH = orientationH;
	emit orientationHChanged(m_orientationH);
}

}  // namespace icL::toolkit::panels
