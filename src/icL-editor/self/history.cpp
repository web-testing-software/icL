#include "history.h"

#include "../fragment/fragment.h"
#include "../private/cursor.h"
#include "../private/line.h"
#include "../private/selection.h"

namespace icL::editor {

History::History(QQuickItem * parent)
    : Scroll(parent) {}

Selection * History::getFirstSelection() {
	auto * it = m_main;

	while (it->prev() != nullptr) {
		it = it->prev();
	}

	return it;
}

Selection * History::getLastSelection() {
	auto * it = m_main;

	while (it->next() != nullptr) {
		it = it->next();
	}

	return it;
}

int History::selectionsCount() {
	return numberOfCursors;
}

void History::addCursorOnPrevLine() {
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

void History::addCursorOnNextLine() {
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

void History::moveCursorToNextChar() {
	auto * it = getFirstSelection();

	while (it != nullptr) {
		it->move(1);
		it = it->next();
	}
}

void History::moveCursorToPrevChar() {
	auto * it = getFirstSelection();

	while (it != nullptr) {
		it->move(-1);
		it = it->next();
	}
}

void History::moveCursorToNextWord() {
	auto * it = getFirstSelection();

	while (it != nullptr) {
		it->moveOverWords(1);
		it = it->next();
	}
}

void History::moveCursorToPrevWord() {
	auto * it = getFirstSelection();

	while (it != nullptr) {
		it->moveOverWords(-1);
		it = it->next();
	}
}

}  // namespace icL::editor
