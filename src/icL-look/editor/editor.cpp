#include "editor.h"

namespace icL::look::editor {

Editor::Editor(QObject * parent)
	: QObject(parent) {
	m_breakpoint = new Line(this);
	m_comment    = new CharFormat(this);
	m_current    = new Line(this);
	m_debug      = new Line(this);
	m_error      = new CharFormat(this);
	m_function   = new CharFormat(this);
	m_global     = new CharFormat(this);
	m_keyword    = new CharFormat(this);
	m_local      = new CharFormat(this);
	m_method     = new CharFormat(this);
	m_number     = new CharFormat(this);
	m_occurrence = new Highlight(this);
	m_property   = new CharFormat(this);
	m_selection  = new CharFormat(this);
	m_string     = new CharFormat(this);
	m_system     = new CharFormat(this);
	m_text       = new CharFormat(this);
	m_type       = new CharFormat(this);
	m_warning    = new CharFormat(this);
}

Editor::~Editor() {
	icL_dropField(m_breakpoint);
	icL_dropField(m_comment);
	icL_dropField(m_current);
	icL_dropField(m_debug);
	icL_dropField(m_error);
	icL_dropField(m_function);
	icL_dropField(m_global);
	icL_dropField(m_keyword);
	icL_dropField(m_local);
	icL_dropField(m_method);
	icL_dropField(m_number);
	icL_dropField(m_occurrence);
	icL_dropField(m_property);
	icL_dropField(m_selection);
	icL_dropField(m_string);
	icL_dropField(m_system);
	icL_dropField(m_text);
	icL_dropField(m_type);
	icL_dropField(m_warning);
}

CharFormat * Editor::text() const {
	return m_text;
}

CharFormat * Editor::selection() const {
	return m_selection;
}

CharFormat * Editor::number() const {
	return m_number;
}

CharFormat * Editor::string() const {
	return m_string;
}

CharFormat * Editor::type() const {
	return m_type;
}

CharFormat * Editor::local() const {
	return m_local;
}

CharFormat * Editor::global() const {
	return m_global;
}

CharFormat * Editor::property() const {
	return m_property;
}

CharFormat * Editor::method() const {
	return m_method;
}

CharFormat * Editor::function() const {
	return m_function;
}

CharFormat * Editor::keyword() const {
	return m_keyword;
}

CharFormat * Editor::comment() const {
	return m_comment;
}

CharFormat * Editor::system() const {
	return m_system;
}

CharFormat * Editor::error() const {
	return m_error;
}

CharFormat * Editor::warning() const {
	return m_warning;
}

Highlight * Editor::occurrence() const {
	return m_occurrence;
}

Line * Editor::current() const {
	return m_current;
}

Line * Editor::debug() const {
	return m_debug;
}

Line * Editor::breakpoint() const {
	return m_breakpoint;
}

void Editor::setText(CharFormat * text) {
	if (m_text == text)
		return;

	m_text = text;
	emit textChanged(m_text);
}

void Editor::setSelection(CharFormat * selection) {
	if (m_selection == selection)
		return;

	m_selection = selection;
	emit selectionChanged(m_selection);
}

void Editor::setNumber(CharFormat * number) {
	if (m_number == number)
		return;

	m_number = number;
	emit numberChanged(m_number);
}

void Editor::setString(CharFormat * string) {
	if (m_string == string)
		return;

	m_string = string;
	emit stringChanged(m_string);
}

void Editor::setType(CharFormat * type) {
	if (m_type == type)
		return;

	m_type = type;
	emit typeChanged(m_type);
}

void Editor::setLocal(CharFormat * local) {
	if (m_local == local)
		return;

	m_local = local;
	emit localChanged(m_local);
}

void Editor::setGlobal(CharFormat * global) {
	if (m_global == global)
		return;

	m_global = global;
	emit globalChanged(m_global);
}

void Editor::setProperty(CharFormat * property) {
	if (m_property == property)
		return;

	m_property = property;
	emit propertyChanged(m_property);
}

void Editor::setMethod(CharFormat * method) {
	if (m_method == method)
		return;

	m_method = method;
	emit methodChanged(m_method);
}

void Editor::setFunction(CharFormat * function) {
	if (m_function == function)
		return;

	m_function = function;
	emit functionChanged(m_function);
}

void Editor::setKeyword(CharFormat * keyword) {
	if (m_keyword == keyword)
		return;

	m_keyword = keyword;
	emit keywordChanged(m_keyword);
}

void Editor::setComment(CharFormat * comment) {
	if (m_comment == comment)
		return;

	m_comment = comment;
	emit commentChanged(m_comment);
}

void Editor::setSystem(CharFormat * system) {
	if (m_system == system)
		return;

	m_system = system;
	emit systemChanged(m_system);
}

void Editor::setError(CharFormat * error) {
	if (m_error == error)
		return;

	m_error = error;
	emit errorChanged(m_error);
}

void Editor::setWarning(CharFormat * warning) {
	if (m_warning == warning)
		return;

	m_warning = warning;
	emit warningChanged(m_warning);
}

void Editor::setOccurrence(Highlight * occurrence) {
	if (m_occurrence == occurrence)
		return;

	m_occurrence = occurrence;
	emit occurrenceChanged(m_occurrence);
}

void Editor::setCurrent(Line * current) {
	if (m_current == current)
		return;

	m_current = current;
	emit currentChanged(m_current);
}

void Editor::setDebug(Line * debug) {
	if (m_debug == debug)
		return;

	m_debug = debug;
	emit debugChanged(m_debug);
}

void Editor::setBreakpoint(Line * breakpoint) {
	if (m_breakpoint == breakpoint)
		return;

	m_breakpoint = breakpoint;
	emit breakpointChanged(m_breakpoint);
}

}  // namespace icL::look::editor
