#include "mouse.h"

#include "../private/line.h"
#include "../private/selection.h"
#include "../private/styleproxy.h"
#include "linenumbers.h"

#include <QCursor>
#include <QDebug>

namespace icL::editor {

Mouse::Mouse(QQuickItem * parent)
	: Keyboard(parent) {
	setAcceptedMouseButtons(
	  Qt::LeftButton | Qt::MiddleButton | Qt::RightButton);
	setAcceptHoverEvents(true);
	setCursor({Qt::IBeamCursor});
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
				scrollDownBy(-delta.y() / m_proxy->fullLineH());
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
				scrollUpBy(delta.y() / m_proxy->fullLineH());
			}
		}
	}

	emit firstCharNrChanged(xScroll);
	emit requestRepaint();
}

void Mouse::mousePressEvent(QMouseEvent * event) {
	int line = event->y() / m_proxy->fullLineH() + m_firstVisible->lineNumber();
	int ch   = qRound(
			   static_cast<float>(event->x() - m_leftPadding) /
			   static_cast<float>(m_proxy->charW())) +
			 xScroll;

	m_main->beginSelection(line, ch);
	updateCurrentLine();
}

void Mouse::mouseMoveEvent(QMouseEvent * event) {
	int line = event->y() / m_proxy->fullLineH() + m_firstVisible->lineNumber();
	int ch   = qRound(
			   static_cast<float>(event->x() - m_leftPadding) /
			   static_cast<float>(m_proxy->charW())) +
			 xScroll;

	m_main->selectTo(line, ch);
	updateCurrentLine();
}

void Mouse::mouseReleaseEvent(QMouseEvent * event) {
	//	qDebug() << "is released";
}

void Mouse::hoverMoveEvent(QHoverEvent * event) {
	//	qDebug() << "hover move";
}

}  // namespace icL::editor
