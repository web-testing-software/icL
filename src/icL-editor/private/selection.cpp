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

Cursor * Selection::main() const {
    if (m_rtl) {
        return m_begin;
    }

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

ChangeEntity * Selection::getChangeEntity() {
    return changeEntity;
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
    m_begin->getEditor()->lUpdateCurrentLine();
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
    m_begin->getEditor()->lUpdateCurrentLine();
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
    m_begin->getEditor()->lUpdateCurrentLine();
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

    bool endLineIsSelectedCompletly =
      m_end->position() == endFrag->length() && endFrag->next() == nullptr;

    if (beginFrag != endFrag) {

        // make begin line phantom if is removed completly
        if (beginFrag->prev() == nullptr && m_begin->position() == 0) {
            auto * beginLine = beginFrag->line();
            auto * prevLine  = beginLine->prev();
            auto * nextLine  = beginLine->next();

            auto * newLine = new Line(beginLine->parent(), beginLine->isNew());
            auto * newFrag = new Fragment(newLine);

            newLine->setFirst(newFrag);
            newLine->setLineNumber(beginLine->lineNumber());

            if (prevLine != nullptr) {
                prevLine->setNext(newLine);
                newLine->setPrev(prevLine);
            }
            if (nextLine != nullptr) {
                nextLine->setPrev(newLine);
                newLine->setNext(nextLine);
            }

            beginLine->setPrev(newLine);
            beginLine->makePhantom();

            m_begin->setFragment(newFrag);
            m_begin->setPosition(0);
        }
        // Remove a fragment of line
        else if (m_begin->position() != beginFrag->length()) {
            beginFrag->drop(m_begin, m_begin->position());
            beginFrag->line()->makeChanged();
        }

        if (m_end->position() != 0 && !endLineIsSelectedCompletly) {
            endFrag->drop(m_end, 0, m_end->position());
            endFrag->line()->makeChanged();
        }

        // beginFrag and end fragments can be deleted on content drop
        beginFrag = m_begin->fragment();
        endFrag   = m_end->fragment();
    }
    else {
        beginFrag->drop(m_begin, m_begin->position(), m_end->position());
    }

    auto * beginLine = beginFrag->line();

    if (beginLine != endFrag->line()) {

        // Drop content from begin frag to end of line
        while (beginFrag->next() != nullptr) {
            auto * tmp = beginFrag->next()->next();

            delete beginFrag->next();
            beginFrag->setNext(tmp);
        }

        // Make phantoms lines beetwen begin line and end line
        beginLine = beginLine->next();
        while (beginLine != endFrag->line()) {
            auto * tmp = beginLine->next();

            beginLine->makePhantom();
            beginLine = tmp;
        }

        auto * endLine = endFrag->line();

        // If we are deleting all end line
        if (endLineIsSelectedCompletly) {
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
    m_begin->getEditor()->lUpdateCurrentLine();
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
    Q_ASSERT(*m_begin == *m_end);

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
    m_begin->getEditor()->lUpdateCurrentLine();
    m_begin->fragment()->line()->fixLines();

    return retAfter;
}

void Selection::rawInsert(const QString & text) {
    // If the selection is not empty
    Q_ASSERT(*m_begin == *m_end);

    m_end->fragment()->rawInsert(m_end, m_end->position(), text);
    m_begin->syncWith(m_end);
}

void Selection::rawDrop() {
    if (*m_begin == *m_end) {
        return;
    }

    auto beginFrag = m_begin->fragment(), endFrag = m_end->fragment();
    auto beginLine = beginFrag->line(), endLine = endFrag->line();

    if (beginLine == endLine) {
        if (beginFrag == endFrag) {
            beginFrag->rawDrop(m_begin->position(), m_end->position());
        }
        else {
            endFrag->rawDrop(0, m_end->position());
            beginFrag->rawDrop(m_begin->position());
            m_end->syncWith(m_begin);

            while (beginFrag->next() != endFrag) {
                auto nextnext = beginFrag->next()->next();

                delete beginFrag->next();
                beginFrag->setNext(nextnext);
            }
        }
    }
    else {
        while (beginLine->next() != endLine) {
            beginLine->next()->deleteNow();
        }
    }
}

void Selection::linkAfter(Selection * selection) {
    if (m_next != nullptr) {
        m_next->m_prev    = selection;
        selection->m_next = m_next;
    }

    selection->m_prev = this;
    this->m_next      = selection;
}

void Selection::linkBefore(Selection * selection) {
    if (m_prev != nullptr) {
        m_prev->m_next    = selection;
        selection->m_prev = m_prev;
    }

    selection->m_next = this;
    this->m_prev      = selection;
}

void Selection::remove() {
    if (m_next != nullptr) {
        m_next->m_prev = m_prev;
    }

    if (m_prev != nullptr) {
        m_prev->m_next = m_next;
    }

    delete this;
}

void Selection::syncWith(Selection * selection) {
    m_begin->syncWith(selection->m_begin);
    m_end->syncWith(selection->m_end);
}

void Selection::setNext(Selection * next) {
    if (m_next == next)
        return;

    m_next = next;
}

void Selection::setPrev(Selection * prev) {
    if (m_prev == prev)
        return;

    m_prev = prev;
}

void Selection::setRtl(bool rtl) {
    if (m_rtl == rtl)
        return;

    m_rtl = rtl;
}

void Selection::setChangeEntity(ChangeEntity * changeEntity) {
    this->changeEntity = changeEntity;
}

bool Selection::beginSelection(Line * line, int ch) {
    if (line == nullptr) {
        return false;
    }

    moveCursorToLine(line, m_begin);
    m_begin->setPreffered(ch);
    m_begin->matchPreffered();

    m_end->syncWith(m_begin);

    return true;
}

void Selection::selectTo(Line * line, int ch) {
    if (line == nullptr) {
        return;
    }

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
    moveCursorToLine(line, toMove);

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

bool Selection::moveCursorToLine(Line * line, Cursor * cursor) {
    if (line == nullptr) {
        return false;
    }

    cursor->setFragment(line->first());
    cursor->setPosition(0);

    return true;
}

bool Selection::isAfter(Cursor * cursor, Line * line, int ch) {
    int cursorLine = cursor->fragment()->line()->lineNumber();

    return line->lineNumber() > cursorLine ||
           (line->lineNumber() == cursorLine && ch > cursor->getPosInLine());
}

}  // namespace icL::editor
