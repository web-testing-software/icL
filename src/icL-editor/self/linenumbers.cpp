#include "linenumbers.h"

#include "../private/line.h"
#include "../private/styleproxy.h"
#include "editorinternal.h"

#include <icL-look/export/chars.h>

#include <QOpenGLFunctions>
#include <QPainter>
#include <QStaticText>

namespace icL::editor {

LineNumbers::LineNumbers(QQuickItem * parent)
	: QQuickPaintedItem(parent) {
	setRenderTarget(QQuickPaintedItem::FramebufferObject);
	setAntialiasing(true);
}

void LineNumbers::setEditor(EditorInternal * editor) {
	if (m_editor == editor)
		return;

	m_editor = editor;
	setWidth(editor->m_leftPadding);
	update();
}

void LineNumbers::paint(QPainter * painter) {
	if (m_editor == nullptr) {
		return;
	}

	QTime timer;
	timer.start();

	painter->setCompositionMode(QPainter::CompositionMode_Source);

	painter->setPen(Qt::NoPen);
	painter->setBrush(m_editor->m_chars->cline.lineNumber.background);
	painter->drawRect(m_editor->lineNumberArea);

	drawBackground(painter);

	painter->setCompositionMode(QPainter::CompositionMode_SourceOver);

	drawText(painter);

	drawChanges(painter);

	//	qDebug() << "render time of line numbers" << timer.elapsed();
}

void LineNumbers::drawBackground(QPainter * painter) {
	auto * it    = m_editor->m_firstVisible;
	auto * proxy = m_editor->m_proxy;
	auto * chars = m_editor->m_chars;
	int    yStep = proxy->fullLineH();
	int    yPos  = 0;

	painter->setPen(Qt::NoPen);

	while (it != nullptr && yPos < height()) {

		if (it == m_editor->current()) {
			painter->setBrush(chars->current.lineNumber.background);
			painter->drawPolygon(m_editor->leftArrow.translated(0, yPos));

			if (it->hasBreakPoint()) {
				int padding = proxy->lineS() * 2;
				int size    = proxy->fullLineH() - padding * 2;

				painter->setBrush(chars->breakpoint.lineNumber.text.color());
				painter->drawEllipse(padding, yPos + padding, size, size);
			}
		}
		else if (it->hasBreakPoint()) {
			painter->setBrush(chars->breakpoint.lineNumber.background);
			painter->drawPolygon(m_editor->leftArrow.translated(0, yPos));
		}

		it->setVisible(true);
		it->setLastY(yPos);
		yPos += yStep;
		it = it->next();
	}

	while (it != nullptr && it->visible()) {
		it->setVisible(false);
		it = it->next();
	}
}

void LineNumbers::drawText(QPainter * painter) {
	auto * it    = m_editor->m_firstVisible;
	auto * proxy = m_editor->m_proxy;
	auto * chars = m_editor->m_chars;
	int    yDelta =
	  proxy->divLineSBy2() +
	  (proxy->charH() - static_cast<int>(it->getCache()->size().height())) / 2;

	painter->setBrush(Qt::NoBrush);

	int type = -1;

	while (it != nullptr && it->visible()) {

		if (it == m_editor->current() && type != 1) {
			painter->setPen(chars->current.lineNumber.text);
			painter->setFont(chars->current.lineNumber.font);
			type = 1;
		}
		else if (it->hasBreakPoint() && type != 2) {
			painter->setPen(chars->breakpoint.lineNumber.text);
			painter->setFont(chars->breakpoint.lineNumber.font);
			type = 2;
		}
		else if (type != 3) {
			painter->setPen(chars->cline.lineNumber.text);
			painter->setFont(chars->cline.lineNumber.font);
			type = 3;
		}

		auto * stext = it->getCache();

		painter->drawStaticText(
		  m_editor->lineNumberRight -
			proxy->charW() * it->charsNumberInLineNumber(),
		  it->lastY() + yDelta, *stext);

		it = it->next();
	}
}

void LineNumbers::drawChanges(QPainter * painter) {
	auto * proxy = m_editor->m_proxy;
	auto * chars = m_editor->m_chars;

	if (proxy->hasChangeChanges()) {
		updateGeometry();
	}

	// draw unsaved lines
	auto * it = m_editor->m_firstVisible;

	painter->setPen(Qt::NoPen);
	painter->setBrush(chars->changes.changed);
	while (it->visible()) {
		if (it->isChanged()) {
			if (it->isNew()) {
				painter->drawRect(newLine.translated(0, it->lastY()));
			}
			else {
				painter->drawRect(change.translated(0, it->lastY()));
			}
		}
		it = it->next();
	}

	// draw saved lines
	it = m_editor->m_firstVisible;

	painter->setBrush(chars->changes.saved);
	while (it->visible()) {
		if (it->wasChanged()) {
			if (it->isNew()) {
				painter->drawRect(newLine.translated(0, it->lastY()));
			}
			else {
				painter->drawRect(change.translated(0, it->lastY()));
			}
		}
		it = it->next();
	}

	// draw lines with phantoms
	it = m_editor->m_firstVisible;

	while (it->visible()) {
		if (it->hasPhantoms()) {
			painter->drawRect(phantom.translated(0, it->lastY()));
		}
		it = it->next();
	}
}

void LineNumbers::updateGeometry() {
	auto * proxy = m_editor->m_proxy;

	change.setTop(proxy->changePadding());
	change.setHeight(proxy->fullLineH() - proxy->changePadding() * 2);
	change.setRight(proxy->changeWidth() - 1);

	newLine.setTop(proxy->newLinePadding());
	newLine.setHeight(proxy->fullLineH() - proxy->newLinePadding() * 2);
	newLine.setRight(proxy->changeWidth() - 1);

	phantom.setTop(proxy->fullLineH() - proxy->phanthomHeight() / 2);
	phantom.setHeight(proxy->phanthomHeight());
	phantom.setWidth(proxy->changeWidth());

	phantomLine.setTop(0);
	phantomLine.setRight(proxy->changeWidth() - 1);
	phantomLine.setBottom(proxy->fullLineH());
}


}  // namespace icL::editor
