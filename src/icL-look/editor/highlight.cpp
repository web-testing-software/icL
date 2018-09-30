#include "highlight.h"

namespace icL::look::editor {

Highlight::Highlight(QObject * parent)
	: QObject(parent) {
	m_background = m_border = QColor(Qt::transparent);
}

QColor Highlight::background() const {
	return m_background;
}

QColor Highlight::border() const {
	return m_border;
}

void Highlight::setBackground(QColor background) {
	if (m_background == background)
		return;

	m_background = background;
	emit backgroundChanged(m_background);
}

void Highlight::setBorder(QColor border) {
	if (m_border == border)
		return;

	m_border = border;
	emit borderChanged(m_border);
}

}  // namespace icL::look::editor
