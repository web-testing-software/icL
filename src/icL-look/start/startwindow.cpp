#include "startwindow.h"

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

}  // namespace icL::look::start
