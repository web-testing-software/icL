#include "floating.h"

namespace icL::look::session {

Floating::Floating(QObject * parent)
	: QObject(parent) {
	m_error = m_warn = m_console = m_bg = QColor(Qt::transparent);

	m_header = new base::Text(this);
	m_input  = new start::Input(this);
	m_stack  = new Tree(this);
	m_state  = new Tree(this);
}

Floating::~Floating() {
	icL_dropField(m_header);
	icL_dropField(m_input);
	icL_dropField(m_stack);
	icL_dropField(m_state);
}

base::Text * Floating::header() const {
	return m_header;
}

Tree * Floating::stack() const {
	return m_stack;
}

Tree * Floating::state() const {
	return m_state;
}

QColor Floating::error() const {
	return m_error;
}

QColor Floating::warn() const {
	return m_warn;
}

QColor Floating::console() const {
	return m_console;
}

start::Input * Floating::input() const {
	return m_input;
}

QColor Floating::bg() const {
	return m_bg;
}

void Floating::setHeader(base::Text * header) {
	if (m_header == header)
		return;

	m_header = header;
	emit headerChanged(m_header);
}

void Floating::setStack(Tree * stack) {
	if (m_stack == stack)
		return;

	m_stack = stack;
	emit stackChanged(m_stack);
}

void Floating::setState(Tree * state) {
	if (m_state == state)
		return;

	m_state = state;
	emit stateChanged(m_state);
}

void Floating::setError(QColor error) {
	if (m_error == error)
		return;

	m_error = error;
	emit errorChanged(m_error);
}

void Floating::setWarn(QColor warn) {
	if (m_warn == warn)
		return;

	m_warn = warn;
	emit warnChanged(m_warn);
}

void Floating::setConsole(QColor console) {
	if (m_console == console)
		return;

	m_console = console;
	emit consoleChanged(m_console);
}

void Floating::setInput(start::Input * input) {
	if (m_input == input)
		return;

	m_input = input;
	emit inputChanged(m_input);
}

void Floating::setBg(QColor bg) {
	if (m_bg == bg)
		return;

	m_bg = bg;
	emit bgChanged(m_bg);
}

}  // namespace icL::look::session
