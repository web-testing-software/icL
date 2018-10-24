#include "keyboard.h"

#include "../private/cursor.h"
#include "../private/selection.h"

namespace icL::editor {

Keyboard::Keyboard(QQuickItem * parent)
    : History(parent) {}

void Keyboard::keyPressEvent(QKeyEvent * event) {
	if (event->key() == Qt::Key_Left) {
		m_main->move(-1, event->modifiers().testFlag(Qt::ShiftModifier));
	}
	else if (event->key() == Qt::Key_Right) {
		m_main->move(1, event->modifiers().testFlag(Qt::ShiftModifier));
	}
}

void Keyboard::keyReleaseEvent(QKeyEvent * event) {}

}  // namespace icL::editor
