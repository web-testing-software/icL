#include "logic.h"

#include "../private/fragment.h"
#include "../private/line.h"

namespace icL::editor {

Logic::Logic(QQuickItem * parent)
	: QQuickPaintedItem(parent) {}

Selection * Logic::main() const {
	return m_main;
}

Line * Logic::first() const {
	return m_first;
}

Line * Logic::current() const {
	return m_current;
}

Line * Logic::firstVisible() const {
	return m_firstVisible;
}

Line * Logic::lastVisible() const {
	return m_lastVisible;
}

void Logic::makeChanged() {
	changed = true;
	update();
}

void Logic::clear() {
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

bool Logic::loadFile(const QString & path) {
	QFile       file(path);
	QTextStream stream(&file);

	if (!file.open(QFile::ReadOnly)) {
		return false;
	}

	while (!stream.atEnd()) {
		QString str = stream.readLine(160);

		auto * line     = new Line(this);
		auto * fragment = new Fragment(line);

		fragment->insert(0, str);
		line->setFirst(fragment);
		line->getText();
		addNewLine(line);
	}

	auto * it = m_firstVisible = m_first;
	for (int i = 0; i < numberOfLines && it != nullptr; i++) {
		it->setVisible(true);
		it            = it->next();
		m_lastVisible = it;
	}

	// Testing data
	// To be removed after
	auto * ptr = m_first->next()->next()->next()->next()->next()->next();
	ptr = ptr->next()->next()->next()->next()->next()->next();
	m_first->next()->next()->setHasBreakPoint(true);
	m_first->next()->next()->next()->next()->next()->next()->setHasBreakPoint(
	  true);

	ptr->setHasBreakPoint(true);
	debugLine = m_current = ptr->prev();

	return true;
}

void Logic::setFirst(Line * first) {
	if (m_first == first)
		return;

	m_first = first;
	emit firstChanged(m_first);
}

void Logic::setCurrent(Line * current) {
	if (m_current == current)
		return;

	m_current = current;
	emit currentChanged(m_current);
}

void Logic::setFirstVisible(Line * firstVisible) {
	if (m_firstVisible == firstVisible)
		return;

	m_firstVisible = firstVisible;
	emit firstVisibleChanged(m_firstVisible);
}

void Logic::setLastVisible(Line * lastVisible) {
	if (m_lastVisible == lastVisible)
		return;

	m_lastVisible = lastVisible;
	emit lastVisibleChanged(m_lastVisible);
}

void Logic::addNewLine(Line * line, bool focus) {
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

	changeNumberOfLines(numberOfLines + 1);
}

void Logic::changeNumberOfLines(int newValue) {
	numberOfLines  = newValue;
	numberOfDigits = 0;

	while (newValue > 0) {
		newValue /= 10;
		numberOfDigits++;
	}
}

}  // namespace icL::editor
