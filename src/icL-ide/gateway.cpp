#include "gateway.h"

namespace icL::ide {

GateWay::GateWay(QObject * parent)
	: QObject(parent) {}

qreal GateWay::userInterfaceScale() const {
	return m_userInterfaceScale;
}

bool GateWay::startWindowMode() const {
	return m_startWindowMode;
}

void GateWay::closeSessionWindows() {
	emit requestToCloseSessionWindows();
}

void GateWay::setUserInterfaceScale(qreal userInterfaceScale) {
	qWarning("Floating point comparison needs context sanity check");
	if (qFuzzyCompare(m_userInterfaceScale, userInterfaceScale))
		return;

	m_userInterfaceScale = userInterfaceScale;
	emit userInterfaceScaleChanged(m_userInterfaceScale);
}

void GateWay::setStartWindowMode(bool startWindowMode) {
	if (m_startWindowMode == startWindowMode)
		return;

	m_startWindowMode = startWindowMode;
	emit startWindowModeChanged(m_startWindowMode);
}

}  // namespace icL::ide
