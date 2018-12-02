#include "opacitymask.h"

#include "../private/line.h"
#include "editorinternal.h"

#include <QOpenGLFunctions>
#include <QPainter>

namespace icL::editor {

OpacityMask::OpacityMask(QQuickItem * parent)
    : QQuickPaintedItem(parent) {
	setRenderTarget(QQuickPaintedItem::FramebufferObject);
	setAntialiasing(true);
}

void OpacityMask::paint(QPainter * painter) {
	if (m_editor == nullptr) {
		return;
	}

	painter->beginNativePainting();

	static QOpenGLFunctions gl;

	gl.initializeOpenGLFunctions();

	gl.glEnable(GL_SCISSOR_TEST);
	gl.glScissor(
	  0, 0, m_editor->lineNumberArea.right() + 1,
	  m_editor->lineNumberArea.bottom());

	gl.glClearColor(1.0, 1.0, 1.0, 1.0);

	gl.glClear(GL_COLOR_BUFFER_BIT);

	painter->endNativePainting();

	auto * it = m_editor->m_firstVisible;

	painter->setPen(Qt::NoPen);
	painter->setBrush(Qt::white);

	while (it != nullptr && it->visible()) {

		if (it == m_editor->current() || it->hasBreakPoint()) {
			painter->drawPolygon(
			  m_editor->leftArrow.translated(0, it->lastY()));
		}

		it = it->next();
	}
}

void OpacityMask::setEditor(EditorInternal * editor) {
	if (m_editor == editor)
		return;

	m_editor = editor;
}

}  // namespace icL::editor
