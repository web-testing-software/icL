#include "line.h"

#include "../fragment/fragment.h"
#include "../self/drawing.h"
#include "fixer.h"
#include "styleproxy.h"

#include <QStaticText>
#include <QTextStream>

namespace icL::editor {

Line::Line(Logic * parent, bool isNew) {
    m_parent = parent;
    m_isNew  = isNew;
}

Fragment * Line::first() const {
    return m_first;
}

Line * Line::next() const {
    return m_next;
}

Line * Line::nextDisplay() const {
    if (phantom != nullptr && m_showPhantom) {
        return phantom;
    }

    return m_next;
}

Line * Line::prev() const {
    return m_prev;
}

Line * Line::prevDisplay() const {
    if (m_prev != nullptr && m_prev->m_showPhantom && m_prev->phantom != this) {
        return m_prev->getLastPhantom();
    }

    return m_prev;
}

int Line::length() const {
    return m_length;
}

int Line::beginPos() const {
    return m_beginPos;
}

int Line::lineNumber() const {
    if (m_isPhantom) {
        return m_prev->lineNumber();
    }

    return m_lineNumber;
}

bool Line::visible() const {
    return m_visible;
}

bool Line::hasBreakPoint() const {
    return m_hasBreakPoint;
}

const QString & Line::getText(bool force) {
    if (!m_isChanged || force) {
        return content;
    }

    int tabSize = dynamic_cast<Drawing *>(m_parent)->proxy()->tabSize();

    auto * it = m_first;

    content.clear();
    content.reserve(m_length);

    content += QString(it->spaces() / tabSize, '\t');
    content += QString(it->spaces() % tabSize, ' ');
    content += it->displayText();
    it = it->next();

    while (it != nullptr) {
        content += QString(it->spaces(), ' ');
        content += it->displayText();
    }

    return content;
}

bool Line::isChanged() {
    return m_isChanged;
}

bool Line::wasChanged() {
    return m_wasChanged;
}

void Line::save(QTextStream * stream) {
    if (stream->device() != nullptr)
        (*stream) << getText();
    m_wasChanged = m_isChanged;
    m_isChanged  = false;
}

Logic * Line::parent() const {
    return m_parent;
}

QStaticText * Line::getCache() {
    return cache;
}

bool Line::isNew() {
    return m_isNew;
}

bool Line::isPhantom() {
    return m_isPhantom;
}

bool Line::isSelected() {
    return m_isSelected;
}

bool Line::hasPhantoms() {
    return phantom != nullptr;
}

Line * Line::getLastPhantom() {
    auto * it = phantom;

    if (it == nullptr) {
        return nullptr;
    }

    while (it->m_next != nullptr && it->m_next->m_isPhantom) {
        it = it->m_next;
    }

    return it;
}

int Line::lastY() {
    return m_lastY;
}

void Line::updateLength() {
    auto * it = m_first->next();

    m_length = m_first->length();
    while (it != nullptr) {
        m_length += it->length();
        it = it->next();
    }
}

void Line::setFirst(Fragment * first) {
    if (m_first == first)
        return;

    m_first = first;
}

void Line::setNext(Line * next) {
    if (m_next == next)
        return;

    m_next = next;
}

void Line::setPrev(Line * prev) {
    if (m_prev == prev)
        return;

    m_prev = prev;
}

void Line::setBeginPos(int beginPos) {
    if (m_beginPos == beginPos)
        return;

    m_beginPos = beginPos;
}

void Line::setLineNumber(int lineNumber) {
    if (m_lineNumber == lineNumber)
        return;

    if (cache != nullptr) {
        cache->setText(QString::number(lineNumber));
    }

    m_lineNumber              = lineNumber;
    m_charsNumberInLineNumber = 0;

    if (lineNumber < 10) {
        m_charsNumberInLineNumber = 1;
    }
    else if (lineNumber < 100) {
        m_charsNumberInLineNumber = 2;
    }
    else if (lineNumber < 1000) {
        m_charsNumberInLineNumber = 3;
    }
    else if (lineNumber < 10000) {
        m_charsNumberInLineNumber = 4;
    }
    else {
        m_charsNumberInLineNumber = 5;
    }
}

void Line::setVisible(bool visible) {
    if (m_visible == visible)
        return;

    if (visible) {
        if (cache == nullptr) {
            cache = new QStaticText(QString::number(m_lineNumber));
        }

        for (auto * it = m_first; it != nullptr; it = it->next()) {
            it->cacheNow();
        }
    }
    else {
        if (cache != nullptr) {
            delete cache;
            cache = nullptr;

            for (auto * it = m_first; it != nullptr; it = it->next()) {
                it->freeCache();
            }
        }
    }

    m_visible = visible;
}

void Line::setHasBreakPoint(bool hasBreakPoint) {
    if (m_hasBreakPoint == hasBreakPoint)
        return;

    m_hasBreakPoint = hasBreakPoint;
}

void Line::setLastY(int lastY) {
    m_lastY = lastY;
}

void Line::makeChanged() {
    m_parent->lMakeChanged();
    m_isChanged  = true;
    m_wasChanged = false;
}

void Line::fixLines() {
    m_parent->fixer()->fix(this);
}

int Line::charsNumberInLineNumber() {
    return m_charsNumberInLineNumber;
}

void Line::makePhantom() {
    if (m_isPhantom) {
        return;
    }

    m_prev->m_next = m_next;

    if (m_next != nullptr) {
        m_next->m_prev = m_prev;
    }

    Line * prevLineLastPhantom = m_prev->getLastPhantom();

    if (prevLineLastPhantom != nullptr) {
        m_prev = prevLineLastPhantom;

        prevLineLastPhantom->m_next = this;
    }
    else {
        m_prev->phantom = this;
    }

    if (phantom != nullptr) {
        Line * lastPhantom = getLastPhantom();

        phantom->m_prev     = this;
        lastPhantom->m_next = m_next;

        m_next = phantom;
    }

    if (!m_prev->m_showPhantom) {
        setVisible(false);
    }

    phantom         = nullptr;
    m_isPhantom     = true;
    m_hasBreakPoint = false;
}

void Line::restorePhantom() {
    if (!m_isPhantom) {
        return;
    }

    if (m_prev->m_isPhantom) {
        m_prev->m_next = m_next;
    }
    else {
        m_prev->phantom = m_next->m_isPhantom ? m_next : nullptr;
    }

    if (m_next->m_isPhantom) {
        m_next->m_prev = m_prev;
    }

    Line * noPhantom = m_prev;

    while (noPhantom->m_isPhantom) {
        noPhantom = noPhantom->prev();
    }

    if (noPhantom->m_next != nullptr) {
        noPhantom->m_next->m_prev = this;
    }

    m_next = noPhantom->m_next;
    m_prev = noPhantom;

    noPhantom->m_next = this;
}

void Line::dropPhantom() {
    if (!m_isPhantom) {
        return;
    }

    if (m_prev->m_isPhantom) {
        m_prev->m_next = m_next;
    }
    else {
        m_prev->phantom = m_next->m_isPhantom ? m_next : nullptr;
    }

    if (m_next->m_isPhantom) {
        m_next->m_prev = m_prev;
    }

    delete this;
}

void Line::showPhantoms(bool show) {
    if (show && phantom == nullptr) {
        return;
    }

    m_showPhantom = show;

    if (show) {
        Line * it = phantom;

        while (it != nullptr && it->m_isPhantom) {
            it->setVisible(true);
            it = it->next();
        }
    }
}

void Line::replaceContents(const QString & content) {
    while (m_first->next() != nullptr) {
        auto * next = m_first->next();

        m_first->setNext(m_first->next()->next());
        delete next;
    }

    m_first->replaceContent(content);

    m_isNew     = false;
    m_isChanged = true;
}

void Line::deleteNow() {
    while (m_first != nullptr) {
        auto * next = m_first->next();

        m_first = next->next();
        delete m_first;
    }

    while (phantom != nullptr) {
        phantom->deleteNow();
    }

    if (m_prev != nullptr) {
        if (m_isPhantom) {
            if (m_next->isPhantom()) {
                m_prev->phantom = m_next;
            }
            else {
                m_prev->phantom = nullptr;
            }
        }
        else {
            m_prev->m_next = m_next;
        }
    }

    delete this;
}

void Line::rawDropBegin(int pos) {
    int accumulatedPos = 0;

    while (m_first->length() + accumulatedPos < pos) {
        auto next = m_first->next();

        accumulatedPos += m_first->length();

        delete m_first;
        m_first = next;
    }

    m_first->rawDrop(0, pos - accumulatedPos);
}

void Line::rawDropEnd(int pos) {
    int accumulatedPos = 0;

    auto it = m_first;

    while (it->length() + accumulatedPos <= pos) {
        accumulatedPos += it->length();
        it = it->next();
    }

    while (it->next() != nullptr) {
        auto nextnext = it->next()->next();

        delete it->next();
        it->setNext(nextnext);
    }

    it->rawDrop(pos - accumulatedPos);
}

}  // namespace icL::editor
