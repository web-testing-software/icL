#include "editorinternal.h"

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

}  // namespace icL::editor
