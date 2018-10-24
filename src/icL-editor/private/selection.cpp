#include "selection.h"

#include "../fragment/fragment.h"
#include "../self/advanced.h"
#include "cursor.h"

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

void Selection::moveSelect(int step, Cursor * begin, Cursor * end) {
	if (step < 0) {
		begin->stepBack(-step, end);
	}
	else {
		begin->stepForward(step, end);
	}
}

void Selection::move(int step, bool select) {
	if (select) {
		if (
		  m_begin->fragment() == m_end->fragment() &&
		  m_begin->position() == m_end->position()) {
			if (step > 0) {
				setRtl(false);
			}
			else {
				setRtl(true);
			}
		}

		if (m_rtl) {
			moveSelect(step, m_begin, m_end);
		}
		else {
			moveSelect(step, m_end, m_begin);
		}
	}
	else {
		if (m_rtl) {
			m_end->syncWith(m_begin);
		}
		else {
			m_begin->syncWith(m_end);
		}

		if (step < 0) {
			m_begin->stepBack(-step, m_begin);
			m_end->syncWith(m_begin);
		}
		else {
			m_end->stepForward(step, m_end);
			m_begin->syncWith(m_end);
		}
	}

	m_begin->getEditor()->makeCursorOpaque();
}

bool Selection::rtl() const {
	return m_rtl;
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

}  // namespace icL::editor
