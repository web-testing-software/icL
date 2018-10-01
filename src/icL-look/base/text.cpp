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

void Text::setUp(const QJsonObject & obj) {
	m_background = objToColor(obj.value("background").toObject());
	m_foreground = objToColor(obj.value("foreground").toObject());

	emit backgroundChanged(m_background);
	emit foregroundChanged(m_foreground);
}

QJsonObject Text::getUp() {
	return {{"background", colorToObj(m_background)},
			{"foreground", colorToObj(m_foreground)}};
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
