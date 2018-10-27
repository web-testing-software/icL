#include "drawing.h"

#include "../fragment/fragment.h"
#include "../private/cursor.h"
#include "../private/line.h"
#include "../private/selection.h"
#include "../private/styleproxy.h"

#include <icL-look/export/chars.h>

#include <QDateTime>
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

	cursorTimer.start();

	m_proxy = new StyleProxy();
}

look::EditorStyle * Drawing::style() const {
	return m_proxy->style();
}

StyleProxy * Drawing::proxy() {
	return m_proxy;
}

look::Chars * Drawing::chars() const {
	return m_chars;
}

void Drawing::makeCursorOpaque() {
	cursorIsHidding = true;
	cursorTimer.start();
}

void Drawing::paint(QPainter * painter) {
	if (!m_chars)
		return;

	QTime timer;
	timer.start();

	//	painter->setRenderHint(QPainter::Antialiasing);

	painter->setPen(Qt::NoPen);
	painter->setBrush(m_chars->cline.lineNumber.background);
	painter->drawRect(lineNumberArea);

	painter->setBrush(m_chars->cline.background);
	painter->drawRect(contentArea);

	drawLineNumbers(painter);
	drawBreakPoints(painter);
	drawCurrentLine(painter);
	//	drawDebugLine(painter);
	drawSelection(painter, m_main);
	drawContent(painter);

	drawCursor(painter);

	//	qDebug() << "render time" << timer.elapsed();
	update();
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
	update();
	emit charsChanged(m_chars);
}

void Drawing::updateBackgroundGeometry() {
	if (m_proxy->style() == nullptr)
		return;

	lineNumberRight = m_proxy->fullLineH() + numberOfDigits * m_proxy->charW();

	lineNumberArea.setLeft(0);
	lineNumberArea.setTop(0);
	lineNumberArea.setBottom(static_cast<int>(width()));
	lineNumberArea.setRight(lineNumberRight + m_proxy->fullLineH());

	contentArea.setLeft(lineNumberArea.right());
	contentArea.setTop(0);
	contentArea.setBottom(static_cast<int>(height()));
	contentArea.setRight(static_cast<int>(width()));

	scissorsArea.setLeft(contentArea.left() + m_proxy->fullLineH() / 2);
	scissorsArea.setTop(0);
	scissorsArea.setRight(static_cast<int>(width()));
	scissorsArea.setBottom(static_cast<int>(height()));

	leftArrow = {
	  QVector<QPoint>({{0, 0},
	                   {lineNumberArea.right(), 0},
	                   {scissorsArea.left(), m_proxy->fullLineH() / 2},
	                   {lineNumberArea.right(), m_proxy->fullLineH()},
	                   {0, m_proxy->fullLineH()}})};

	lineRect = contentArea;
	lineRect.setBottom(m_proxy->fullLineH());
}

void Drawing::drawLineNumbers(QPainter * painter) {
	painter->setFont(m_chars->cline.lineNumber.font);
	painter->setPen(m_chars->cline.lineNumber.text);
	painter->setBrush(Qt::NoBrush);

	auto * it    = m_firstVisible;
	int    yStep = m_proxy->fullLineH();
	int    yPos =
	  m_proxy->divLineSBy2() +
	  (m_proxy->charH() - static_cast<int>(it->getCache()->size().height())) /
	    2;

	while (it != nullptr && it->visible()) {
		auto * stext = it->getCache();

		painter->drawStaticText(
		  lineNumberRight - m_proxy->charW() * it->charsNumberInLineNumber(),
		  yPos, *stext);

		yPos += yStep;
		it = it->next();
	}
}

void Drawing::drawBreakPoints(QPainter * painter) {

	int    yStep = m_proxy->fullLineH();
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
	it = m_firstVisible;
	yPos =
	  m_proxy->divLineSBy2() +
	  (m_proxy->charH() - static_cast<int>(it->getCache()->size().height())) /
	    2;
	painter->setBrush(Qt::NoBrush);
	painter->setPen(m_chars->breakpoint.lineNumber.text);
	painter->setFont(m_chars->breakpoint.lineNumber.font);

	while (it != nullptr && it->visible()) {

		if (it->hasBreakPoint()) {
			auto * stext = it->getCache();

			painter->drawStaticText(
			  lineNumberRight -
			    m_proxy->charW() * it->charsNumberInLineNumber(),
			  yPos, *stext);
		}

		yPos += yStep;
		it = it->next();
	}
}

void Drawing::drawLine(
  QPainter * painter, Line * line, look::LineFormat & format) {
	if (!line->visible()) {
		return;
	}

	int visibleLineNumber = line->lineNumber() - m_firstVisible->lineNumber();
	int yPos              = visibleLineNumber * m_proxy->fullLineH();

	painter->setPen(Qt::NoPen);
	painter->setBrush(format.background);
	painter->drawRect(lineRect.translated(0, yPos));

	painter->setBrush(format.lineNumber.background);
	painter->drawConvexPolygon(leftArrow.translated(0, yPos));


	if (line->hasBreakPoint()) {
		painter->setBrush(m_chars->breakpoint.lineNumber.background);
		//		painter->drawRect(0, yPos, m_proxy->fullLineH(),
		// m_proxy->fullLineH());
		int padding = m_proxy->lineS() * 2;
		int size    = m_proxy->fullLineH() - padding * 2;
		painter->drawEllipse(padding, yPos + padding, size, size);
	}

	painter->setBrush(Qt::NoBrush);
	painter->setPen(format.lineNumber.text);
	painter->setFont(format.lineNumber.font);
	painter->drawStaticText(
	  lineNumberRight - m_proxy->charW() * line->charsNumberInLineNumber(),
	  yPos + m_proxy->divLineSBy2() +
	    (m_proxy->charH() -
	     static_cast<int>(line->getCache()->size().height())) /
	      2,
	  *line->getCache());
}

