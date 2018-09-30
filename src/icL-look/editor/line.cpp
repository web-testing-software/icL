#include "line.h"

namespace icL::look::editor {

Line::Line(QObject * parent)
	: QObject(parent) {}

QColor Line::lineBg() const {
	return m_lineBg;
}

QColor Line::lineNumberBg() const {
	return m_lineNumberBg;
}

QColor Line::lineNumber() const {
	return m_lineNumber;
}

void Line::setLineBg(QColor lineBg) {
	if (m_lineBg == lineBg)
		return;

	m_lineBg = lineBg;
	emit lineBgChanged(m_lineBg);
}

void Line::setLineNumberBg(QColor lineNumberBg) {
	if (m_lineNumberBg == lineNumberBg)
		return;

	m_lineNumberBg = lineNumberBg;
	emit lineNumberBgChanged(m_lineNumberBg);
}

void Line::setLineNumber(QColor lineNumber) {
	if (m_lineNumber == lineNumber)
		return;

	m_lineNumber = lineNumber;
	emit lineNumberChanged(m_lineNumber);
}

}  // namespace icL::look::editor
