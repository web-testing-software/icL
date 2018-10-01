#include "sessionwindow.h"

#include "centralside.h"
#include "floating.h"
#include "leftside.h"
#include "topbar.h"

#include <QJsonObject>

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

void SessionWindow::setUp(const QJsonObject & obj) {
	m_center->setUp(obj.value("center").toObject());
	m_floating->setUp(obj.value("floating").toObject());
	m_left->setUp(obj.value("left").toObject());
	m_top->setUp(obj.value("top").toObject());
}

QJsonObject SessionWindow::getUp() {
	return {{"center", m_center->getUp()},
			{"floating", m_floating->getUp()},
			{"left", m_left->getUp()},
			{"top", m_top->getUp()}};
}

}  // namespace icL::look::session
