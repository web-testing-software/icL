#include "editor.h"

namespace icL::editor {

Editor::Editor(QQuickItem * parent)
	: QQuickPaintedItem(parent) {}

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

}  // namespace icL::editor
