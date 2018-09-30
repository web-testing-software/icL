#include "sessionwindow.h"

namespace icL::look::session {

SessionWindow::SessionWindow(QObject * parent)
	: Base(parent) {
	m_center   = new CentralSide(this);
	m_floating = new Floating(this);
	m_left     = new LeftSide(this);
	m_top      = new TopBar(this);
}

SessionWindow::~SessionWindow() {
	icL_dropField(m_center);
	icL_dropField(m_floating);
	icL_dropField(m_left);
	icL_dropField(m_top);
}

CentralSide * SessionWindow::center() const {
	return m_center;
}

Floating * SessionWindow::floating() const {
	return m_floating;
}

LeftSide * SessionWindow::left() const {
	return m_left;
}

TopBar * SessionWindow::top() const {
	return m_top;
}

void SessionWindow::setCenter(CentralSide * center) {
	if (m_center == center)
		return;

	m_center = center;
	emit centerChanged(m_center);
}

void SessionWindow::setFloating(Floating * floating) {
	if (m_floating == floating)
		return;

	m_floating = floating;
	emit floatingChanged(m_floating);
}

void SessionWindow::setLeft(LeftSide * left) {
	if (m_left == left)
		return;

	m_left = left;
	emit leftChanged(m_left);
}

void SessionWindow::setTop(TopBar * top) {
	if (m_top == top)
		return;

	m_top = top;
	emit topChanged(m_top);
}

}  // namespace icL::look::session
