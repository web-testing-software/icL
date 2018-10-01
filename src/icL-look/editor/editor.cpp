#include "charformat.h"
#include "editor.h"
#include "highlight.h"
#include "line.h"

#include <QJsonObject>

namespace icL::look::editor {

Editor::Editor(QObject * parent)
	: Base(parent) {

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

void Editor::setUp(const QJsonObject & obj) {
	m_text->setUp(obj.value("text").toObject());
	m_selection->setUp(obj.value("selection").toObject());
	m_number->setUp(obj.value("number").toObject());
	m_string->setUp(obj.value("string").toObject());
	m_type->setUp(obj.value("type").toObject());
	m_local->setUp(obj.value("local").toObject());
	m_global->setUp(obj.value("global").toObject());
	m_property->setUp(obj.value("property").toObject());
	m_method->setUp(obj.value("method").toObject());
	m_function->setUp(obj.value("function").toObject());
	m_keyword->setUp(obj.value("keyword").toObject());
	m_comment->setUp(obj.value("comment").toObject());
	m_system->setUp(obj.value("system").toObject());
	m_error->setUp(obj.value("error").toObject());
	m_warning->setUp(obj.value("warning").toObject());

	m_occurrence->setUp(obj.value("occurrence").toObject());

	m_current->setUp(obj.value("current").toObject());
	m_debug->setUp(obj.value("debug").toObject());
	m_breakpoint->setUp(obj.value("breakpoint").toObject());
}

QJsonObject Editor::getUp() {
	return {{"text", m_text->getUp()},
			{"selection", m_selection->getUp()},
			{"number", m_number->getUp()},
			{"string", m_string->getUp()},
			{"type", m_type->getUp()},
			{"local", m_local->getUp()},
			{"global", m_global->getUp()},
			{"property", m_property->getUp()},
			{"method", m_method->getUp()},
			{"function", m_function->getUp()},
			{"keyword", m_keyword->getUp()},
			{"comment", m_comment->getUp()},
			{"system", m_system->getUp()},
			{"error", m_error->getUp()},
			{"warning", m_warning->getUp()},
			{"occurrence", m_occurrence->getUp()},
			{"current", m_current->getUp()},
			{"debug", m_debug->getUp()},
			{"breakpoint", m_breakpoint->getUp()}};
}

}  // namespace icL::look::editor
