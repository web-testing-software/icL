#include "selection.h"

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
