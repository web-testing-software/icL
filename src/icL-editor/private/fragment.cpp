#include "fragment.h"

namespace icL::editor {

Fragment::Fragment(QObject * parent)
	: QObject(parent) {}

Fragment * Fragment::prev() const {
	return m_prev;
}

Fragment * Fragment::next() const {
	return m_next;
}

Line * Fragment::line() const {
	return m_line;
}

uint8_t Fragment::length() const {
	return m_length;
}

int8_t Fragment::spaces() const {
	return m_spaces;
}

int8_t Fragment::glyphs() const {
	return m_glyphs;
}

void Fragment::setPrev(Fragment * prev) {
	if (m_prev == prev)
		return;

	m_prev = prev;
	emit prevChanged(m_prev);
}

void Fragment::setNext(Fragment * next) {
	if (m_next == next)
		return;

	m_next = next;
	emit nextChanged(m_next);
}

void Fragment::setLine(Line * line) {
	if (m_line == line)
		return;

	m_line = line;
	emit lineChanged(m_line);
}

}  // namespace icL::editor
