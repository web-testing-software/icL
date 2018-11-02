#include "textlook.h"

#include <QJsonObject>

namespace icL::look {

TextLook::TextLook(QObject * parent)
    : BaseLook(parent) {
	m_background = m_foreground = QColor(Qt::transparent);
}

QColor TextLook::background() const {
	return m_background;
}

QColor TextLook::foreground() const {
	return m_foreground;
}

void TextLook::setUp(const QJsonObject & obj) {
	m_background = objToColor(obj.value("background").toObject());
	m_foreground = objToColor(obj.value("foreground").toObject());

	emit backgroundChanged(m_background);
	emit foregroundChanged(m_foreground);
}

QJsonObject TextLook::getUp() {
	return {{"background", colorToObj(m_background)},
	        {"foreground", colorToObj(m_foreground)}};
}

void TextLook::setBackground(const QColor & background) {
	if (m_background == background)
		return;

	m_background = background;
	emit backgroundChanged(m_background);
}

void TextLook::setForeground(const QColor & foreground) {
	if (m_foreground == foreground)
		return;

	m_foreground = foreground;
	emit foregroundChanged(m_foreground);
}

}  // namespace icL::look
