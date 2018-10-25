#include "selection.h"

#include "../fragment/fragment.h"
#include "../self/advanced.h"
#include "cursor.h"
#include "line.h"

namespace icL::editor {

Selection::Selection(QObject * parent)
    : QObject(parent) {
	m_begin = new Cursor(this);
	m_end   = new Cursor(this);
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

Selection * Selection::next() const {
	return m_next;
}

bool Selection::rtl() const {
	return m_rtl;
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
}

void Selection::setNext(Selection * next) {
	if (m_next == next)
		return;

	m_next = next;
	emit nextChanged(m_next);
}

void Selection::setRtl(bool rtl) {
	if (m_rtl == rtl)
		return;

	m_rtl = rtl;
	emit rtlChanged(m_rtl);
}

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

}  // namespace icL::editor
