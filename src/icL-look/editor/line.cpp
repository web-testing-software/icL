#include "line.h"

namespace icL::look::editor {

Line::Line(QObject * parent)
	: QObject(parent) {
	m_lineBg     = QColor(Qt::transparent);
	m_lineNumber = new CharFormatBase(this);
}

Line::~Line() {
	icL_dropField(m_lineNumber);
}

QColor Line::lineBg() const {
	return m_lineBg;
}

CharFormatBase * Line::lineNumber() const {
	return m_lineNumber;
}

void Line::setLineBg(QColor lineBg) {
	if (m_lineBg == lineBg)
		return;

	m_lineBg = lineBg;
	emit lineBgChanged(m_lineBg);
}

void Line::setLineNumber(CharFormatBase * lineNumber) {
	if (m_lineNumber == lineNumber)
		return;

	m_lineNumber = lineNumber;
	emit lineNumberChanged(m_lineNumber);
}

}  // namespace icL::look::editor
