#include "history.h"

#include "../fragment/fragment.h"
#include "../private/cursor.h"
#include "../private/line.h"
#include "../private/selection.h"

namespace icL::editor {

History::History(QQuickItem * parent)
	: Scroll(parent) {}

void History::addCursorOnPrevLine() {
	if (*m_main->begin() != *m_main->end() || m_current->prev() == nullptr) {
		return;
	}

	if (
	  m_main->prev() == nullptr ||
	  (m_main->prev()->main()->fragment()->line() !=
	   m_main->main()->fragment()->line())) {

		auto * nSelection = new Selection();

		nSelection->syncWith(m_main);
	}
	else {
		m_main->prev()->remove();
	}

	m_main->moveUpDown(-1);
}

void History::addCursorOnNextLine() {
	if (*m_main->begin() != *m_main->end() || m_current->next() == nullptr) {
		return;
	}

	if (
	  m_main->next() == nullptr ||
	  (m_main->next()->main()->fragment()->line() !=
	   m_main->main()->fragment()->line())) {

		auto * nSelection = new Selection();

		nSelection->syncWith(m_main);
	}
	else {
		m_main->next()->remove();
	}

	m_main->moveUpDown(1);
}

}  // namespace icL::editor
