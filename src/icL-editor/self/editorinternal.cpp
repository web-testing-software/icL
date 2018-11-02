#include "editorinternal.h"

#include "../private/line.h"

namespace icL::editor {

EditorInternal::EditorInternal(QQuickItem * parent)
	: Mouse(parent) {}

void EditorInternal::scrollX(qreal ratio) {
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

void EditorInternal::scrollY(qreal ratio) {
	int16_t line = ratio * numberOfLines - m_firstVisible->lineNumber();

	if (line < 0) {
		moveUp(-line);
	}
	else {
		moveDown(line);
	}

	emit requestRepaint();
}

}  // namespace icL::editor
