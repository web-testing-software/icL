#include "debug.h"

namespace icL::toolkit::panels {

Debug::Debug(QObject * parent)
	: QObject(parent) {}

bool Debug::stack() const {
	return m_stack;
}

bool Debug::state() const {
	return m_state;
}

bool Debug::console() const {
	return m_console;
}

bool Debug::browser() const {
	return m_browser;
}

void Debug::setStack(bool stack) {
	if (m_stack == stack)
		return;

	m_stack = stack;
	emit stackChanged(m_stack);
}

void Debug::setState(bool state) {
	if (m_state == state)
		return;

	m_state = state;
	emit stateChanged(m_state);
}

void Debug::setConsole(bool console) {
	if (m_console == console)
		return;

	m_console = console;
	emit consoleChanged(m_console);
}

void Debug::setBrowser(bool browser) {
	if (m_browser == browser)
		return;

	m_browser = browser;
	emit browserChanged(m_browser);
}

}  // namespace icL::toolkit::panels
