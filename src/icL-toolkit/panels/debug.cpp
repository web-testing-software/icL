#include "debug.h"

#include <QJsonObject>

namespace icL::toolkit::panels {

Debug::Debug(QObject * parent)
    : BasePanels(parent) {}

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

void Debug::setUp(const QJsonObject & obj) {
	BasePanels::setUp(obj);

	m_stack   = obj.value("stack").toBool();
	m_state   = obj.value("state").toBool();
	m_console = obj.value("console").toBool();
	m_browser = obj.value("browser").toBool();
}

QJsonObject Debug::getUp() {
	auto obj = BasePanels::getUp();

	obj["stack"]   = m_stack;
	obj["state"]   = m_state;
	obj["console"] = m_console;
	obj["browser"] = m_browser;

	return obj;
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
