#include "history.h"

#include "../fragment/fragment.h"
#include "../history/internalchange.h"
#include "../private/cursor.h"
#include "../private/line.h"
#include "../private/selection.h"

namespace icL::editor {

History::History(QQuickItem * parent)
    : Scroll(parent) {}

Selection * History::hGetFirstSelection() {
	auto * it = m_main;

	while (it->prev() != nullptr) {
		it = it->prev();
	}

	return it;
}

Selection * History::hGetLastSelection() {
	auto * it = m_main;

	while (it->next() != nullptr) {
		it = it->next();
	}

	return it;
}

int History::hSelectionsCount() {
	return numberOfCursors;
}

void History::hAddCursorOnPrevLine() {
	if (*m_main->begin() != *m_main->end() || m_current->prev() == nullptr) {
		return;
	}

	if (
	  m_main->prev() == nullptr ||
	  (m_main->prev()->main()->fragment()->line() !=
	   m_main->main()->fragment()->line()->prev())) {

		auto * nSelection = new Selection();

		nSelection->syncWith(m_main);
		m_main->linkAfter(nSelection);
		numberOfCursors++;
	}
	else {
		m_main->prev()->remove();
		numberOfCursors--;
	}

	m_main->moveUpDown(-1);
}

void History::hAddCursorOnNextLine() {
	if (*m_main->begin() != *m_main->end() || m_current->next() == nullptr) {
		return;
	}

	if (
	  m_main->next() == nullptr ||
	  (m_main->next()->main()->fragment()->line() !=
	   m_main->main()->fragment()->line()->next())) {

		auto * nSelection = new Selection();

		nSelection->syncWith(m_main);
		m_main->linkBefore(nSelection);
		numberOfCursors++;
	}
	else {
		m_main->next()->remove();
		numberOfCursors--;
	}

	m_main->moveUpDown(1);
}

void History::hMoveCursorChar(int step) {

	auto * it = hGetFirstSelection();

	while (it != nullptr) {
		it->move(step);
		it = it->next();
	}
}

void History::hMoveCursorWord(int step) {

	auto * it = hGetFirstSelection();

	while (it != nullptr) {
		it->moveOverWords(step);
		it = it->next();
	}
}

void History::hMoveCursorLine(int step) {

	auto * it = hGetFirstSelection();

	while (it != nullptr) {
		it->moveUpDown(step);
		it = it->next();
	}
}

void History::hSelectChar(int step) {

	auto * it = hGetFirstSelection();

	while (it != nullptr) {
		it->move(1, true);
		it = it->next();
	}
}

void History::hSelectWord(int step) {

	auto * it = hGetFirstSelection();

	while (it != nullptr) {
		it->moveOverWords(step, true);
		it = it->next();
	}
}

void History::hSelectLine(int step) {

	auto * it = hGetFirstSelection();

	while (it != nullptr) {
		it->moveUpDown(step, true);
		it = it->next();
	}
}

void History::hBackspace() {}

void History::hDelete() {}

void History::hDrop() {}

void History::hInsert() {}

void History::hUndo() {}

void History::hRedo() {}

void History::hTryToDelete() {}

bool History::hHasSelection() {
	return false;
}

void History::hUpdateHistories() {}

void History::hFixSelections() {}

InternalChange * History::hGetCurrentChangeEntity(bool forDelete) {

	if (cursorWasMoved || m_currentChange == nullptr) {
		return hGetNewChangeEntity();
	}

	if (m_currentChange->hasInsert() && forDelete) {
		return hGetNewChangeEntity();
	}

	return m_currentChange;
}

InternalChange * History::hGetNewChangeEntity() {
	InternalChange * ret = new InternalChange();

	auto * it = hGetFirstSelection();

	while (it != nullptr) {
		ret->addChange(
		  it->begin()->fragment()->line()->lineNumber(),
		  it->begin()->getPosInLine(), it == m_main);

		it = it->next();
	}

	return ret;
}

}  // namespace icL::editor
