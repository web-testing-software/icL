#include "editor.h"

#include <QPainter>

namespace icL::editor {

Editor::Editor(QQuickItem * parent)
	: QQuickPaintedItem(parent) {
	lineNumbers.setWidth(100);

	setRenderTarget(Editor::FramebufferObject);

	connect(this, &Editor::widthChanged, this, &Editor::resize);
	connect(this, &Editor::heightChanged, this, &Editor::resize);
}

look::Editor * Editor::look() const {
	return m_look;
}

int Editor::charW() const {
	return m_charW;
}

int Editor::charH() const {
	return m_charH;
}

int Editor::fontS() const {
	return m_fontS;
}

void Editor::setLook(look::Editor * look) {
	if (m_look == look)
		return;

	m_look = look;
	emit lookChanged(m_look);
}

void Editor::setCharW(int charW) {
	if (m_charW == charW)
		return;

	m_charW = charW;
	emit charWChanged(m_charW);
}

void Editor::setCharH(int charH) {
	if (m_charH == charH)
		return;

	m_charH = charH;
	emit charHChanged(m_charH);
}

void Editor::setFontS(int fontS) {
	if (m_fontS == fontS)
		return;

	m_fontS = fontS;
	emit fontSChanged(m_fontS);
}

void Editor::resize() {
	lineNumbers.setBottom(height());
	textArea.setLeft(100);
	textArea.setRight(width());
	textArea.setBottom(height());

	update();
}

void Editor::paint(QPainter * painter) {

	QFont font("monospace");
	font.setPixelSize(16);
	painter->setFont(font);

	painter->setPen(Qt::NoPen);

	painter->setBrush(QBrush(QColor("#e2e2e2")));
	painter->drawRect(lineNumbers);

	painter->setBrush(QBrush(QColor("#f2f2f2")));
	painter->drawRect(textArea);

	painter->setBrush(QBrush(QColor("#232323")));
	painter->setPen(QColor("#232323"));
	painter->drawText(QPoint(25, 25), "Text");
}

}  // namespace icL::editor
