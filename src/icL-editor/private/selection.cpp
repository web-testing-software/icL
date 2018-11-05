#include "selection.h"

#include "../fragment/fragment.h"
#include "../self/editorinternal.h"
#include "cursor.h"
#include "line.h"

namespace icL::editor {

Selection::Selection() {
	m_begin = new Cursor();
	m_end   = new Cursor();
}

Selection::~Selection() {
	delete m_begin;
	delete m_end;
}

Cursor * Selection::begin() const {
	return m_begin;
}

Cursor * Selection::end() const {
	return m_end;
}

Selection * Selection::prev() const {
	return m_prev;
}

Selection * Selection::next() const {
	return m_next;
}

bool Selection::rtl() const {
	return m_rtl;
}

QString Selection::getText() {
	auto * beginFrag = m_begin->fragment();
	auto * endFrag   = m_end->fragment();

	if (beginFrag == endFrag) {
		return m_begin->fragment()->getText(
		  m_begin->position(), m_end->position());
	}

	QString ret = beginFrag->getText(m_begin->position());

	if (beginFrag->next() == nullptr) {
		ret += '\n';
	}

	auto * it = beginFrag->nextFragment();

	while (it != endFrag) {
		ret += it->getText();

		if (it->next() == nullptr) {
			ret += '\n';
		}

		it = it->nextFragment();
	}

	ret += endFrag->getText(0, m_end->position());

	return ret;
}

void Selection::move(int step, bool select) {
	if (select) {
		setRtlByStep(step);

		if (m_rtl) {
			moveSelect(step, m_begin, m_end);
		}
		else {
			moveSelect(step, m_end, m_begin);
		}
	}
	else {
		unifyCursors();

		if (step < 0) {
			m_begin->stepBackward(-step, m_begin);
			m_begin->updatePreffered();
			m_end->syncWith(m_begin);
		}
		else {
			m_end->stepForward(step, m_end);
			m_end->updatePreffered();
			m_begin->syncWith(m_end);
		}
	}

	m_begin->getEditor()->makeCursorOpaque();
	m_begin->getEditor()->updateCurrentLine();
}

void Selection::moveOverWords(int words, bool select) {
	if (select) {
		setRtlByStep(words);

		if (m_rtl) {
			moveSelectOverWords(words, m_begin, m_end);
		}
		else {
			moveSelectOverWords(words, m_end, m_begin);
		}
	}
	else {
		unifyCursors();

		if (words < 0) {
			m_begin->stepWordsBackward(-words, m_begin);
			m_begin->updatePreffered();
			m_end->syncWith(m_begin);
		}
		else {
			m_end->stepWordsForward(words, m_end);
			m_end->updatePreffered();
			m_begin->syncWith(m_end);
		}
	}

	m_begin->getEditor()->makeCursorOpaque();
	m_begin->getEditor()->updateCurrentLine();
}

void Selection::moveUpDown(int lines, bool select) {
	if (select) {
		setRtlByStep(lines);

		if (m_rtl) {
			moveSelectOverLines(lines, m_begin, m_end);
		}
		else {
			moveSelectOverLines(lines, m_end, m_begin);
		}
	}
	else {
		unifyCursors();

		if (lines < 0) {
			m_begin->stepLinesUp(-lines, m_begin);
			m_end->syncWith(m_begin);
		}
		else {
			m_end->stepLinesDown(lines, m_end);
			m_begin->syncWith(m_end);
		}
	}

	m_begin->getEditor()->makeCursorOpaque();
	m_begin->getEditor()->updateCurrentLine();
}

QString Selection::drop() {
	// If the selection is empty
	if (*m_begin == *m_end) {
		return {};
	}

	bool notEditable = false;

	// Test if is editable first

	auto * it = m_begin->fragment();

	while (it != m_end->fragment()) {
		notEditable = notEditable || it->isReadOnly();
		it          = it->nextFragment();
	}

	if (notEditable) {
		return {};
	}

	// The content is editable

	QString retAfter = getText();

	// Drop frgment from begin line

	auto * beginFrag = m_begin->fragment();
	auto * endFrag   = m_end->fragment();
	auto * editor    = beginFrag->line()->parent();

	if (beginFrag != endFrag) {

		// make begin line phantom if is removed completly
		if (beginFrag->prev() == nullptr && m_begin->position() == 0) {
			auto * beginLine = beginFrag->line();
			auto * prevLine  = beginLine->prev();
			auto * nextLine  = beginLine->next();

			auto * newLine = new Line(beginLine->parent(), beginLine->isNew());
			auto * newFrag = new Fragment(newLine);

			beginLine->makePhantom();

			newLine->setFirst(newFrag);

			if (prevLine != nullptr) {
				prevLine->setNext(newLine);
				newLine->setPrev(prevLine);
			}
			if (nextLine != nullptr) {
				nextLine->setPrev(newLine);
				newLine->setNext(nextLine);
			}

			m_begin->setFragment(newFrag);
			m_begin->setPosition(0);
		}
		// Remove a fragment of line
		else if (m_begin->position() != beginFrag->length()) {
			beginFrag->drop(m_begin, m_begin->position());
			beginFrag->line()->makeChanged();
		}

		if (m_end->position() != 0) {
			endFrag->drop(m_end, 0, m_end->position());
			endFrag->line()->makeChanged();
		}

		// beginFrag and end fragments can be deleted on content drop
		beginFrag = m_begin->fragment();
		endFrag   = m_end->fragment();

		while (beginFrag->next() != nullptr) {
			auto * tmp = beginFrag->next()->next();

			delete beginFrag->next();
			beginFrag->setNext(tmp);
		}
	}
	else {
		beginFrag->drop(m_begin, m_begin->position(), m_end->position());
	}

	// Drop lines beetwen begin line and end line

	auto * beginLine = beginFrag->line();

	if (beginLine != endFrag->line()) {
		while (beginLine->next() != endFrag->line()) {
			auto * next = beginLine->next();

			beginLine->makePhantom();
			beginLine = next;
		}

		auto * endLine = endFrag->line();

		// If we are deleting all end line
		if (
		  m_end->position() == endFrag->length() &&
		  endFrag->next() == nullptr) {
			endLine->makePhantom();
		}

		// If you are deleting a part of end line
		else {

			// Drop fragment from end line

			while (endFrag->prev() != nullptr) {
				auto * tmp = endFrag->prev()->prev();

				delete endFrag->next();
				endFrag->setNext(tmp);
			}

			// Merge begin and end line

			auto * itFrag = endFrag;

			beginLine->setNext(endFrag->line()->next());
			if (endLine->next() != nullptr) {
				endLine->next()->setPrev(beginLine);
			}

			while (itFrag != nullptr) {
				itFrag->setLine(beginLine);
				itFrag = itFrag->next();
			}

			beginFrag->setNext(endFrag);
			endFrag->setPrev(beginFrag);

			// Delete first frag if empty

			if (beginFrag->spaces() == 0 && beginFrag->glyphs() == 0) {
				endFrag->setPrev(beginFrag->prev());

				if (beginFrag->line()->first() == beginFrag) {
					beginFrag->line()->setFirst(endFrag);
				}

				endFrag->setPrev(nullptr);

				if (m_begin->fragment() == beginFrag) {
					m_begin->setFragment(endFrag);
					m_begin->setPosition(0);
				}
			}

			if (
			  endFrag->spaces() == 0 && endFrag->glyphs() == 0 &&
			  (endFrag->prev() != nullptr || endFrag->next() != nullptr)) {

				if (endFrag->next() != nullptr) {
					endFrag->next()->setPrev(endFrag->prev());
				}

				if (endFrag->prev() != nullptr) {
					endFrag->prev()->setNext(endFrag->next());
				}

				if (endFrag->line()->first() == endFrag) {
					endFrag->line()->setFirst(endFrag->next());
				}

				if (m_begin->fragment() == endFrag) {
					m_begin->setFragment(endFrag->next());
					m_begin->setPosition(0);
				}

				delete endFrag;
			}

			if (endLine == editor->firstVisible()) {
				editor->setFirstVisible(beginLine);
			}

			delete endLine;
		}
	}

	m_end->syncWith(m_begin);
	m_begin->fragment()->line()->updateLength();
	m_begin->getEditor()->updateCurrentLine();
	m_begin->fragment()->line()->fixLines();

	return retAfter;
}

QString Selection::backspace() {
	if (*m_begin != *m_end) {
		return drop();
	}

	m_begin->stepBackward(1, m_end);
	setRtl(true);
	return drop();
}

QString Selection::delete1() {
	if (*m_begin != *m_end) {
		return drop();
	}

	m_end->stepForward(1, m_begin);
	setRtl(false);
	return drop();
	return {};
}

QString Selection::insert(const QString & text) {
	// If the selection is not empty
	if (*m_begin != *m_end) {
		return {};
	}

	m_end->fragment()->insert(m_begin, m_end, m_end->position(), text);

	QString retAfter = getText();

	// Update the length of edited lines
	auto * it = m_begin->fragment()->line();

	do {
		it->updateLength();
		it = it->next();
	} while (it != m_end->fragment()->line()->next());

	m_end->updatePreffered();
	m_begin->syncWith(m_end);
	m_begin->getEditor()->updateCurrentLine();
	m_begin->fragment()->line()->fixLines();

	return retAfter;
}

void Selection::setNext(Selection * next) {
	if (m_next == next)
		return;

	m_next = next;
}

void Selection::setRtl(bool rtl) {
	if (m_rtl == rtl)
		return;

	m_rtl = rtl;
}

void Selection::beginSelection(int line, int ch) {
	moveCursorToLine(line, m_begin);
	m_begin->setPreffered(ch);
	m_begin->matchPreffered();

	m_end->syncWith(m_begin);
}

void Selection::selectTo(int line, int ch) {
	// Nothing selected yet
	Cursor * toMove;
	if (*m_begin == *m_end) {
		if (isAfter(m_begin, line, ch)) {
			toMove = m_end;
			setRtl(false);
		}
		else {
			toMove = m_begin;
			setRtl(true);
		}
	}
	// Current selection is RTL
	else if (m_rtl) {
		// If the selection gets wrong
		if (isAfter(m_end, line, ch)) {
			m_begin->syncWith(m_end);
			toMove = m_end;
			setRtl(false);
		}
		// If is all ok
		else {
			toMove = m_begin;
		}
	}
	// Current selection mode is !RTL
	else {
		// If the selection gets wrong
		if (!isAfter(m_begin, line, ch)) {
			m_end->syncWith(m_begin);
			toMove = m_begin;
			setRtl(true);
		}
		// If all is ok
		else {
			toMove = m_end;
		}
	}

	// Move needed cursor
	if (!moveCursorToLine(line, toMove)) {
		if (line < 1) {
			ch = 0;
		}
		else {
			ch = toMove->fragment()->line()->length();
		}
	}
	toMove->setPreffered(ch);
	toMove->matchPreffered();
}

void Selection::finishSelection() {}

void Selection::moveSelect(int step, Cursor * begin, Cursor * end) {
	if (step < 0) {
		begin->stepBackward(-step, end);
	}
	else {
		begin->stepForward(step, end);
	}

	begin->updatePreffered();
}

void Selection::moveSelectOverWords(int words, Cursor * begin, Cursor * end) {
	if (words < 0) {
		begin->stepWordsBackward(-words, end);
	}
	else {
		begin->stepWordsForward(words, end);
	}

	begin->updatePreffered();
}

void Selection::moveSelectOverLines(int lines, Cursor * begin, Cursor * end) {
	if (lines < 0) {
		begin->stepLinesUp(-lines, end);
	}
	else {
		begin->stepLinesDown(lines, end);
	}
}

void Selection::unifyCursors() {
	if (m_rtl) {
		m_end->syncWith(m_begin);
	}
	else {
		m_begin->syncWith(m_end);
	}
}

void Selection::setRtlByStep(int step) {
	if (*m_begin == *m_end) {
		if (step > 0) {
			setRtl(false);
		}
		else {
			setRtl(true);
		}
	}
}

bool Selection::moveCursorToLine(int line, Cursor * cursor) {
	auto * lineIt        = cursor->fragment()->line();
	int    currentLineNr = lineIt->lineNumber();

	bool ret = true;

	// Fix line values
	int maxValue = dynamic_cast<Drawing *>(lineIt->parent())->linesCount();

	if (line < 1) {
		line = 1;
		ret  = false;
	}
	else if (line > maxValue) {
		line = maxValue;
		ret  = false;
	}

	if (currentLineNr > line) {
		while (lineIt->lineNumber() != line) {
			lineIt = lineIt->prev();
		}
	}
	else {
		while (lineIt->lineNumber() != line) {
			lineIt = lineIt->next();
		}
	}

	cursor->setFragment(lineIt->first());
	cursor->setPosition(0);

	return ret;
}

bool Selection::isAfter(Cursor * cursor, int line, int ch) {
	int cursorLine = cursor->fragment()->line()->lineNumber();

	return line > cursorLine ||
		   (line == cursorLine && ch > cursor->getPosInLine());
}

}  // namespace icL::editor