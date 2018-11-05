#include "scroll.h"

#include "../private/line.h"

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