void Drawing::drawCurrentLine(QPainter * painter) {
	drawLine(painter, m_current, m_chars->current);
}

void Drawing::drawDebugLine(QPainter * painter) {
	drawLine(painter, debugLine, m_chars->debug);
}

void Drawing::setUpClipArea(QPainter * painter) {
	painter->setClipRect(scissorsArea);
}

void Drawing::drawSelection(QPainter * painter, Selection * selection) {
	auto * beginFrag = selection->begin()->fragment();
	auto * endFrag   = selection->end()->fragment();
	auto * beginLine = beginFrag->line();
	auto * endLine   = endFrag->line();

	if (
	  beginLine->lineNumber() > m_lastVisible->lineNumber() ||
	  endLine->lineNumber() < m_firstVisible->lineNumber()) {
		return;
	}

	int xBegin = scissorsArea.left();
	int xStep  = m_proxy->charW();
	int toAdd  = xStep / 2;  // Add extra space after lines
	int yStep  = m_proxy->fullLineH();
	int yPos =
	  (beginLine->lineNumber() - m_firstVisible->lineNumber() + 1) * yStep;

	painter->setPen(Qt::NoPen);
	painter->setBrush(m_chars->selection.background);

	if (beginLine == endLine) {
		int beginChar = selection->begin()->getPosInLine();
		int endChar   = selection->end()->getPosInLine();

		if (beginChar != endChar) {
			painter->drawRect(
			  xBegin + xStep * beginChar, yPos - yStep,
			  (endChar - beginChar) * xStep, yStep);
		}
	}
	else {
		auto * it = beginLine->next();

		while (!it->visible()) {
			it = it->next();
			yPos += yStep;
		}

		while (it->visible() && it != endLine) {
			painter->drawRect(
			  xBegin, yPos, it->length() * xStep + toAdd, yStep);
			it = it->next();
			yPos += yStep;
		}

		if (endLine->visible()) {
			painter->drawRect(
			  xBegin, yPos, selection->end()->getPosInLine() * xStep, yStep);
		}

		if (beginLine->visible()) {
			int left  = selection->begin()->getPosInLine();
			int right = beginLine->length();

			yPos =
			  (beginLine->lineNumber() - m_firstVisible->lineNumber()) * yStep;
			painter->drawRect(
			  xBegin + left * xStep, yPos, (right - left) * xStep + toAdd,
			  yStep);

			if (beginLine->next()->length() < left) {
				painter->setBrush(Qt::NoBrush);
				painter->setPen(m_chars->selection.border);

				yPos += yStep + m_proxy->divLineSBy2();
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

	auto * itLine = m_firstVisible;
	int    yStep  = m_proxy->fullLineH();
	int    yPos   = m_proxy->divLineSBy2() +
	           (m_proxy->charH() -
	            static_cast<int>(itLine->getCache()->size().height())) /
	             2;
	int xBegin = scissorsArea.left();
	int xStep  = m_proxy->charW();

	while (itLine != nullptr && itLine->visible()) {
		auto * itFrag = itLine->first();
		int    xPos   = xBegin;

		while (itFrag != nullptr && xPos < width()) {
			auto * stext = itFrag->getCache();

			painter->setPen(itFrag->format().text);
			painter->setFont(itFrag->format().font);

			xPos += itFrag->spaces() * xStep;
			painter->drawStaticText(xPos, yPos, *stext);

			xPos += itFrag->glyphs() * xStep;
			itFrag = itFrag->next();
		}

		yPos += yStep;
		itLine = itLine->next();
	}
}

qreal Drawing::transition(qreal x) {
	// x = (e^(x*e) - 1) / (e^e - 1) for x {0, 1}, max error 0.0015 = 0.15%
	return x * (x * (x * (x * 0.6755328851108425f - 0.3190423664446824f) +
	                 0.47886115389358097f) +
	            0.1646483274402586f);
}

void Drawing::drawCursor(QPainter * painter) {
	auto * itSelection = m_main;
	int    xBegin      = scissorsArea.left();
	int    elapsed     = cursorTimer.elapsed();
	qreal  alpha       = static_cast<qreal>(elapsed) / 1000.f;

	if (cursorIsHidding) {
		alpha = 1.f - transition(alpha);
	}
	else {
		alpha = transition(alpha);
	}

	if (alpha > 1.f || alpha < 0) {
		alpha = alpha > 1.f ? 1.f : 0.f;
		cursorTimer.start();
		cursorIsHidding = !cursorIsHidding;
	}

	painter->setOpacity(alpha);

	while (itSelection != nullptr) {
		Cursor * cursor;

		if (itSelection->rtl()) {
			cursor = itSelection->begin();
		}
		else {
			cursor = itSelection->end();
		}

		auto * line = cursor->fragment()->line();

		if (line->visible()) {
			int yPos = (line->lineNumber() - m_firstVisible->lineNumber()) *
			           m_proxy->fullLineH();
			int xPos = xBegin + cursor->getPosInLine() * m_proxy->charW();

			painter->setPen(cursor->fragment()->format().text);

			painter->drawLine(xPos, yPos, xPos, yPos + m_proxy->fullLineH());
		}

		itSelection = itSelection->next();
	}
}

}  // namespace icL::editor
