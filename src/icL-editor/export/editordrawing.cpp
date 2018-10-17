#include "editordrawing.h"

#include <icL-look/editor/editorstyle.h>

#include <QPainter>

namespace icL::editor {

EditorDrawing::EditorDrawing(QQuickItem * parent)
	: Editor(parent) {
	connect(
	  this, &Editor::widthChanged, this,
	  &EditorDrawing::updateBackgroundGeometry);
	connect(
	  this, &Editor::heightChanged, this,
	  &EditorDrawing::updateBackgroundGeometry);
}

look::EditorStyle * EditorDrawing::style() const {
	return m_style;
}

void EditorDrawing::paint(QPainter *painter)
{
	painter->setPen(Qt::NoPen);


	painter->drawRect(lineNumberArea);
}

void EditorDrawing::setStyle(look::EditorStyle * style) {
	if (m_style == style)
		return;

	m_style = style;
	emit styleChanged(m_style);
}

void EditorDrawing::updateBackgroundGeometry() {
	lineNumberRight = m_style->fullLineH() + numberOfDigits * m_style->charW();

	lineNumberArea.setLeft(0);
	lineNumberArea.setTop(0);
	lineNumberArea.setBottom(width());
	lineNumberArea.setRight(lineNumberRight + m_style->fullLineH());

	contentArea.setLeft(lineNumberArea.right());
	contentArea.setTop(0);
	contentArea.setBottom(height());
	contentArea.setRight(width());

	scissorsArea.setLeft(contentArea.left() + m_style->fullLineH() / 2);
	scissorsArea.setTop(0);
	scissorsArea.setRight(width());
	scissorsArea.setBottom(height());
}

}  // namespace icL::editor
