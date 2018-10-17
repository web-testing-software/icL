#include "editor.h"

#include "../private/fragment.h"
#include "../private/line.h"

namespace icL::editor {

Editor::Editor(QQuickItem * parent)
	: QQuickPaintedItem(parent) {}

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

void Editor::makeChanged() {
	changed = true;
	update();
}

void Editor::clear() {
	auto * it = m_first;

	while (it != nullptr) {
		auto * tmp = it;

		it = it->next();
		delete tmp;
	}

	m_first        = nullptr;
	m_firstVisible = nullptr;
	m_lastVisible  = nullptr;
	m_current      = nullptr;
	numberOfLines  = 0;
}

bool Editor::loadFile(const QString & path) {
	QFile       file(path);
	QTextStream stream(&file);

	if (!file.open(QFile::ReadOnly)) {
		return false;
	}

	while (!file.atEnd()) {
		QString str = stream.readLine(160);

		auto * line     = new Line(this);
		auto * fragment = new Fragment(line);

		fragment->insert(0, str);
		line->getText();
		addNewLine(line);
	}

	auto * it = m_first;
	for (int i = 0; i < numberOfLines && it != nullptr; i++) {
		it->setVisible(true);
		it = it->next();
	}

	return true;
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

void Editor::addNewLine(Line * line, bool focus) {
	if (m_current == nullptr) {
		m_first = m_current = line;
		line->setLineNumber(1);
	}
	else {
		if (m_current->next() != nullptr) {
			m_current->next()->setPrev(line);
			line->setNext(m_current->next());
		}
		m_current->setNext(line);
		line->setPrev(m_current);
		line->setLineNumber(m_current->lineNumber() + 1);

		if (m_lastVisible == m_current && focus) {
			m_firstVisible = m_firstVisible->next();
			m_lastVisible  = line;
		}

		setCurrent(line);
	}

	numberOfLines++;
}

}  // namespace icL::editor
