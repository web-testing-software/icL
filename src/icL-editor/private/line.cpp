#include "line.h"

namespace icL::editor {

Line::Line(QObject * parent)
	: QObject(parent) {}

Fragment * Line::first() const {
	return m_first;
}

Line * Line::next() const {
	return m_next;
}

Line * Line::prev() const {
	return m_prev;
}

uint8_t Line::length() const {
	return m_length;
}

int32_t Line::beginPos() const {
	return m_beginPos;
}

int16_t Line::lineNumber() const {
	return m_lineNumber;
}

bool Line::visible() const {
	return m_visible;
}

void Line::setFirst(Fragment * first) {
	if (m_first == first)
		return;

	m_first = first;
	emit firstChanged(m_first);
}

void Line::setNext(Line * next) {
	if (m_next == next)
		return;

	m_next = next;
	emit nextChanged(m_next);
}

void Line::setPrev(Line * prev) {
	if (m_prev == prev)
		return;

	m_prev = prev;
	emit prevChanged(m_prev);
}

void Line::setBeginPos(int32_t beginPos) {
	if (m_beginPos == beginPos)
		return;

	m_beginPos = beginPos;
	emit beginPosChanged(m_beginPos);
}

void Line::setLineNumber(int16_t lineNumber) {
	if (m_lineNumber == lineNumber)
		return;

	m_lineNumber = lineNumber;
	emit lineNumberChanged(m_lineNumber);
}

void Line::setVisible(bool visible) {
	if (m_visible == visible)
		return;

	m_visible = visible;
	emit visibleChanged(m_visible);
}

}  // namespace icL::editor
