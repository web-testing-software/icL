#include "editor.h"

namespace icL::editor {

Editor::Editor(QQuickItem * parent)
	: QQuickPaintedItem(parent) {}

look::EditorStyle * Editor::style() const {
	return m_style;
}

Selection * Editor::main() const {
	return m_main;
}

Line * Editor::first() const {
	return m_first;
}

Line * Editor::current() const {
	return m_current;
}

Line * Editor::firstVisible() const {
	return m_firstVisible;
}

Line * Editor::lastVisible() const {
	return m_lastVisible;
}

void Editor::setStyle(look::EditorStyle * style) {
	if (m_style == style)
		return;

	m_style = style;
	emit styleChanged(m_style);
}

void Editor::setFirst(Line * first) {
	if (m_first == first)
		return;

	m_first = first;
	emit firstChanged(m_first);
}

void Editor::setCurrent(Line * current) {
	if (m_current == current)
		return;

	m_current = current;
	emit currentChanged(m_current);
}

void Editor::setFirstVisible(Line * firstVisible) {
	if (m_firstVisible == firstVisible)
		return;

	m_firstVisible = firstVisible;
	emit firstVisibleChanged(m_firstVisible);
}

void Editor::setLastVisible(Line * lastVisible) {
	if (m_lastVisible == lastVisible)
		return;

	m_lastVisible = lastVisible;
	emit lastVisibleChanged(m_lastVisible);
}

}  // namespace icL::editor
