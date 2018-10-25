#include "fragment.h"

#include "../private/line.h"
#include "../private/styleproxy.h"
#include "../self/advanced.h"
#include "bracket.h"
#include "string.h"
#include "word.h"

#include <icL-look/export/chars.h>

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

	if (m_line->next() != nullptr) {
		return m_line->next()->first();
	}

	return nullptr;
}

Fragment * Fragment::prevFragment() {
	if (m_prev != nullptr) {
		return m_prev;
	}
	if (m_line->prev() != nullptr) {
		auto * it = m_line->prev()->first();

		while (it->next() != nullptr) {
			it = it->next();
		}

		return it;
	}

	return nullptr;
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
		return dropAllContent(begin);
	}

	return dropHead(begin, end);
}

Fragment * Fragment::insert(int pos, const QString & text) {
	if (pos < m_spaces) {
		return insertInSpaces(pos, text);
	}

	if (pos == length()) {
		return insertAfterGlyphs(text);
	}

	if (pos == m_spaces) {
		return insertAfterSpaces(text);
	}

	return insertInGlyphs(pos, text);
}

Fragment * Fragment::replace(int p1, int p2, const QString & after) {
	// On drop this fragment may repaced by another
	auto * frag = drop(p1, p2);

	return frag->insert(p1, after);
}

bool Fragment::isBracket() {
	return false;
}

bool Fragment::isOpenBracket() {
	return false;
}

const look::TextCharFormat & Fragment::format() {
	return getEditor()->chars()->text;
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
	const QString   restrictedChars = "\n{}[]()\"";

	int i       = 0;
	int tabSize = getEditor()->proxy()->tabSize();

	while (i < text.length() && !restrictedChars.contains(text[i])) {
		if (text[i] == '\t') {
			pg.toInsertHere.append(QString(tabSize, ' '));
		}
		else {
			pg.toInsertHere.append(text[i]);
		}
		i++;
	}

	if (i != text.length()) {
		pg.onNextLine     = text[i] == '\n';
		pg.toInsertInNext = text.mid(i);
	}

	return pg;
}

Fragment * Fragment::insertInSpaces(int pos, const QString & text) {
	auto pg = processGlyphs(text);

	if (pg.toInsertInNext.isEmpty()) {
		content.prepend(pg.toInsertHere + QString(m_spaces - pos, ' '));
		m_spaces = pos;
		m_glyphs = content.length();
		return this;
	}

	auto * newFrag = makeNewFragment(
	  pg.toInsertInNext % QString(m_spaces - pos, ' ') % content,
	  pg.onNextLine);

	content  = pg.toInsertHere;
	m_glyphs = pg.toInsertHere.length();
	m_spaces = pos;

	return newFrag;
}

Fragment * Fragment::insertAfterSpaces(const QString & text) {
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

Fragment * Fragment::insertAfterGlyphs(const QString & text) {
	auto pg = processGlyphs(text);

	if (content.isEmpty()) {
		int i = 0;

		while (pg.toInsertHere[i].isSpace()) {
			i++;
		}

		m_spaces += i;
		content.append(pg.toInsertHere.midRef(i));
		m_glyphs += pg.toInsertHere.length() - i;
	}
	else {
		content.append(pg.toInsertHere);
		m_glyphs += pg.toInsertHere.length();
	}

	if (pg.toInsertInNext.isEmpty()) {
		return this;
	}

	return makeNewFragment(pg.toInsertInNext, pg.onNextLine);
}

Fragment * Fragment::dropSpaces(int p1, int p2) {
	m_spaces -= p2 - p1;
	return this;
}

Fragment * Fragment::dropHead(int p1, int p2) {
	m_spaces -= m_spaces - p1;
	content.remove(0, p2 - m_spaces);
	m_glyphs = content.length();
	return this;
}

Fragment * Fragment::dropContent(int p1, int p2) {
	content.remove(p1 - m_spaces, p2 - p1);
	m_glyphs = content.length();
	return this;
}

Fragment * Fragment::dropTail(int p1, int p2) {
	return dropContent(p1, p2);
}

Fragment * Fragment::dropAllContent(int p1) {
	auto * newFrag = new Fragment(m_line);

	newFrag->m_spaces = m_spaces - p1;
	newFrag->m_prev   = m_prev;
	newFrag->m_next   = m_next;

	if (m_prev != nullptr) {
		m_prev->m_next = newFrag;
	}

	if (m_next != nullptr) {
		m_next->m_prev = newFrag;
	}

	delete this;
	return newFrag;
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

		i++;
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

	case '"':
		ret = makeFragmentNow(FragmentTypes::String, false);
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

	case FragmentTypes::Bracket:
		ret = new Bracket(parent);
		break;

	case FragmentTypes::String:
		ret = new String(parent);
		break;

	case FragmentTypes::Word:
		ret = new Word(parent);
		break;
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
