#include "fragment.h"

#include "../self/advanced.h"
#include "line.h"
#include "styleproxy.h"

#include <icL-look/editor/editorstyle.h>

#include <QStaticText>
#include <QStringBuilder>

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

ProcessedGlyphs Fragment::processGlyphs(const QString & text) {
	ProcessedGlyphs pg;
	int             i = 0;

	while (i < text.length() && text[i] != '\n') {
		pg.toInsertHere.append(text[i]);
		i++;
	}

	if (i != text.length()) {
		pg.onNextLine     = true;
		pg.toInsertInNext = text.mid(i);
	}

	return pg;
}

Fragment * Fragment::insertInSpaces(int pos, const QString & text) {
	auto pg = processGlyphs(text);

	if (pg.toInsertInNext.isEmpty()) {
		content.prepend(pg.toInsertHere + QString(' ', m_spaces - pos));
		m_spaces = pos;
		m_glyphs = content.length();
		return this;
	}

	auto * newFrag = makeNewFragment(
	  pg.toInsertInNext % QString(' ', m_spaces - pos) % content,
	  pg.onNextLine);

	content  = pg.toInsertHere;
	m_glyphs = pg.toInsertHere.length();
	m_spaces = pos;

	return newFrag;
}

Fragment * Fragment::insertAfterSpaces(int pos, const QString & text) {
	auto pg = processGlyphs(text);

	if (pg.toInsertInNext.isEmpty()) {
		content.prepend(pg.toInsertHere);
		m_glyphs += pg.toInsertHere.length();
		return this;
	}

	auto * newFrag =
	  makeNewFragment(pg.toInsertInNext + content, pg.onNextLine);

	content  = pg.toInsertHere;
	m_glyphs = pg.toInsertHere.length();

	return newFrag;
}

Fragment * Fragment::insertInGlyphs(int pos, const QString & text) {
	auto pg           = processGlyphs(text);
	int  posInContent = pos - m_spaces;

	if (pg.toInsertInNext.isEmpty()) {
		content.insert(posInContent, pg.toInsertHere);
		m_glyphs += pg.toInsertHere.length();
		return this;
	}

	auto * newFrag = makeNewFragment(
	  pg.toInsertInNext + content.mid(posInContent), pg.onNextLine);

	content.replace(
	  posInContent, content.length() - posInContent, pg.toInsertHere);
	m_glyphs = content.length();

	return newFrag;
}

Fragment * Fragment::insertAfterGlyphs(int pos, const QString & text) {
	auto pg = processGlyphs(text);

	content.append(pg.toInsertHere);
	m_glyphs += pg.toInsertHere.length();

	if (pg.toInsertInNext.isEmpty()) {
		return this;
	}

	return makeNewFragment(pg.toInsertInNext, pg.onNextLine);
}

Fragment * Fragment::makeNewFragment(const QString & text, bool onNewLine) {
	int tabSize = getEditor()->proxy()->tabSize();
	int spaces  = 0;
	int i       = 0;

	while (i < text.length() && text[i].isSpace()) {
		if (text[i] == '\t') {
			spaces += tabSize;
		}
		else if (text[i] == '\n') {
			auto * newFrag = makeFragmentNow(FragmentTypes::Fragment, true);

			newFrag->m_spaces = spaces;
			return newFrag->makeNewFragment(text.mid(i), true);
		}
		else {
			spaces++;
		}
	}

	if (i == text.length()) {
		auto * newFrag = makeFragmentNow(FragmentTypes::Fragment, onNewLine);

		newFrag->m_spaces = spaces;
		return newFrag;
	}

	Fragment * ret;

	switch (text[i].toLatin1()) {
	case '{':
	case '}':
	case '(':
	case ')':
	case '[':
	case ']':
		ret = makeFragmentNow(FragmentTypes::Bracket, false);
		break;

	default:
		ret = makeFragmentNow(FragmentTypes::Fragment, onNewLine);
		break;
	}

	ret->m_spaces = spaces;
	ret->insert(spaces, text.mid(spaces));

	return ret;
}

Fragment * Fragment::makeFragmentNow(FragmentTypes type, bool onNewLine) {
	Fragment * ret    = nullptr;
	Line *     parent = nullptr;

	if (onNewLine) {
		parent = new Line(m_line->parent());
		getEditor()->addNewLine(parent);
	}
	else {
		parent = m_line;
	}

	switch (type) {
	case FragmentTypes::Fragment:
		ret = new Fragment(parent);
		break;

		//	default:
		// TODO: Write it later
	}

	if (onNewLine) {
		parent->setFirst(ret);
	}
	else {
		ret->m_prev = this;
		m_next      = ret;
	}

	return ret;
}

}  // namespace icL::editor
