#include "gateway.h"

#include <QApplication>

namespace icL::ide {

GateWay::GateWay(QObject * parent)
    : QObject(parent) {}

qreal GateWay::userInterfaceScale() const {
	return m_userInterfaceScale;
}

bool GateWay::startWindowMode() const {
	return m_startWindowMode;
}

QObject * GateWay::crossLook() const {
	return m_crossLook;
}

void GateWay::closeSessionWindows() {
	emit requestToCloseSessionWindows();
}

void GateWay::aboutQt() {
	QApplication::aboutQt();
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

void GateWay::setCrossLook(QObject * crossLook) {
	if (m_crossLook == crossLook)
		return;

	m_crossLook = crossLook;
	emit crossLookChanged(m_crossLook);
}

}  // namespace icL::ide
