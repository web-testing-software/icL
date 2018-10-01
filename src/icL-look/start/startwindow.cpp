#include "startwindow.h"

#include "../base/text.h"
#include "side.h"

#include <QJsonObject>

namespace icL::look::start {

StartWindow::StartWindow(QObject * parent)
	: Base(parent) {
	m_header    = new base::Text(this);
	m_left      = new Side(this);
	m_right     = new Side(this);
	m_underline = new base::Text(this);
}

StartWindow::~StartWindow() {
	icL_dropField(m_header);
	icL_dropField(m_left);
	icL_dropField(m_right);
	icL_dropField(m_underline);
}

base::Text * StartWindow::header() const {
	return m_header;
}

Side * StartWindow::left() const {
	return m_left;
}

Side * StartWindow::right() const {
	return m_right;
}

base::Text * StartWindow::underline() const {
	return m_underline;
}

void StartWindow::setUp(const QJsonObject & obj) {
	m_header->setUp(obj.value("header").toObject());
	m_left->setUp(obj.value("left").toObject());
	m_right->setUp(obj.value("right").toObject());
	m_underline->setUp(obj.value("underline").toObject());
}

QJsonObject StartWindow::getUp() {
	return {{"header", m_header->getUp()},
			{"left", m_left->getUp()},
			{"right", m_right->getUp()},
			{"underline", m_underline->getUp()}};
}

}  // namespace icL::look::start
