#include "drawing.h"

#include "../private/line.h"

#include <icL-look/editor/editorstyle.h>
#include <icL-look/export/chars.h>

#include <QPainter>
#include <QStaticText>

namespace icL::editor {

Drawing::Drawing(QQuickItem * parent)
	: Logic(parent) {
	connect(
	  this, &Logic::widthChanged, this, &Drawing::updateBackgroundGeometry);
	connect(
	  this, &Logic::heightChanged, this, &Drawing::updateBackgroundGeometry);
}

look::EditorStyle * Drawing::style() const {
	return m_style;
}

look::Chars * Drawing::chars() const {
	return m_chars;
}

void Drawing::paint(QPainter * painter) {
	if (!m_chars)
		return;

	painter->setRenderHint(QPainter::Antialiasing);

	painter->setPen(Qt::NoPen);
	painter->setBrush(m_chars->cline.lineNumber.background);
	painter->drawRect(lineNumberArea);

	painter->setBrush(m_chars->cline.background);
	painter->drawRect(contentArea);

	drawLineNumbers(painter);
	drawBreakPoints(painter);
}

void Drawing::setStyle(look::EditorStyle * style) {
	if (m_style == style)
		return;

	m_style = style;
	updateBackgroundGeometry();
	emit styleChanged(m_style);
}

void Drawing::setChars(look::Chars * chars) {
	if (m_chars == chars)
		return;

	m_chars = chars;
	update();
	emit charsChanged(m_chars);
}

void Drawing::updateBackgroundGeometry() {
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

	QList<QPoint> lnArea = {};

	leftArrow = {
	  QVector<QPoint>({{0, 0},
					   {lineNumberArea.right(), 0},
					   {scissorsArea.left(), m_style->m_fullLineH / 2},
					   {lineNumberArea.right(), m_style->m_fullLineH},
					   {0, m_style->m_fullLineH}})};

	lineRect = contentArea;
	lineRect.setBottom(m_style->m_fullLineH);
}

void Drawing::drawLineNumbers(QPainter * painter) {
	painter->setFont(m_chars->cline.lineNumber.font);
	painter->setPen(m_chars->cline.lineNumber.text);
	painter->setBrush(Qt::NoBrush);

	auto * it = m_firstVisible;
	int yStep = m_style->m_fullLineH;
	int yPos  = m_style->m_divLineSBy2 +
			   (m_style->m_charH - it->getCache()->size().height()) / 2;

	while (it != nullptr && it->visible()) {
		auto * stext = it->getCache();

		painter->drawStaticText(
		  lineNumberRight - m_style->m_charW * it->charsNumberInLineNumber(),
		  yPos, *stext);

		yPos += yStep;
		it = it->next();
	}
}

void Drawing::drawBreakPoints(QPainter * painter) {

	int    yStep = m_style->m_fullLineH;
	int    yPos  = 0;
	auto * it    = m_firstVisible;

	painter->setPen(Qt::NoPen);

	if (m_chars->breakpoint.background.color().alpha() > 0) {
		painter->setBrush(m_chars->breakpoint.background);

		while (it != nullptr && it->visible()) {

			if (it->hasBreakPoint()) {
				painter->drawRect(lineRect.translated(0, yPos));
			}

			yPos += yStep;
			it = it->next();
		}
	}

	// Init for second drawing
	it   = m_firstVisible;
	yPos = 0;
	painter->setBrush(m_chars->breakpoint.lineNumber.background);

	while (it != nullptr && it->visible()) {

		if (it->hasBreakPoint()) {
			painter->drawConvexPolygon(leftArrow.translated(0, yPos));
		}

		yPos += yStep;
		it = it->next();
	}

	// Init for third drawing
	it   = m_firstVisible;
	yPos = m_style->m_divLineSBy2 +
		   (m_style->m_charH - it->getCache()->size().height()) / 2;
	painter->setBrush(Qt::NoBrush);
	painter->setPen(m_chars->breakpoint.lineNumber.text);

	while (it != nullptr && it->visible()) {

		if (it->hasBreakPoint()) {
			auto * stext = it->getCache();

			painter->drawStaticText(
			  lineNumberRight -
				m_style->m_charW * it->charsNumberInLineNumber(),
			  yPos, *stext);
		}

		yPos += yStep;
		it = it->next();
	}
}

void Drawing::drawCurrentLine() {}

void Drawing::drawDebugLine() {}

void Drawing::setUpClipArea() {}

void Drawing::drawSelection() {}

void Drawing::drawContent() {}

}  // namespace icL::editor
