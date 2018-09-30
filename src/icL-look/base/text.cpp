#include "text.h"

namespace icL::look::base {

Text::Text(QObject * parent)
	: Base(parent) {
	m_background = m_foreground = QColor(Qt::transparent);
}

QColor Text::background() const {
	return m_background;
}

QColor Text::foreground() const {
	return m_foreground;
}

void Text::setBackground(QColor background) {
	if (m_background == background)
		return;

	m_background = background;
	emit backgroundChanged(m_background);
}

void Text::setForeground(QColor foreground) {
	if (m_foreground == foreground)
		return;

	m_foreground = foreground;
	emit foregroundChanged(m_foreground);
}

}  // namespace icL::look::base
