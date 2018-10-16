#include "selection.h"

namespace icL::editor {

Selection::Selection(QObject * parent)
	: QObject(parent) {}

Cursor * Selection::begin() const {
	return m_begin;
}

Cursor * Selection::end() const {
	return m_end;
}

Selection * Selection::next() const {
	return m_next;
}

void Selection::setNext(Selection * next) {
	if (m_next == next)
		return;

	m_next = next;
	emit nextChanged(m_next);
}

}  // namespace icL::editor
