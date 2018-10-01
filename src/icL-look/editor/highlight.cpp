#include "highlight.h"

namespace icL::look::editor {

Highlight::Highlight(QObject * parent)
	: Base(parent) {
	m_background = m_border = QColor(Qt::transparent);
}

QColor Highlight::background() const {
	return m_background;
}

QColor Highlight::border() const {
	return m_border;
}

void Highlight::setUp(const QJsonObject & obj) {
	m_background = objToColor(obj.value("background").toObject());
	m_border     = objToColor(obj.value("border").toObject());

	emit backgroundChanged(m_background);
	emit borderChanged(m_border);
}

QJsonObject Highlight::getUp() {
	return {{"background", colorToObj(m_background)},
			{"border", colorToObj(m_border)}};
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
