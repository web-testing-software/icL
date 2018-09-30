#include "charformat.h"

namespace icL::look::editor {

CharFormat::CharFormat(QObject * parent)
	: CharFormatBase (parent) {}

int CharFormat::underline() const {
	return m_underline;
}

QColor CharFormat::undercolor() const {
	return m_undercolor;
}

void CharFormat::setUnderline(int underline) {
	if (m_underline == underline)
		return;

	m_underline = underline;
	emit underlineChanged(m_underline);
}

void CharFormat::setUndercolor(QColor undercolor) {
	if (m_undercolor == undercolor)
		return;

	m_undercolor = undercolor;
	emit undercolorChanged(m_undercolor);
}

}  // namespace icL::look::editor
