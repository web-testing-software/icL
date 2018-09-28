#include "input.h"

namespace icL::look::start {

Input::Input(QObject * parent)
	: Link(parent) {}

Input::~Input() {
	if (m_inactive != nullptr) {
		delete m_inactive;
	}

	if (m_selection != nullptr) {
		delete m_selection;
	}
}

base::Text * Input::inactive() const {
	return m_inactive;
}

base::Text * Input::selection() const {
	return m_selection;
}

QColor Input::cursor() const {
	return m_cursor;
}

void Input::setInactive(base::Text * inactive) {
	if (m_inactive == inactive)
		return;

	m_inactive = inactive;
	emit inactiveChanged(m_inactive);
}

void Input::setSelection(base::Text * selection) {
	if (m_selection == selection)
		return;

	m_selection = selection;
	emit selectionChanged(m_selection);
}

void Input::setCursor(QColor cursor) {
	if (m_cursor == cursor)
		return;

	m_cursor = cursor;
	emit cursorChanged(m_cursor);
}

}  // namespace icL::look::start
