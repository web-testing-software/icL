#include "mousetracker.h"

#include <QCursor>

namespace icL::toolkit::utils {

MouseTracker::MouseTracker(QObject * parent)
	: QThread(parent) {}

bool MouseTracker::tracking() const {
	return m_tracking;
}

QPoint MouseTracker::position() const {
	return m_position;
}

QPoint MouseTracker::startTracking() {
	start();
	m_tracking = true;
	emit trackingChanged(m_tracking);

	return QCursor::pos();
}

QPoint MouseTracker::stopTracking() {
	m_tracking = false;
	emit trackingChanged(m_tracking);

	return QCursor::pos();
}

void MouseTracker::run() {
	while (m_tracking) {
		QPoint cursor = QCursor::pos();

		if (cursor != m_position) {
			m_position = cursor;
			emit posittionChanged(m_position);
		}
		msleep(8);
	}
}

}  // namespace icL::toolkit::utils
