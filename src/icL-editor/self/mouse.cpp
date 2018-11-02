#include "mouse.h"

#include "../private/line.h"
#include "../private/styleproxy.h"
#include "linenumbers.h"

#include <QDebug>

namespace icL::editor {

Mouse::Mouse(QQuickItem * parent)
	: Keyboard(parent) {
	setAcceptedMouseButtons(
	  Qt::LeftButton | Qt::MiddleButton | Qt::RightButton);
	setAcceptHoverEvents(true);
}

void Mouse::wheelEvent(QWheelEvent * event) {
	QPoint delta = event->pixelDelta();
	int    maxX  = 160 - m_visibleChars;

	if (delta.isNull()) {
		delta = event->angleDelta() / 60;
		delta.setX(
		  delta.x() / 2 * m_proxy->charW() * m_proxy->tabSize() *
		  m_proxy->tabSize());
		delta.setY(delta.y() * m_proxy->fullLineH());
	}

	if (delta.x() != 0) {
		int step = delta.x() / (m_proxy->tabSize() * m_proxy->charW());

		if (step < 0) {

			xScroll += -step;

			if (xScroll > maxX) {
				xScroll = maxX;
			}
		}
		else {
			if (xScroll > step) {
				xScroll -= step;
			}
			else {
				xScroll = 0;
			}
		}
	}
	if (delta.y() != 0) {
		int step = delta.y() / m_proxy->charW();

		if (delta.y() < 0) {
			if (event->modifiers().testFlag(Qt::ShiftModifier)) {
				xScroll += -step;

				if (xScroll > maxX) {
					xScroll = maxX;
				}
			}
			else {
				moveDown(-delta.y() / m_proxy->fullLineH());
			}
		}
		else /* delta.y > 0 */ {
			if (event->modifiers().testFlag(Qt::ShiftModifier)) {
				if (xScroll > step) {
					xScroll -= step;
				}
				else {
					xScroll = 0;
				}
			}
			else {
				moveUp(delta.y() / m_proxy->fullLineH());
			}
		}
	}

	emit firstCharNrChanged(xScroll);
	emit requestRepaint();
}

void Mouse::mousePressEvent(QMouseEvent * event) {
	//	qDebug() << "is pressed";
}

void Mouse::mouseMoveEvent(QMouseEvent * event) {
	//	qDebug() << "is moving";
}

void Mouse::mouseReleaseEvent(QMouseEvent * event) {
	//	qDebug() << "is released";
}

void Mouse::hoverMoveEvent(QHoverEvent * event) {
	//	qDebug() << "hover move";
}

void Mouse::moveUp(int by) {
	int    i  = 0;
	auto * it = m_firstVisible;

	while (it->prev() != nullptr && i < by) {
		it = it->prev();
		it->setVisible(true);
		i++;
	}

	setFirstVisible(it);
}

void Mouse::moveDown(int by) {
	int    i  = 0;
	auto * it = m_firstVisible;

	while (it->next() != nullptr && i < by) {
		it->setVisible(false);
		it = it->next();
		i++;
	}

	setFirstVisible(it);
}

}  // namespace icL::editor
