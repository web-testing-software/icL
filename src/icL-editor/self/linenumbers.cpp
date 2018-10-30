#include "linenumbers.h"

#include "../private/line.h"
#include "../private/styleproxy.h"
#include "drawing.h"

#include <icL-look/export/chars.h>

#include <QOpenGLFunctions>
#include <QPainter>

namespace icL::editor {

LineNumbers::LineNumbers(QQuickItem * parent)
	: QQuickPaintedItem(parent) {
	setRenderTarget(QQuickPaintedItem::FramebufferObject);
	setAntialiasing(true);
}

Drawing * LineNumbers::editor() const {
	return m_editor;
}

void LineNumbers::setEditor(Drawing * editor) {
	if (m_editor == editor)
		return;

	m_editor = editor;
	setWidth(editor->leftPadding);
	update();
	emit editorChanged(m_editor);
}

void LineNumbers::paint(QPainter * painter) {
	if (m_editor == nullptr) {
		return;
	}

	QTime timer;
	timer.start();

	//	painter->beginNativePainting();

	//	static QOpenGLFunctions gl;

	//	gl.initializeOpenGLFunctions();

	//	gl.glEnable(GL_SCISSOR_TEST);
	//	gl.glScissor(
	//	  0, 0, m_editor->lineNumberArea.right(),
	//	  m_editor->lineNumberArea.bottom());

	//	const QColor bg =
	// m_editor->m_chars->cline.lineNumber.background.color();
	//	gl.glClearColor(bg.redF(), bg.greenF(), bg.blueF(), bg.alphaF());

	//	gl.glClear(GL_COLOR_BUFFER_BIT);

	//	//	gl.glScissor(
	//	//	  m_editor->lineNumberArea.right(), 0,
	//	//	  width() - m_editor->lineNumberArea.right(), height());

	//	//	gl.glClearColor(0.f, 0.f, 0.f, 0.f);
	//	//	gl.glClear(GL_COLOR_BUFFER_BIT);


	//	painter->endNativePainting();

	painter->setCompositionMode(QPainter::CompositionMode_Source);

	painter->setPen(Qt::NoPen);
	painter->setBrush(m_editor->m_chars->cline.lineNumber.background);
	painter->drawRect(m_editor->lineNumberArea);

	drawBackground(painter);

	qDebug() << "render time of line numbers" << timer.elapsed();
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
				painter->setBrush(chars->breakpoint.lineNumber.background);
				int padding = proxy->lineS() * 2;
				int size    = proxy->fullLineH() - padding * 2;
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


}  // namespace icL::editor
