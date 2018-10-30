#include "keyboard.h"

#include "../private/cursor.h"
#include "../private/line.h"
#include "../private/selection.h"
#include "linenumbers.h"

namespace icL::editor {

Keyboard::Keyboard(QQuickItem * parent)
    : History(parent) {}

void Keyboard::keyPressEvent(QKeyEvent * event) {
	if (event->key() == Qt::Key_Left) {
		if (event->modifiers().testFlag(Qt::ControlModifier)) {
			m_main->moveOverWords(
			  -1, event->modifiers().testFlag(Qt::ShiftModifier));
		}
		else
			m_main->move(-1, event->modifiers().testFlag(Qt::ShiftModifier));
	}
	else if (event->key() == Qt::Key_Right) {
		if (event->modifiers().testFlag(Qt::ControlModifier)) {
			m_main->moveOverWords(
			  1, event->modifiers().testFlag(Qt::ShiftModifier));
		}
		else
			m_main->move(1, event->modifiers().testFlag(Qt::ShiftModifier));
	}
	else if (event->key() == Qt::Key_Up) {
		m_main->moveUpDown(-1, event->modifiers().testFlag(Qt::ShiftModifier));
	}
	else if (event->key() == Qt::Key_Down) {
		m_main->moveUpDown(1, event->modifiers().testFlag(Qt::ShiftModifier));
	}
	else if (event->key() == Qt::Key_Backspace) {
		qDebug() << m_main->backspace();
	}
	else if (event->key() == Qt::Key_Delete) {
		qDebug() << m_main->delete1();
	}
	else if (event->key() == Qt::Key_A) {
		qDebug() << m_main->insert(event->text());
	}
	else if (event->key() == Qt::Key_Enter) {
		qDebug() << m_main->insert("\n");
	}
	else if (event->key() == Qt::Key_1) {
		qDebug() << "pressed";
		m_firstVisible->next()->next()->setHasBreakPoint(
		  !m_firstVisible->next()->next()->hasBreakPoint());
		m_lineN->update();
	}

	emit requestRepaint();
}

void Keyboard::keyReleaseEvent(QKeyEvent * event) {}

}  // namespace icL::editor
