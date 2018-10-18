#include "fragment.h"

#include "line.h"

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
	return m_length;
}

int8_t Fragment::spaces() const {
	return m_spaces;
}

int8_t Fragment::glyphs() const {
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

void Fragment::drop(int begin, int end) {
	content.remove(begin, end - begin);
	m_line->makeChanged();
}

void Fragment::insert(int pos, const QString & text) {
	content.insert(pos, text);
	m_line->makeChanged();
}

void Fragment::replace(int p1, int p2, const QString & after) {
	content.replace(p1, p2, after);
	m_line->makeChanged();
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
