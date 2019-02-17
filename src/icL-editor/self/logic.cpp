#include "logic.h"

#include "../fragment/fragment.h"
#include "../history/changesentity.h"
#include "../private/cursor.h"
#include "../private/fixer.h"
#include "../private/line.h"
#include "../private/selection.h"
#include "linenumbers.h"

namespace icL::editor {

Logic::Logic(QQuickItem * parent)
    : QQuickPaintedItem(parent) {
    m_mainSelection = new Selection();
    m_fixer         = new Fixer();
}

Logic::~Logic() {
    delete m_mainSelection;
    delete m_fixer;
}

Selection * Logic::main() const {
    return m_mainSelection;
}

Line * Logic::first() const {
    return m_first;
}

Line * Logic::current() const {
    return m_currentLine;
}

Line * Logic::firstVisible() const {
    return m_firstVisible;
}

Fixer * Logic::fixer() {
    return m_fixer;
}

void Logic::lMakeChanged() {
    changed = true;
}

void Logic::lClear() {
    auto * it = m_first;

    while (it != nullptr) {
        auto * tmp = it;

        it = it->nextDisplay();
        delete tmp;
    }

    m_first        = nullptr;
    m_firstVisible = nullptr;
    m_currentLine  = nullptr;
    numberOfLines  = 0;
}

bool Logic::loadFile(const QString & path) {
    QFile       file(path);
    QTextStream stream(&file);

    if (!file.open(QFile::ReadOnly)) {
        qDebug() << "File not found" << file.fileName();
        return false;
    }

    qDebug() << "File found" << file.fileName();

    while (!stream.atEnd()) {
        QString str = stream.readLine(160);

        auto * line     = new Line(this, false);
        auto * fragment = new Fragment(line);

        fragment->insert(
          m_mainSelection->begin(), m_mainSelection->end(), 0, str);
        line->setFirst(fragment);
        line->getText(true);
        line->updateLength();
        lAddNewLine(line);
    }

    auto * it = m_firstVisible = m_first;
    for (int i = 0; i < numberOfLines && it != nullptr; i++) {
        it->setVisible(true);
        it = it->next();
    }

    // Testing data
    // To be removed after
    auto * ptr = m_first->next()->next()->next()->next()->next()->next();
    ptr        = ptr->next()->next()->next()->next()->next()->next();
    m_first->next()->next()->setHasBreakPoint(true);
    m_first->next()->next()->next()->next()->next()->next()->setHasBreakPoint(
      true);

    ptr->setHasBreakPoint(true);
    debugLine = m_currentLine = ptr->prev();

    auto * sixth = m_first->next()->next()->next()->next()->next();
    m_mainSelection->begin()->setFragment(sixth->first());
    m_mainSelection->end()->setFragment(m_currentLine->first());
    m_mainSelection->begin()->setPosition(16);
    m_mainSelection->end()->setPosition(2);
    m_mainSelection->begin()->updatePreffered();
    m_mainSelection->end()->updatePreffered();

    m_fixer->fixNow(m_first);

    return true;
}

Line * Logic::getLineByNumber(int16_t n) {
    auto * it = m_first;
    int    i  = 0;

    while (it->next() != nullptr && i < n) {
        it = it->next();
        i++;
    }

    return it;
}

void Logic::setFirst(Line * first) {
    if (m_first == first)
        return;

    m_first = first;
}

void Logic::setCurrent(Line * current) {
    if (m_currentLine == current)
        return;

    m_currentLine = current;
}

void Logic::setFirstVisible(Line * firstVisible) {
    if (m_firstVisible == firstVisible)
        return;

    m_firstVisible = firstVisible;
    firstVisible->setVisible(true);

    emit firstLineNrChanged();
}

void Logic::lAddNewLine(Line * line) {
    if (m_currentLine == nullptr) {
        m_first = m_currentLine = line;
        line->setLineNumber(1);
    }
    else {
        if (m_currentLine->next() != nullptr) {
            m_currentLine->next()->setPrev(line);
        }
        line->setNext(m_currentLine->next());
        m_currentLine->setNext(line);
        line->setPrev(m_currentLine);
        line->setLineNumber(m_currentLine->lineNumber() + 1);
        line->setVisible(m_currentLine->visible());

        setCurrent(line);
    }
}

void Logic::lUpdateCurrentLine() {
    Fragment * fragment;

    if (m_mainSelection->rtl()) {
        fragment = m_mainSelection->begin()->fragment();
    }
    else {
        fragment = m_mainSelection->end()->fragment();
    }

    if (fragment != nullptr) {
        setCurrent(fragment->line());

        sAutoScrollToCurrent();

        emit requestRepaint();
    }
}

void Logic::lChangeNumberOfLines(int newValue) {
    numberOfLines  = newValue;
    numberOfDigits = 0;

    while (newValue > 0) {
        newValue /= 10;
        numberOfDigits++;
    }

    emit linesCountChanged();
    dUpdateBackgroundGeometry();
}

void Logic::lBackUpSelections() {
    auto it = hGetFirstSelection();

    while (it != nullptr) {
        it->begin()->backUp();
        it->end()->backUp();
    }
}

void Logic::lRestoreSelections() {
    auto it = hGetFirstSelection();

    while (it != nullptr) {
        it->begin()->restore();
        it->end()->restore();
    }
}

void Logic::lOptimizeSelections() {
    auto it = hGetFirstSelection();

    while (it->next() != nullptr) {
        if (it->next()->begin()->getPosInFile() <= it->end()->getPosInFile()) {
            it->end()->syncWith(it->next()->end());
            it->next()->remove();
        }
        else {
            it = it->next();
        }
    }
}

void Logic::lSyncSelectionsWith(ChangesEntity * internalChange) {
    while (m_mainSelection->prev()) {
        m_mainSelection->prev()->remove();
    }

    while (m_mainSelection->next()) {
        m_mainSelection->next()->remove();
    }

    // The main seletion was found
    Selection * lastSelectionAfterMain = nullptr;

    for (auto * change : internalChange->getChanges()) {
        Selection * current;

        if (change->isMain) {
            current                = m_mainSelection;
            lastSelectionAfterMain = m_mainSelection;
        }
        else {
            current = new Selection();

            if (lastSelectionAfterMain == nullptr) {

                if (m_mainSelection->prev() != nullptr) {
                    m_mainSelection->prev()->setNext(current);
                }

                current->setPrev(m_mainSelection->prev());
                current->setNext(m_mainSelection);
                m_mainSelection->setPrev(current);
            }
            else {
                lastSelectionAfterMain->setNext(current);
                current->setPrev(lastSelectionAfterMain);

                lastSelectionAfterMain = current;
            }
        }

        current->begin()->setLineNumber(change->line);
        current->begin()->setPreffered(change->column);

        current->begin()->restore();
        current->end()->syncWith(current->begin());
    }
}

}  // namespace icL::editor
