#include "fragment.h"

#include "../private/cursor.h"
#include "../private/line.h"
#include "../private/styleproxy.h"
#include "../self/editorinternal.h"
#include "bracket.h"
#include "string.h"
#include "word.h"

#include <icL-look/export/chars.h>

#include <QStaticText>
#include <QStringBuilder>

namespace icL::editor {

Fragment::Fragment(Line * parent) {
	m_line = parent;

	if (m_line->visible()) {
		cacheNow();
	}
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

const QString Fragment::getText(int begin, int end) {
	if (end < 0) {
		end = length();
	}

	QString ret;

	if (begin < m_spaces) {
		if (end > m_spaces) {
			ret += QString(m_spaces - begin, ' ');
			ret += content.midRef(0, end - m_spaces);
		}
		else {
			ret += QString(end - begin, ' ');
		}
	}
	else {
		ret += content.midRef(begin - m_spaces, end - begin);
	}

	return ret;
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

Fragment * Fragment::drop(Cursor * cursor, int begin, int end) {
	Fragment * ret;

	if (end < 0) {
		end = length();
	}

	if (begin == end) {
		return this;
	}

	if (end <= m_spaces && m_glyphs > 0) {
		ret = dropSpaces(cursor, begin, end);
	}
	else if (begin > m_spaces) {
		if (end >= length()) {
			ret = dropTail(cursor, begin, end);
		}
		else {
			ret = dropContent(cursor, begin, end);
		}
	}
	else if (end >= length()) {
		ret = dropAllContent(cursor, begin);
	}
	else {
		ret = dropHead(cursor, begin, end);
	}

	if (cache != nullptr) {
		cache->setText(content);
	}

	m_line->makeChanged();
	//	qDebug() << m_glyphs;

	return ret;
}

Fragment * Fragment::insert(
  Cursor * begin, Cursor * end, int pos, const QString & text) {
	Fragment * ret;

	if (text.isEmpty()) {
		return this;
	}

	if (pos < m_spaces) {
		ret = insertInSpaces(begin, end, pos, text);
	}
	else if (pos == length()) {
		ret = insertAfterGlyphs(begin, end, text);
	}
	else if (pos == m_spaces) {
		ret = insertAfterSpaces(begin, end, text);
	}
	else {
		ret = insertInGlyphs(begin, end, pos, text);
	}

	if (cache != nullptr) {
		cache->setText(content);
	}

	bool isLoadingFile =
	  dynamic_cast<Drawing *>(m_line->parent())->linesCount() == 0;
	bool isEndOfLine = pos == length() && m_next == nullptr && text[0] == '\n';

	if (!isLoadingFile && !isEndOfLine) {
		m_line->makeChanged();
	}
	if (isEndOfLine) {
		m_line->next()->makeChanged();
	}

	return ret;
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

bool Fragment::isReadOnly() {
	return readOnly;
}

void Fragment::setReadOnly(bool value) {
	readOnly = value;
}

void Fragment::setPrev(Fragment * prev) {
	if (m_prev == prev)
		return;

	m_prev = prev;
}

void Fragment::setNext(Fragment * next) {
	if (m_next == next)
		return;

	m_next = next;
}

void Fragment::setLine(Line * line) {
	if (m_line == line)
		return;

	m_line = line;
}

EditorInternal * Fragment::getEditor() {
	return dynamic_cast<EditorInternal *>(m_line->parent());
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
		pg.toInsertInNext = text.mid(pg.onNextLine ? i + 1 : i);
	}

	return pg;
}

Fragment * Fragment::insertInSpaces(
  Cursor * begin, Cursor * end, int pos, const QString & text) {
	auto pg = processGlyphs(text);

	if (pg.toInsertInNext.isEmpty() && !pg.onNextLine) {
		int spaces = countSpacesAtBegin(pg.toInsertHere);

		if (spaces == pg.toInsertHere.length()) {
			m_spaces += spaces;

			end->setPosition(pos + spaces);
			end->setFragment(this);
			return this;
		}

		content.prepend(QString(m_spaces - pos, ' '));
		content.prepend(pg.toInsertHere.midRef(spaces));

		m_spaces = pos + spaces;
		m_glyphs = content.length();

		end->setPosition(m_spaces + pg.toInsertHere.length());
		end->setFragment(this);

		return this;
	}

	auto * newFrag = makeNewFragment(
	  begin, end, pg.toInsertInNext % QString(m_spaces - pos, ' ') % content,
	  pg.onNextLine);
	int spaces = countSpacesAtBegin(pg.toInsertHere);

	end->stepBackward(m_spaces - pos + content.length(), end);

	content  = pg.toInsertHere.mid(spaces);
	m_glyphs = pg.toInsertHere.length() - spaces;
	m_spaces = pos + spaces;

	return newFrag;
}

Fragment * Fragment::insertAfterSpaces(
  Cursor * begin, Cursor * end, const QString & text) {
	auto pg = processGlyphs(text);

	if (pg.toInsertInNext.isEmpty() && !pg.onNextLine) {
		int spaces = countSpacesAtBegin(pg.toInsertHere);

		end->setPosition(m_spaces + pg.toInsertHere.length());
		end->setFragment(this);

		content.prepend(pg.toInsertHere.midRef(spaces));

		m_spaces += spaces;
		m_glyphs += pg.toInsertHere.length() - spaces;

		return this;
	}

	auto * newFrag =
	  makeNewFragment(begin, end, pg.toInsertInNext + content, pg.onNextLine);

	end->stepBackward(content.length(), end);

	content  = pg.toInsertHere;
	m_glyphs = pg.toInsertHere.length();

	return newFrag;
}

Fragment * Fragment::insertInGlyphs(
  Cursor * begin, Cursor * end, int pos, const QString & text) {

	auto pg           = processGlyphs(text);
	int  posInContent = pos - m_spaces;

	if (pg.toInsertInNext.isEmpty() && !pg.onNextLine) {
		content.insert(posInContent, pg.toInsertHere);
		m_glyphs += pg.toInsertHere.length();

		end->setPosition(pos + pg.toInsertHere.length());
		end->setFragment(this);

		return this;
	}

	auto * newFrag = makeNewFragment(
	  begin, end, pg.toInsertInNext + content.mid(posInContent), pg.onNextLine);

	end->stepBackward(content.length() - posInContent, end);

	content.replace(
	  posInContent, content.length() - posInContent, pg.toInsertHere);
	m_glyphs = content.length();

	return newFrag;
}

Fragment * Fragment::insertAfterGlyphs(
  Cursor * begin, Cursor * end, const QString & text) {
	auto pg = processGlyphs(text);

	if (content.isEmpty()) {
		int spaces = countSpacesAtBegin(pg.toInsertHere);

		content.append(pg.toInsertHere.midRef(spaces));

		m_spaces += spaces;
		m_glyphs += pg.toInsertHere.length() - spaces;
	}
	else {
		content.append(pg.toInsertHere);
		m_glyphs += pg.toInsertHere.length();
	}

	if (pg.toInsertInNext.isEmpty() && !pg.onNextLine) {
		end->setPosition(m_glyphs + m_spaces);
		end->setFragment(this);

		return this;
	}

	return makeNewFragment(begin, end, pg.toInsertInNext, pg.onNextLine);
}

Fragment * Fragment::dropSpaces(Cursor * cursor, int p1, int p2) {
	m_spaces -= p2 - p1;

	cursor->setPosition(p1);
	cursor->setFragment(this);

	return this;
}

Fragment * Fragment::dropHead(Cursor * cursor, int p1, int p2) {
	if (p2 <= m_spaces) {
		m_spaces -= p2 - p1;

		cursor->setPosition(p1);
		cursor->setFragment(this);

		return this;
	}

	content.remove(0, p2 - m_spaces);
	m_spaces -= m_spaces - p1;
	m_glyphs = content.length();

	cursor->setPosition(p1);
	cursor->setFragment(this);

	return this;
}

Fragment * Fragment::dropContent(Cursor * cursor, int p1, int p2) {
	content.remove(p1 - m_spaces, p2 - p1);
	m_glyphs = content.length();

	cursor->setPosition(p1);
	cursor->setFragment(this);

	return this;
}

Fragment * Fragment::dropTail(Cursor * cursor, int p1, int p2) {
	return dropContent(cursor, p1, p2);
}

Fragment * Fragment::dropAllContent(Cursor * cursor, int p1) {

	// We are deleting all content
	if (p1 == 0) {

		// This fragment has no neighbords
		if (m_next == nullptr && m_prev == nullptr) {
			m_spaces = 0;
			m_glyphs = 0;
			content.clear();

			cursor->setFragment(this);
			cursor->setPosition(0);

			return this;
		}

		// This fragment is first in line
		if (m_prev == nullptr) {
			m_next->m_prev = nullptr;
			m_line->setFirst(m_next);

			cursor->setFragment(m_next);
			cursor->setPosition(0);

			delete this;

			return m_next;
		}

		// This fragment has a previous fragment

		if (m_next != nullptr) {
			m_next->m_prev = m_prev;
		}
		m_prev->m_next = m_next;

		cursor->setFragment(m_prev);
		cursor->setPosition(m_prev->length());

		delete this;

		return m_prev;
	}

	// We are deleting just glyphs and maybe some spaces

	auto * newFrag = new Fragment(m_line);

	newFrag->m_spaces = p1;
	newFrag->m_prev   = m_prev;
	newFrag->m_next   = m_next;

	if (m_prev != nullptr) {
		m_prev->m_next = newFrag;
	}
	else {
		m_line->setFirst(newFrag);
	}

	if (m_next != nullptr) {
		m_next->m_prev = newFrag;
	}

	if (m_line->visible()) {
		newFrag->cacheNow();
	}

	delete this;

	cursor->setPosition(newFrag->m_spaces);
	cursor->setFragment(newFrag);

	return newFrag;
}

Fragment * Fragment::makeNewFragment(
  Cursor * begin, Cursor * end, const QString & text, bool onNewLine) {
	int tabSize = getEditor()->proxy()->tabSize();
	int spaces  = 0;
	int i       = 0;

	while (i < text.length() && text[i].isSpace()) {
		if (text[i] == '\t') {
			spaces += tabSize;
		}
		else if (text[i] == '\n') {
			auto * newFrag = makeFragmentNow(FragmentTypes::Fragment, false);

			newFrag->m_spaces = spaces;
			return newFrag->makeNewFragment(begin, end, text.mid(i + 1), true);
		}
		else {
			spaces++;
		}

		i++;
	}

	if (i == text.length()) {
		auto * newFrag = makeFragmentNow(FragmentTypes::Fragment, onNewLine);

		newFrag->m_spaces = spaces;
		end->setFragment(newFrag);
		end->setPosition(spaces);
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
	ret->insert(begin, end, spaces, text.mid(spaces));

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
		if (m_next != nullptr) {
			m_next->m_prev = ret;
		}

		ret->m_next = m_next;
		ret->m_prev = this;
		m_next      = ret;
	}

	if (onNewLine) {
		moveNextBlockAfter(ret);
	}

	return ret;
}

void Fragment::ensurePrev() {
	if (m_prev == nullptr) {
		m_prev = new Fragment(m_line);

		m_prev->m_next = this;
		m_line->setFirst(m_prev);
	}
}

void Fragment::moveNextBlockAfter(Fragment * after) {
	auto * it = m_next;

	while (it != nullptr) {
		it->setLine(after->m_line);
		it = it->m_next;
	}

	if (m_next != nullptr) {
		after->m_next  = m_next;
		m_next->m_prev = after;
	}
	m_next = nullptr;
}

int Fragment::countSpacesAtBegin(const QString & text) {
	int ret = 0;

	while (ret < text.length() && text[ret] == ' ') {
		ret++;
	}

	return ret;
}

int Fragment::countSpacesAtEnd(const QString & text) {
	int ret = 0;
	int max = text.length();

	while (text[max - ret - 1] == ' ' && ret < max) {
		ret++;
	}

	return ret;
}

}  // namespace icL::editor
