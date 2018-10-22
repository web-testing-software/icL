#include "fragment.h"

#include "../self/advanced.h"
#include "line.h"
#include "styleproxy.h"

#include <icL-look/editor/editorstyle.h>

#include <QStaticText>

namespace icL::editor {

Fragment::Fragment(Line * parent)
	: QObject(parent) {
	m_line = parent;
}

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
	return m_spaces + m_glyphs;
}

uint8_t Fragment::spaces() const {
	return m_spaces;
}

uint8_t Fragment::glyphs() const {
	return m_glyphs;
}

const QString & Fragment::displayText() {
	return content;
}

Fragment * Fragment::nextFragment() {
	if (m_next != nullptr) {
		return m_next;
	}
	else if (m_line->next() != nullptr) {
		return m_line->next()->first();
	}
	else {
		return nullptr;
	}
}

Fragment * Fragment::prevFragment() {
	if (m_prev != nullptr) {
		return m_prev;
	}
	else if (m_line->prev() != nullptr) {
		auto * it = m_line->prev()->first();

		while (it->next() != nullptr) {
			it = it->next();
		}

		return it;
	}
	else {
		return nullptr;
	}
}

bool Fragment::isCached() {
	return cache != nullptr;
}

void Fragment::cacheNow() {
	if (cache == nullptr) {
		cache = new QStaticText(content);
	}
}

void Fragment::freeCache() {
	if (cache != nullptr) {
		delete cache;
		cache = nullptr;
	}
}

const QStaticText * Fragment::getCache() {
	return cache;
}

Fragment * Fragment::drop(int begin, int end) {
	if (end <= m_spaces) {
		return dropSpaces(begin, end);
	}

	if (begin > m_spaces) {
		if (end >= length()) {
			return dropTail(begin, end);
		}

		return dropContent(begin, end);
	}

	if (end >= length()) {
		return dropAllContent(begin, end);
	}

	return dropHead(begin, end);
}

Fragment * Fragment::insert(int pos, const QString & text) {
	if (pos < m_spaces) {
		return insertInSpaces(pos, text);
	}

	if (pos == m_spaces) {
		return insertAfterSpaces(pos, text);
	}

	if (pos == length()) {
		return insertAfterGlyphs(pos, text);
	}

	return insertInGlyphs(pos, text);
}

Fragment * Fragment::replace(int p1, int p2, const QString & after) {
	// On drop the this fragment may repaced by another
	auto * frag = drop(p1, p2);

	return frag->insert(p1, after);
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

Advanced * Fragment::getEditor() {
	return dynamic_cast<Advanced *>(m_line->parent());
}

}  // namespace icL::editor
