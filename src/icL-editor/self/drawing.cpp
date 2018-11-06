#include "drawing.h"

#include "../fragment/fragment.h"
#include "../private/cursor.h"
#include "../private/line.h"
#include "../private/selection.h"
#include "../private/styleproxy.h"
#include "linenumbers.h"

#include <icL-look/export/chars.h>

#include <QDateTime>
#include <QOpenGLFunctions>
#include <QPainter>
#include <QStaticText>

namespace icL::editor {

Drawing::Drawing(QQuickItem * parent)
    : Logic(parent) {
	setRenderTarget(QQuickPaintedItem::FramebufferObject);
	setAntialiasing(true);

	connect(
	  this, &Logic::widthChanged, this, &Drawing::updateBackgroundGeometry);
	connect(
	  this, &Logic::heightChanged, this, &Drawing::updateBackgroundGeometry);

	m_proxy = new StyleProxy();
}

look::EditorStyle * Drawing::style() const {
	return m_proxy->style();
}

StyleProxy * Drawing::proxy() {
	return m_proxy;
}

LineNumbers * Drawing::lineN() const {
	return m_lineN;
}

look::Chars * Drawing::chars() const {
	return m_chars;
}

look::ScrollBar * Drawing::scrollBar() const {
	return m_scrollBar;
}

int Drawing::lnWidth() const {
	return lineNumberArea.width();
}

int Drawing::linesCount() const {
	return numberOfLines;
}

int Drawing::charsInLine() const {
	return m_visibleChars;
}

int Drawing::visbileLines() const {
	return m_visibleLines;
}

int Drawing::firstLineNr() const {
	if (m_firstVisible == nullptr) {
		return 1;
	}

	return m_firstVisible->lineNumber();
}

int Drawing::firstCharNr() const {
	return xScroll;
}

void Drawing::paint(QPainter * painter) {

	if (!m_chars)
		return;

	QTime timer;
	timer.start();

	const QColor & bg = m_chars->cline.background.color();

	painter->beginNativePainting();

	static QOpenGLFunctions gl;

	gl.initializeOpenGLFunctions();

	gl.glClearColor(bg.redF(), bg.greenF(), bg.blueF(), bg.alphaF());
	gl.glClear(GL_COLOR_BUFFER_BIT);

	painter->endNativePainting();

	drawBreakPoints(painter);
	drawPhantoms(painter);
	drawCurrentLine(painter);

	drawSelection(painter, m_main);
	drawContent(painter);

	//	qDebug() << "render time" << timer.elapsed();

	//	update();
}

void Drawing::setStyle(look::EditorStyle * style) {
	if (m_proxy->style() == style)
		return;

	m_proxy->setStyle(style);
	updateBackgroundGeometry();
	emit styleChanged(style);
}

void Drawing::setChars(look::Chars * chars) {
	if (m_chars == chars)
		return;

	m_chars = chars;

	setFillColor(chars->cline.background.color());

	emit requestRepaint();
	emit charsChanged(m_chars);
}

void Drawing::setScrollBar(look::ScrollBar * scrollBar) {
	if (m_scrollBar == scrollBar)
		return;

	m_scrollBar = scrollBar;
	emit scrollBarChanged(m_scrollBar);
}

void Drawing::setLineN(LineNumbers * lineN) {
	if (m_lineN == lineN)
		return;

	m_lineN = lineN;
	emit lineNChanged(m_lineN);
}

void Drawing::setCharsInLine(int charsInLine) {
	if (m_visibleChars == charsInLine)
		return;

	m_visibleChars = charsInLine;
	emit charsInLineChanged(m_visibleChars);
}

void Drawing::setVisbileLines(int visbileLines) {
	if (m_visibleLines == visbileLines)
		return;

	m_visibleLines = visbileLines;
	emit visbileLinesChanged(m_visibleLines);
}

void Drawing::updateBackgroundGeometry() {
	if (m_proxy->style() == nullptr)
		return;

	lineNumberRight = m_proxy->fullLineH() + numberOfDigits * m_proxy->charW();

	lineNumberArea.setLeft(0);
	lineNumberArea.setTop(0);
	lineNumberArea.setBottom(static_cast<int>(height()));
	lineNumberArea.setRight(lineNumberRight + m_proxy->fullLineH());

	m_leftPadding = lineNumberArea.right() + m_proxy->fullLineH() / 2 -
					m_proxy->divLineSBy2() + 1;

	leftArrow = {
	  QVector<QPoint>({{0, 0},
					   {lineNumberArea.right() + 1, 0},
					   {m_leftPadding, m_proxy->fullLineH() / 2},
					   {lineNumberArea.right() + 1, m_proxy->fullLineH()},
					   {0, m_proxy->fullLineH()}})};

	leftRect.setRight(lineNumberArea.right());
	leftRect.setBottom(m_proxy->fullLineH() - 1);

	lineRect.setLeft(0);
	lineRect.setRight(static_cast<int>(width()));
	lineRect.setTop(0);
	lineRect.setBottom(m_proxy->fullLineH() - 1);

	if (m_lineN != nullptr) {
		m_lineN->setWidth(m_leftPadding);
	}

	emit lnWidthChanged(lineNumberArea.width());
}

void Drawing::drawBreakPoints(QPainter * painter) {

	auto * it = m_firstVisible;

	painter->setPen(Qt::NoPen);

	if (m_chars->breakpoint.background.color().alpha() > 0) {
		painter->setBrush(m_chars->breakpoint.background);

		while (it != nullptr && it->visible()) {

			if (it->hasBreakPoint()) {
				painter->drawRect(lineRect.translated(0, it->lastY()));
			}

			it = it->nextDisplay();
		}
	}
}

void Drawing::drawCurrentLine(QPainter * painter) {
	if (m_current->visible()) {
		painter->setPen(Qt::NoPen);
		painter->setBrush(m_chars->current.background);

		painter->drawRect(lineRect.translated(0, m_current->lastY()));
	}
}

void Drawing::drawPhantoms(QPainter * painter) {
	int    state = -1;
	auto * it    = m_firstVisible;

	painter->setPen(Qt::NoPen);


	while (it != nullptr && it->visible()) {

		if (it->isPhantom()) {
			if (it->isSelected()) {
				if (state != 1) {
					painter->setBrush(m_chars->phantomSelected.background);
					state = 1;
				}
			}
			else {
				if (state != 2) {
					painter->setBrush(m_chars->phantom.background);
					state = 2;
				}
			}

			painter->drawRect(lineRect.translated(0, it->lastY()));
		}

		it = it->nextDisplay();
	}
}

void Drawing::drawSelection(QPainter * painter, Selection * selection) {
	auto * beginFrag = selection->begin()->fragment();
	auto * endFrag   = selection->end()->fragment();
	auto * beginLine = beginFrag->line();
	auto * endLine   = endFrag->line();

	if (
	  beginLine->lineNumber() >
		m_firstVisible->lineNumber() + 1 +
		  static_cast<int>(height()) / m_proxy->fullLineH() ||
	  endLine->lineNumber() < m_firstVisible->lineNumber()) {
		return;
	}

	int xBegin = m_leftPadding - xScroll * m_proxy->charW();
	int xStep  = m_proxy->charW();
	int toAdd  = xStep / 2;  // Add extra space after lines
	int yStep  = m_proxy->fullLineH();

	painter->setPen(Qt::NoPen);
	painter->setBrush(m_chars->selection.background);

	if (beginLine == endLine) {
		int beginChar = selection->begin()->getPosInLine();
		int endChar   = selection->end()->getPosInLine();

		if (beginChar != endChar) {
			painter->drawRect(
			  xBegin + xStep * beginChar,
			  selection->begin()->fragment()->line()->lastY(),
			  (endChar - beginChar) * xStep, yStep);
		}
	}
	else {
		auto * it = beginLine->next();

		while (!it->visible()) {
			it = it->next();
		}

		while (it->visible() && it != endLine) {
			painter->drawRect(
			  xBegin, it->lastY(), it->length() * xStep + toAdd, yStep);
			it = it->next();
		}

		if (endLine->visible()) {
			painter->drawRect(
			  xBegin, endLine->lastY(),
			  selection->end()->getPosInLine() * xStep, yStep);
		}

		if (beginLine->visible()) {
			int left  = selection->begin()->getPosInLine();
			int right = beginLine->length();

			painter->drawRect(
			  xBegin + left * xStep, beginLine->lastY(),
			  (right - left) * xStep + toAdd, yStep);

			if (
			  beginLine->next()->length() < left &&
			  !beginLine->nextDisplay()->isPhantom()) {
				painter->setBrush(Qt::NoBrush);
				painter->setPen(m_chars->selection.border);

				int yPos = beginLine->lastY() + yStep + m_proxy->divLineSBy2();

				left = beginLine->next() != endLine
				         ? beginLine->next()->length()
				         : selection->end()->getPosInLine();
				painter->drawLine(
				  xBegin + left * xStep +
				    (beginLine->next() == endLine ? 0 : toAdd),
				  yPos, xBegin + right * xStep + toAdd, yPos);
			}
		}
	}
}

void Drawing::drawContent(QPainter * painter) {
	painter->setBrush(Qt::NoBrush);

	int fragments = 0;

	auto * itLine = m_firstVisible;
	int    yDelta = m_proxy->divLineSBy2() +
				 (m_proxy->charH() -
				  static_cast<int>(itLine->getCache()->size().height())) /
				   2;
	int xBegin = m_leftPadding - xScroll * m_proxy->charW();
	int xStep  = m_proxy->charW();

	while (itLine != nullptr && itLine->visible()) {
		auto * itFrag = itLine->first();
		int    xPos   = xBegin;

		while (itFrag != nullptr && xPos + itFrag->length() * xStep < 0) {
			xPos += itFrag->length() * xStep;
			itFrag = itFrag->next();
		}

		while (itFrag != nullptr && xPos < width()) {
			auto * stext = itFrag->getCache();

			painter->setPen(itFrag->format().text);
			painter->setFont(itFrag->format().font);

			xPos += itFrag->spaces() * xStep;
			painter->drawStaticText(xPos, itLine->lastY() + yDelta, *stext);

			xPos += itFrag->glyphs() * xStep;
			itFrag = itFrag->next();
			fragments++;
		}

		itLine = itLine->nextDisplay();
	}

	//	qDebug() << "drawed fragments" << fragments;
}

}  // namespace icL::editor
