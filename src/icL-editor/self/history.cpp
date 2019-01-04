#include "history.h"

#include "../fragment/fragment.h"
#include "../history/changesentity.h"
#include "../private/cursor.h"
#include "../private/line.h"
#include "../private/selection.h"

namespace icL::editor {

History::History(QQuickItem * parent)
    : Scroll(parent) {}

Selection * History::hGetFirstSelection() {
	auto * it = m_mainSelection;

	while (it->prev() != nullptr) {
		it = it->prev();
	}

	return it;
}

Selection * History::hGetLastSelection() {
	auto * it = m_mainSelection;

	while (it->next() != nullptr) {
		it = it->next();
	}

	return it;
}

int History::hSelectionsCount() {
	return numberOfCursors;
}

void History::hAddCursorOnPrevLine() {
	if (
	  *m_mainSelection->begin() != *m_mainSelection->end() ||
	  m_currentLine->prev() == nullptr) {
		return;
	}

	if (
	  m_mainSelection->prev() == nullptr ||
	  (m_mainSelection->prev()->main()->fragment()->line() !=
	   m_mainSelection->main()->fragment()->line()->prev())) {

		auto * nSelection    = new Selection();
		auto * changesEntity = hGetCurrentChangesEntity(false);

		nSelection->syncWith(m_mainSelection);
		m_mainSelection->linkAfter(nSelection);
		numberOfCursors++;

		m_mainSelection->moveUpDown(-1);

		nSelection->setChangeEntity(m_mainSelection->getChangeEntity());
		hAutoSetChangeEntityFor(nSelection, changesEntity);
	}
	else {
		m_mainSelection->setChangeEntity(
		  m_mainSelection->prev()->getChangeEntity());

		m_mainSelection->prev()->remove();
		numberOfCursors--;

		m_mainSelection->moveUpDown(-1);
	}
}

void History::hAddCursorOnNextLine() {
	if (
	  *m_mainSelection->begin() != *m_mainSelection->end() ||
	  m_currentLine->next() == nullptr) {
		return;
	}

	if (
	  m_mainSelection->next() == nullptr ||
	  (m_mainSelection->next()->main()->fragment()->line() !=
	   m_mainSelection->main()->fragment()->line()->next())) {

		auto * nSelection    = new Selection();
		auto * changesEntity = hGetCurrentChangesEntity(false);

		nSelection->syncWith(m_mainSelection);
		m_mainSelection->linkBefore(nSelection);
		numberOfCursors++;

		m_mainSelection->moveUpDown(1);

		nSelection->setChangeEntity(m_mainSelection->getChangeEntity());
		hAutoSetChangeEntityFor(m_mainSelection, changesEntity);
	}
	else {
		m_mainSelection->setChangeEntity(
		  m_mainSelection->next()->getChangeEntity());

		m_mainSelection->next()->remove();
		numberOfCursors--;

		m_mainSelection->moveUpDown(1);
	}
}

void History::hMoveCursorChar(int step) {
	cursorWasMoved = true;

	hForEachForward([step](Selection * selection) { selection->move(step); });
	hFixSelections();
}

void History::hMoveCursorWord(int step) {
	cursorWasMoved = true;

	hForEachBackward(
	  [step](Selection * selection) { selection->moveOverWords(step); });
	hFixSelections();
}

void History::hMoveCursorLine(int step) {
	cursorWasMoved = true;

	hForEachForward(
	  [step](Selection * selection) { selection->moveUpDown(step); });
	hFixSelections();
}

void History::hSelectChar(int step) {
	cursorWasMoved = true;

	hForEachForward(
	  [step](Selection * selection) { selection->move(step, true); });
	hFixSelections();
}

void History::hSelectWord(int step) {
	cursorWasMoved = true;

	hForEachBackward(
	  [step](Selection * selection) { selection->moveOverWords(step, true); });
	hFixSelections();
}

void History::hSelectLine(int step) {
	cursorWasMoved = true;

	hForEachForward(
	  [step](Selection * selection) { selection->moveUpDown(step, true); });
	hFixSelections();
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

void History::hFixSelections() {
	auto * begin = hGetFirstSelection();
	auto * end   = hGetLastSelection();

	// Sort list using bubble sort
	while (end != nullptr) {
		auto * it = begin;

		while (it != end) {
			if (
			  it->begin()->getPosInFile() >
			  it->next()->begin()->getPosInFile()) {
				auto * next = it->next();

				if (it->prev() != nullptr) {
					it->prev()->setNext(next);
				}

				if (next->next() != nullptr) {
					it->next()->setPrev(it);
				}

				next->setPrev(it->prev());
				it->setNext(next->next());
				it->setPrev(next);
				next->setNext(it);
			}
			else {
				it = it->next();
			}
		}
	}


	lOptimizeSelections();
}

ChangesEntity * History::hGetCurrentChangesEntity(bool forDelete) {

	if (cursorWasMoved || m_currentChange == nullptr) {
		return hGetNewChangesEntity();
	}

	if (m_currentChange->hasInsert() && forDelete) {
		return hGetNewChangesEntity();
	}

	return m_currentChange;
}

ChangesEntity * History::hGetNewChangesEntity() {
	ChangesEntity * ret = new ChangesEntity();

	hForEachForward([ret, this](Selection * selection) {
		hAutoSetChangeEntityFor(selection, ret);
	});

	return ret;
}

void History::hForEachForward(std::function<void(Selection *)> func) {
	auto * it = hGetFirstSelection();

	while (it != nullptr) {
		func(it);
		it = it->next();
	}
}

void History::hForEachBackward(std::function<void(Selection *)> func) {
	auto * it = hGetLastSelection();

	while (it != nullptr) {
		func(it);
		it = it->prev();
	}
}

void History::hAutoSetChangeEntityFor(
  Selection * selection, ChangesEntity * changesEntity) {

	auto * changeEntity = changesEntity->addChange(
	  selection->begin()->fragment()->line()->lineNumber(),
	  selection->begin()->getPosInLine(), selection == m_mainSelection);

	selection->setChangeEntity(changeEntity);
}

}  // namespace icL::editor
