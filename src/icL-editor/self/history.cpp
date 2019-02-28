#include "history.h"

#include "../fragment/fragment.h"
#include "../history/changesentity.h"
#include "../private/cursor.h"
#include "../private/line.h"
#include "../private/selection.h"

namespace icL::editor {

History::History(QQuickItem * parent)
    : Scroll(parent) {
    m_firstRevision = new ChangesEntity();
}

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

void History::hBackspace() {
    /*auto * changesEntity =*/
    hGetCurrentChangesEntity(true);  // update or reuse current changes entity

    hForEachBackward([](Selection * selection) {
        QString deleted      = selection->backspace();
        auto *  changeEntity = selection->getChangeEntity();

        changeEntity->deleted.prepend(deleted);
        changeEntity->stepBack += deleted.length();
    });
}

void History::hDelete() {
    /*auto * changesEntity =*/
    hGetCurrentChangesEntity(true);  // update or reuse current changes entity

    hForEachBackward([](Selection * selection) {
        QString deleted      = selection->delete1();
        auto *  changeEntity = selection->getChangeEntity();

        changeEntity->deleted.append(deleted);
    });
}

void History::hDrop() {
    /*auto * changesEntity =*/
    hGetCurrentChangesEntity(true);  // update or reuse current changes entity

    hForEachBackward([](Selection * selection) {
        QString deleted      = selection->drop();
        auto *  changeEntity = selection->getChangeEntity();

        changeEntity->deleted.append(deleted);
    });
}

void History::hInsert(const QString & text) {
    /*auto * changesEntity =*/
    hGetCurrentChangesEntity(false);  // update or reuse current changes entity

    hForEachBackward([&text](Selection * selection) {
        QString inserted     = selection->insert(text);
        auto *  changeEntity = selection->getChangeEntity();

        changeEntity->inserted.append(inserted);
    });
}

void History::hUndo() {
    //
}

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

    if (cursorWasMoved || m_currentChanges == nullptr) {
        return hGetNewChangesEntity();
    }

    if (m_currentChanges->hasInsert() && forDelete) {
        return hGetNewChangesEntity();
    }

    return m_currentChanges;
}

ChangesEntity * History::hGetNewChangesEntity() {

    // Finish current

    if (m_currentChanges != nullptr) {
        m_currentChanges->optimize();

        if (m_currentChanges->getChanges().empty()) {
            delete m_currentChanges;
        }

        m_currentChanges = nullptr;
    }

    if (m_currentChanges) {
        m_currentChanges->setPrev(m_currentRevision->prev());

        if (m_currentRevision != nullptr) {

            while (m_currentRevision->next() != nullptr) {
                auto * nextnext = m_currentRevision->next()->next();

                delete m_currentRevision->next();
                m_currentRevision->setNext(nextnext);
            }

            m_currentRevision->setNext(m_currentChanges);
        }

        m_currentRevision = m_currentChanges;

        if (m_firstRevision == nullptr) {
            m_firstRevision = m_currentRevision;
        }
    }

    // Create new

    ChangesEntity * ret = new ChangesEntity();

    hForEachForward([ret, this](Selection * selection) {
        hAutoSetChangeEntityFor(selection, ret);
    });

    return ret;
}

void History::hForEachForward(const std::function<void(Selection *)> & func) {
    auto * it = hGetFirstSelection();

    while (it != nullptr) {
        func(it);
        it = it->next();
    }
}

void History::hForEachBackward(const std::function<void(Selection *)> & func) {
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
