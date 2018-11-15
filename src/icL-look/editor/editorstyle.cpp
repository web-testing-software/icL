#include "editorstyle.h"

#include <cmath>

#include <QFontDatabase>
#include <QFontMetrics>
#include <QtDebug>

namespace icL::look {

EditorStyle::EditorStyle(QObject * parent)
    : QObject(parent) {

    int id = QFontDatabase::addApplicationFont(":/fonts/NotoMono-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);

    m_font.setFamily(family);
	m_font.setFixedPitch(true);
    m_font.setPixelSize(m_fontS);

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
