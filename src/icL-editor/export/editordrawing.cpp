#include "editordrawing.h"

#include <icL-look/editor/editorstyle.h>
#include <icL-look/export/chars.h>

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

look::Chars * EditorDrawing::chars() const {
	return m_chars;
}

void EditorDrawing::paint(QPainter * painter) {
	if (!m_chars)
		return;

	painter->setPen(Qt::NoPen);
	painter->setBrush(m_chars->cline.lineNumber.background);
	painter->drawRect(lineNumberArea);

	painter->setBrush(m_chars->cline.background);
	painter->drawRect(contentArea);
}

void EditorDrawing::setStyle(look::EditorStyle * style) {
	if (m_style == style)
		return;

	m_style = style;
	updateBackgroundGeometry();
	emit styleChanged(m_style);
}

void EditorDrawing::setChars(look::Chars * chars) {
	if (m_chars == chars)
		return;

	m_chars = chars;
	update();
	emit charsChanged(m_chars);
}

void EditorDrawing::updateBackgroundGeometry() {
	if (m_style == nullptr)
		return;

	lineNumberRight = m_style->m_fullLineH + numberOfDigits * m_style->m_charW;

	lineNumberArea.setLeft(0);
	lineNumberArea.setTop(0);
	lineNumberArea.setBottom(width());
	lineNumberArea.setRight(lineNumberRight + m_style->m_fullLineH);

	contentArea.setLeft(lineNumberArea.right());
	contentArea.setTop(0);
	contentArea.setBottom(height());
	contentArea.setRight(width());

	scissorsArea.setLeft(contentArea.left() + m_style->m_fullLineH / 2);
	scissorsArea.setTop(0);
	scissorsArea.setRight(width());
	scissorsArea.setBottom(height());
}

}  // namespace icL::editor
