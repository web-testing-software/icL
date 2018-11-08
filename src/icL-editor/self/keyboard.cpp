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
		const auto & mods = event->modifiers();

		if (
		  mods.testFlag(Qt::ShiftModifier) && mods.testFlag(Qt::AltModifier)) {
			addCursorOnPrevLine();
		}
		else
			m_main->moveUpDown(
			  -1, event->modifiers().testFlag(Qt::ShiftModifier));
	}
	else if (event->key() == Qt::Key_Down) {
		const auto & mods = event->modifiers();

		if (
		  mods.testFlag(Qt::ShiftModifier) && mods.testFlag(Qt::AltModifier)) {
			addCursorOnNextLine();
		}
		else
			m_main->moveUpDown(
			  1, event->modifiers().testFlag(Qt::ShiftModifier));
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
	else if (event->key() == Qt::Key_S) {
		auto *      it = m_first;
		QTextStream st;

		while (it != nullptr) {
			it->save(&st);
			it = it->next();
		}

		requestRepaint();
	}
	else if (event->key() == Qt::Key_Enter) {
		qDebug() << m_main->insert("\n");
	}
	else if (
	  event->key() == Qt::Key_H &&
	  event->modifiers().testFlag(Qt::ControlModifier)) {
		m_current->showPhantoms(true);
	}
	else if (event->key() == Qt::Key_1) {
		qDebug() << "pressed";
		m_firstVisible->next()->next()->setHasBreakPoint(
		  !m_firstVisible->next()->next()->hasBreakPoint());
	}

	emit requestRepaint();
}

}  // namespace icL::editor
