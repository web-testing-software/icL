#include "editorstylehub.h"

#include <math.h>

#include <QFontMetrics>

namespace icL::editor {

EditorStyleHub::EditorStyleHub(QObject * parent)
	: QObject(parent) {

	m_font.setFixedPitch(true);
	m_font.setPixelSize(m_fontS);

	fixFont();
}

int EditorStyleHub::charW() const {
	return m_charW;
}

int EditorStyleHub::charH() const {
	return m_charH;
}

int EditorStyleHub::fontS() const {
	return m_fontS;
}

int EditorStyleHub::lineS() const {
	return m_lineS;
}

int EditorStyleHub::divLineSBy2() const {
	return m_divLineSBy2;
}

int EditorStyleHub::fullLineH() const {
	return m_fullLineH;
}

const QFont & EditorStyleHub::font() {
	return m_font;
}

void EditorStyleHub::setCharW(int charW) {
	if (m_charW == charW)
		return;

	m_charW = charW;
	emit charWChanged(m_charW);
}

void EditorStyleHub::setCharH(int charH) {
	if (m_charH == charH)
		return;

	m_charH = charH;
	emit charHChanged(m_charH);
}

void EditorStyleHub::setFontS(int fontS) {
	if (m_fontS == fontS)
		return;

	m_fontS = fontS;
	m_font.setPixelSize(m_fontS);
	fixFont();
	emit fontSChanged(m_fontS);
}

void EditorStyleHub::setLineS(int lineS) {
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

void EditorStyleHub::fixFont() {
	QFontMetricsF fmetrics(m_font);

	m_font.setLetterSpacing(QFont::PercentageSpacing, 100.f);

	qreal charWidth = fmetrics.horizontalAdvance(QString('_', 160)) / 160.f;
	setCharW(std::ceil(charWidth));

	qreal neededSpacing = static_cast<float>(m_charW) - charWidth;
	m_font.setLetterSpacing(QFont::AbsoluteSpacing, neededSpacing);

	setCharH(std::ceil(fmetrics.height()));
	setLineS(std::ceil(fmetrics.lineSpacing()));
}

}  // namespace icL::editor
