#include "startwindow.h"

namespace icL::look::start {

StartWindow::StartWindow(QObject * parent)
	: QObject(parent) {}

StartWindow::~StartWindow() {
	if (m_header != nullptr) {
		delete m_header;
	}

	if (m_left != nullptr) {
		delete m_left;
	}

	if (m_right != nullptr) {
		delete m_right;
	}

	if (m_underline != nullptr) {
		delete m_underline;
	}
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

void StartWindow::setHeader(base::Text * header) {
	if (m_header == header)
		return;

	m_header = header;
	emit headerChanged(m_header);
}

void StartWindow::setLeft(Side * left) {
	if (m_left == left)
		return;

	m_left = left;
	emit leftChanged(m_left);
}

void StartWindow::setRight(Side * right) {
	if (m_right == right)
		return;

	m_right = right;
	emit rightChanged(m_right);
}

void StartWindow::setUnderline(base::Text * underline) {
	if (m_underline == underline)
		return;

	m_underline = underline;
	emit underlineChanged(m_underline);
}


}  // namespace icL::look::start
