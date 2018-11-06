#include "scroll.h"

#include "../private/line.h"
#include "../private/styleproxy.h"

namespace icL::editor {

Scroll::Scroll(QQuickItem * parent)
	: Drawing(parent) {}

void Scroll::scrollUpBy(int by) {
	int    i  = 0;
	auto * it = m_firstVisible;

	while (it->prev() != nullptr && i < by) {
		it = it->prevDisplay();
		it->setVisible(true);
		i++;
	}

	setFirstVisible(it);
}

void Scroll::scrollDownBy(int by) {
	int    i  = 0;
	auto * it = m_firstVisible;

	while (it->nextDisplay() != nullptr && i < by) {
		it->setVisible(false);
		it = it->nextDisplay();
		i++;
	}

	setFirstVisible(it);
}

void Scroll::autoScrollToCurrent() {
	if (m_current->lineNumber() <= m_firstVisible->lineNumber()) {
		Line * it = m_firstVisible;
		int    i  = 0;

		while (it != m_current && it->prevDisplay() != nullptr) {
			i++;
			it = it->prevDisplay();
		}

		scrollUpBy(i);
	}
	else {
		bool   visible = false;
		int    y       = 0;
		Line * it      = m_firstVisible;

		while (y < height() - m_proxy->fullLineH() && it != nullptr) {
			visible = visible || it == m_current;
			it      = it->nextDisplay();
			y += m_proxy->fullLineH();
		}

		if (!visible) {
			int i = 1;

			while (it != m_current && it->next() != nullptr) {
				i++;
				it = it->nextDisplay();
			}

			scrollDownBy(i);
		}
	}
}

void Scroll::scrollX(qreal ratio) {
	if (ratio < 0.0) {
		ratio = 0.0;
	}
	else if (ratio > 1.0) {
		ratio = 1.0;
	}

	uint8_t newPos = ratio * static_cast<qreal>(160 - m_visibleChars);

	if (newPos != xScroll) {
		xScroll = newPos;
		emit firstCharNrChanged(newPos);
		update();
	}
}

void Scroll::scrollY(qreal ratio) {
	int16_t line = ratio * numberOfLines - m_firstVisible->lineNumber();

	if (line < 0) {
		scrollUpBy(-line);
	}
	else {
		scrollDownBy(line);
	}

	emit requestRepaint();
}

}  // namespace icL::editor
