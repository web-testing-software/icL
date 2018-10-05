#include "floating.h"

#include "../base/textlook.h"
#include "../start/input.h"
#include "tree.h"

#include <QJsonObject>

Floating::Floating(QObject * parent)
	: BaseLook(parent) {
	m_error = m_warn = m_console = m_bg = QColor(Qt::transparent);

	m_header = new TextLook(this);
	m_input  = new Input(this);
	m_stack  = new Tree(this);
	m_state  = new Tree(this);
}

Floating::~Floating() {
	icL_dropField(m_header);
	icL_dropField(m_input);
	icL_dropField(m_stack);
	icL_dropField(m_state);
}

TextLook * Floating::header() const {
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

Input * Floating::input() const {
	return m_input;
}

QColor Floating::bg() const {
	return m_bg;
}

void Floating::setUp(const QJsonObject & obj) {
	m_header->setUp(obj.value("header").toObject());
	m_stack->setUp(obj.value("stack").toObject());
	m_state->setUp(obj.value("state").toObject());
	m_input->setUp(obj.value("input").toObject());

	m_error   = objToColor(obj.value("error").toObject());
	m_warn    = objToColor(obj.value("warn").toObject());
	m_console = objToColor(obj.value("console").toObject());
	m_bg      = objToColor(obj.value("bg").toObject());

	emit errorChanged(m_error);
	emit warnChanged(m_warn);
	emit consoleChanged(m_console);
	emit bgChanged(m_bg);
}

QJsonObject Floating::getUp() {
	return {{"header", m_header->getUp()},      {"stack", m_stack->getUp()},
			{"state", m_state->getUp()},        {"input", m_input->getUp()},
			{"error", colorToObj(m_error)},     {"warn", colorToObj(m_warn)},
			{"console", colorToObj(m_console)}, {"bg", colorToObj(m_bg)}};
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

void Floating::setBg(QColor bg) {
	if (m_bg == bg)
		return;

	m_bg = bg;
	emit bgChanged(m_bg);
}
