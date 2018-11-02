#include "logic.h"

#include "../fragment/fragment.h"
#include "../private/cursor.h"
#include "../private/fixer.h"
#include "../private/line.h"
#include "../private/selection.h"
#include "linenumbers.h"

namespace icL::editor {

Logic::Logic(QQuickItem * parent)
    : QQuickPaintedItem(parent) {
	m_main  = new Selection();
	m_fixer = new Fixer();

	//	connect(
	//	  m_main->begin(), &Cursor::fragmentChanged, this,
	//	  &Logic::updateCurrentLine);
	//	connect(
	//	  m_main->end(), &Cursor::fragmentChanged, this,
	//&Logic::updateCurrentLine);
}

Logic::~Logic() {
	delete m_main;
	delete m_fixer;
}

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

Fixer * Logic::fixer() {
	return m_fixer;
}

void Logic::makeChanged() {
	changed = true;
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

		fragment->insert(m_main->begin(), m_main->end(), 0, str);
		line->setFirst(fragment);
		line->getText(true);
		line->updateLength();
		addNewLine(line);
	}

	auto * it = m_firstVisible = m_first;
	for (int i = 0; i < numberOfLines && it != nullptr; i++) {
		it->setVisible(true);
		it = it->next();
	}

	// Testing data
	// To be removed after
	auto * ptr = m_first->next()->next()->next()->next()->next()->next();
	ptr        = ptr->next()->next()->next()->next()->next()->next();
	m_first->next()->next()->setHasBreakPoint(true);
	m_first->next()->next()->next()->next()->next()->next()->setHasBreakPoint(
	  true);

	ptr->setHasBreakPoint(true);
	debugLine = m_current = ptr->prev();

	auto * sixth = m_first->next()->next()->next()->next()->next();
	m_main->begin()->setFragment(sixth->first());
	m_main->end()->setFragment(m_current->first());
	m_main->begin()->setPosition(16);
	m_main->end()->setPosition(2);
	m_main->begin()->updatePreffered();
	m_main->end()->updatePreffered();

	m_fixer->fixNow(m_first);

	return true;
}

void Logic::setFirst(Line * first) {
	if (m_first == first)
		return;

	m_first = first;
}

void Logic::setCurrent(Line * current) {
	if (m_current == current)
		return;

	m_current = current;
}

void Logic::setFirstVisible(Line * firstVisible) {
	if (m_firstVisible == firstVisible)
		return;

	m_firstVisible = firstVisible;
	firstVisible->setVisible(true);

	emit firstLineNrChanged();
}

void Logic::addNewLine(Line * line, bool focus) {
	if (m_current == nullptr) {
		m_first = m_current = line;
		line->setLineNumber(1);
	}
	else {
		if (m_current->next() != nullptr) {
			m_current->next()->setPrev(line);
		}
		line->setNext(m_current->next());
		m_current->setNext(line);
		line->setPrev(m_current);
		line->setLineNumber(m_current->lineNumber() + 1);
		line->setVisible(m_current->visible());

		setCurrent(line);
	}
}

void Logic::updateCurrentLine() {
	Fragment * fragment;

	if (m_main->rtl()) {
		fragment = m_main->begin()->fragment();
	}
	else {
		fragment = m_main->end()->fragment();
	}

	if (fragment != nullptr) {
		setCurrent(fragment->line());

		emit requestRepaint();
	}
}

void Logic::changeNumberOfLines(int newValue) {
	numberOfLines  = newValue;
	numberOfDigits = 0;

	while (newValue > 0) {
		newValue /= 10;
		numberOfDigits++;
	}

	updateBackgroundGeometry();
}

}  // namespace icL::editor
