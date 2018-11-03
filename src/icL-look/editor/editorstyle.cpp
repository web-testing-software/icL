#include "editorstyle.h"

#include <cmath>

#include <QFontMetrics>
#include <QtDebug>

namespace icL::look {

EditorStyle::EditorStyle(QObject * parent)
    : QObject(parent) {

	m_font.setFixedPitch(true);
	m_font.setPixelSize(m_fontS);
	m_font.setFamily("monospace");

	fixFont();
}

int EditorStyle::charW() const {
	return m_charW;
}

int EditorStyle::charH() const {
	return m_charH;
}

int EditorStyle::fontS() const {
	return m_fontS;
}

int EditorStyle::lineS() const {
	return m_lineS;
}

int EditorStyle::tabSize() const {
	return m_tabSize;
}

bool EditorStyle::saveTabs() const {
	return m_saveTabs;
}

const QFont & EditorStyle::font() {
	return m_font;
}

int EditorStyle::changePadding() const {
	return m_changePadding;
}

int EditorStyle::newLinePadding() const {
	return m_newLinePadding;
}

int EditorStyle::changeWidth() const {
	return m_changeWidth;
}

int EditorStyle::phanthomHeight() const {
	return m_phanthomHeight;
}

void EditorStyle::setCharW(int charW) {
	if (m_charW == charW)
		return;

	m_charW = charW;
	emit charWChanged(m_charW);
}

void EditorStyle::setCharH(int charH) {
	if (m_charH == charH)
		return;

	m_charH = charH;
	emit charHChanged(m_charH);
}

void EditorStyle::setFontS(int fontS) {
	if (m_fontS == fontS)
		return;

	m_fontS = fontS;
	m_font.setPixelSize(m_fontS);
	fixFont();
	hasChangeChanges = true;
	emit fontSChanged(m_fontS);
}

void EditorStyle::setLineS(int lineS) {
	// The line spacing must be always a even number
	if ((lineS & 1) != 0) {
		lineS++;
	}

	if (m_lineS == lineS)
		return;

	m_lineS       = lineS;
	m_divLineSBy2 = lineS / 2;
	m_fullLineH   = m_charH + lineS;

	hasChangeChanges = true;
	emit lineSChanged(m_lineS);
}

void EditorStyle::setTabSize(int tabSize) {
	if (m_tabSize == tabSize)
		return;

	m_tabSize = tabSize;
	emit tabSizeChanged(m_tabSize);
}

void EditorStyle::setSaveTabs(bool saveTabs) {
	if (m_saveTabs == saveTabs)
		return;

	m_saveTabs = saveTabs;
	emit saveTabsChanged(m_saveTabs);
}

void EditorStyle::setChangePadding(int changePadding) {
	if (m_changePadding == changePadding)
		return;

	m_changePadding  = changePadding;
	hasChangeChanges = true;
	emit changePaddingChanged(m_changePadding);
}

void EditorStyle::setNewLinePadding(int newLinePadding) {
	if (m_newLinePadding == newLinePadding)
		return;

	m_newLinePadding = newLinePadding;
	hasChangeChanges = true;
	emit newLinePaddingChanged(m_newLinePadding);
}

void EditorStyle::setChangeWidth(int changeWidth) {
	if (m_changeWidth == changeWidth)
		return;

	m_changeWidth    = changeWidth;
	hasChangeChanges = true;
	emit changeWidthChanged(m_changeWidth);
}

void EditorStyle::setPhanthomHeight(int phanthomHeight) {
	if (m_phanthomHeight == phanthomHeight)
		return;

	m_phanthomHeight = phanthomHeight;
	hasChangeChanges = true;
	emit phanthomHeightChanged(m_phanthomHeight);
}

void EditorStyle::fixFont() {
	QFontMetricsF fmetrics(m_font);

	m_font.setLetterSpacing(QFont::PercentageSpacing, 100.f);

	qreal charWidth = fmetrics.averageCharWidth();
	setCharW(std::ceil(charWidth));

	qreal neededSpacing = static_cast<float>(m_charW) - charWidth;
	m_font.setLetterSpacing(QFont::AbsoluteSpacing, neededSpacing);

	setCharH(std::ceil(fmetrics.height()));
	m_fullLineH = m_charH + m_lineS;
}

}  // namespace icL::look
