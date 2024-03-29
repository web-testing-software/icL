#include "scroll.h"

#include "../private/cursor.h"
#include "../private/line.h"
#include "../private/selection.h"
#include "../private/styleproxy.h"

namespace icL::editor {

Scroll::Scroll(QQuickItem * parent)
    : Drawing(parent) {}

void Scroll::sScrollUpBy(int by) {
    int    i  = 0;
    auto * it = m_firstVisible;

    while (it->prev() != nullptr && i < by) {
        it = it->prevDisplay();
        it->setVisible(true);
        i++;
    }

    setFirstVisible(it);
}

void Scroll::sScrollDownBy(int by) {
    int    i  = 0;
    auto * it = m_firstVisible;

    while (it->nextDisplay() != nullptr && i < by) {
        it->setVisible(false);
        it = it->nextDisplay();
        i++;
    }

    setFirstVisible(it);
}

void Scroll::sAutoScrollToCurrent() {
    if (m_currentLine->lineNumber() <= m_firstVisible->lineNumber()) {
        Line * it = m_firstVisible;
        int    i  = 0;

        while (it != m_currentLine && it->prevDisplay() != nullptr) {
            i++;
            it = it->prevDisplay();
        }

        sScrollUpBy(i);
    }
    else {
        bool   visible = false;
        int    y       = 0;
        Line * it      = m_firstVisible;

        while (y < height() - m_proxy->fullLineH() && it != nullptr) {
            visible = visible || it == m_currentLine;
            it      = it->nextDisplay();
            y += m_proxy->fullLineH();
        }

        if (!visible) {
            int i = 1;

            while (it != m_currentLine && it->next() != nullptr) {
                i++;
                it = it->nextDisplay();
            }

            sScrollDownBy(i);
        }
    }

    sFixXScrollPosition();
}

void Scroll::sFixXScrollPosition() {
    Cursor * cursor = m_mainSelection->main();
    int      pos    = cursor->getPosInLine();

    if (pos < xScroll) {
        xScroll = cursor->preffered();
    }
    else if (pos > xScroll + charsInLine()) {
        xScroll = cursor->preffered() - charsInLine();
    }
}

void Scroll::scrollX(qreal ratio) {
    if (ratio < 0.0) {
        ratio = 0.0;
    }
    else if (ratio > 1.0) {
        ratio = 1.0;
    }

    uint8_t newPos = uint8_t(ratio * static_cast<qreal>(160 - m_visibleChars));

    if (newPos != xScroll) {
        xScroll = newPos;
        emit firstCharNrChanged(newPos);
        update();
    }
}

void Scroll::scrollY(qreal ratio) {
    int16_t line =
      int16_t(ratio * numberOfLines - m_firstVisible->lineNumber());

    if (line < 0) {
        sScrollUpBy(-line);
    }
    else {
        sScrollDownBy(line);
    }

    emit requestRepaint();
}

}  // namespace icL::editor
