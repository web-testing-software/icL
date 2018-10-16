#include "editor.h"

#include "../export/chars.h"
#include "charformat.h"
#include "editorstyle.h"
#include "highlight.h"
#include "line.h"

#include <QJsonObject>
#include <QTextCharFormat>

namespace icL::look {

Editor::Editor(QObject * parent)
	: BaseLook(parent) {

	m_style      = new EditorStyle(this);
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
	icL_dropField(m_style);
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

EditorStyle * Editor::style() {
	return m_style;
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

void Editor::updateOccurrence() {
	Chars::occurence.background = m_occurrence->background();
	Chars::occurence.border     = m_occurrence->border();
}

void Editor::updateNumber() {
	updateStyle(Chars::number, m_number);
}

void Editor::updateString() {
	updateStyle(Chars::string, m_string);
}

void Editor::updateType() {
	updateStyle(Chars::type, m_type);
}

void Editor::updateLocal() {
	updateStyle(Chars::local, m_local);
}

void Editor::updateGlobal() {
	updateStyle(Chars::global, m_global);
}

void Editor::updateProperty() {
	updateStyle(Chars::property, m_property);
}

void Editor::updateMethod() {
	updateStyle(Chars::method, m_method);
}

void Editor::updateFunction() {
	updateStyle(Chars::function, m_function);
}

void Editor::updateKeyword() {
	updateStyle(Chars::keyword, m_keyword);
}

void Editor::updateComment() {
	updateStyle(Chars::comment, m_comment);
}

void Editor::updateSystem() {
	updateStyle(Chars::system, m_system);
}

void Editor::updateError() {
	updateStyle(Chars::error, m_error);
}

void Editor::updateWarning() {
	updateStyle(Chars::warning, m_warning);
}

void Editor::updateStyle(TextCharFormat & chars, const CharFormat * format) {
	TextCharFormat cf;

	cf.font = m_style->font();

	cf.font.setItalic(format->italic());
	cf.font.setBold(format->bold());

	cf.text = format->foreground();

	if (format->background().alpha() != 0) {
		cf.background = format->background();
	}
	else {
		cf.background = {Qt::NoBrush};
	}

	if (format->underline() != 0) {
		cf.underline.setColor(format->undercolor());

		switch (format->underline()) {
		case 1:
			cf.underline.setStyle(Qt::SolidLine);
			break;

		case 2:
			cf.underline.setStyle(Qt::DashLine);
			break;

		case 3:
			cf.underline.setStyle(Qt::DotLine);
			break;

		case 4:
			cf.underline.setStyle(Qt::DashDotLine);
			break;

		case 5:
			cf.underline.setStyle(Qt::DashDotDotLine);
			break;

		default:
			cf.underline.setStyle(Qt::NoPen);
		}
	}
	else {
		cf.underline = {Qt::NoPen};
	}

	chars = cf;
	Chars::update();
}

void Editor::bindChars() {
	// clang-format off

	connect(m_number,   &CharFormat::undercolorChanged, this, &Editor::updateNumber);
	connect(m_number,   &CharFormat::underlineChanged,  this, &Editor::updateNumber);
	connect(m_number,   &CharFormatBase::boldChanged,   this, &Editor::updateNumber);
	connect(m_number,   &CharFormatBase::italicChanged, this, &Editor::updateNumber);
	connect(m_number,   &TextLook::foregroundChanged,   this, &Editor::updateNumber);
	connect(m_number,   &TextLook::backgroundChanged,   this, &Editor::updateNumber);

	connect(m_string,   &CharFormat::undercolorChanged, this, &Editor::updateString);
	connect(m_string,   &CharFormat::underlineChanged,  this, &Editor::updateString);
	connect(m_string,   &CharFormatBase::boldChanged,   this, &Editor::updateString);
	connect(m_string,   &CharFormatBase::italicChanged, this, &Editor::updateString);
	connect(m_string,   &TextLook::foregroundChanged,   this, &Editor::updateString);
	connect(m_string,   &TextLook::backgroundChanged,   this, &Editor::updateString);

	connect(m_type,     &CharFormat::undercolorChanged, this, &Editor::updateType);
	connect(m_type,     &CharFormat::underlineChanged,  this, &Editor::updateType);
	connect(m_type,     &CharFormatBase::boldChanged,   this, &Editor::updateType);
	connect(m_type,     &CharFormatBase::italicChanged, this, &Editor::updateType);
	connect(m_type,     &TextLook::foregroundChanged,   this, &Editor::updateType);
	connect(m_type,     &TextLook::backgroundChanged,   this, &Editor::updateType);

	connect(m_local,    &CharFormat::undercolorChanged, this, &Editor::updateLocal);
	connect(m_local,    &CharFormat::underlineChanged,  this, &Editor::updateLocal);
	connect(m_local,    &CharFormatBase::boldChanged,   this, &Editor::updateLocal);
	connect(m_local,    &CharFormatBase::italicChanged, this, &Editor::updateLocal);
	connect(m_local,    &TextLook::foregroundChanged,   this, &Editor::updateLocal);
	connect(m_local,    &TextLook::backgroundChanged,   this, &Editor::updateLocal);

	connect(m_global,   &CharFormat::undercolorChanged, this, &Editor::updateGlobal);
	connect(m_global,   &CharFormat::underlineChanged,  this, &Editor::updateGlobal);
	connect(m_global,   &CharFormatBase::boldChanged,   this, &Editor::updateGlobal);
	connect(m_global,   &CharFormatBase::italicChanged, this, &Editor::updateGlobal);
	connect(m_global,   &TextLook::foregroundChanged,   this, &Editor::updateGlobal);
	connect(m_global,   &TextLook::backgroundChanged,   this, &Editor::updateGlobal);

	connect(m_property, &CharFormat::undercolorChanged, this, &Editor::updateProperty);
	connect(m_property, &CharFormat::underlineChanged,  this, &Editor::updateProperty);
	connect(m_property, &CharFormatBase::boldChanged,   this, &Editor::updateProperty);
	connect(m_property, &CharFormatBase::italicChanged, this, &Editor::updateProperty);
	connect(m_property, &TextLook::foregroundChanged,   this, &Editor::updateProperty);
	connect(m_property, &TextLook::backgroundChanged,   this, &Editor::updateProperty);

	connect(m_method,   &CharFormat::undercolorChanged, this, &Editor::updateMethod);
	connect(m_method,   &CharFormat::underlineChanged,  this, &Editor::updateMethod);
	connect(m_method,   &CharFormatBase::boldChanged,   this, &Editor::updateMethod);
	connect(m_method,   &CharFormatBase::italicChanged, this, &Editor::updateMethod);
	connect(m_method,   &TextLook::foregroundChanged,   this, &Editor::updateMethod);
	connect(m_method,   &TextLook::backgroundChanged,   this, &Editor::updateMethod);

	connect(m_function, &CharFormat::undercolorChanged, this, &Editor::updateFunction);
	connect(m_function, &CharFormat::underlineChanged,  this, &Editor::updateFunction);
	connect(m_function, &CharFormatBase::boldChanged,   this, &Editor::updateFunction);
	connect(m_function, &CharFormatBase::italicChanged, this, &Editor::updateFunction);
	connect(m_function, &TextLook::foregroundChanged,   this, &Editor::updateFunction);
	connect(m_function, &TextLook::backgroundChanged,   this, &Editor::updateFunction);

	connect(m_keyword,  &CharFormat::undercolorChanged, this, &Editor::updateKeyword);
	connect(m_keyword,  &CharFormat::underlineChanged,  this, &Editor::updateKeyword);
	connect(m_keyword,  &CharFormatBase::boldChanged,   this, &Editor::updateKeyword);
	connect(m_keyword,  &CharFormatBase::italicChanged, this, &Editor::updateKeyword);
	connect(m_keyword,  &TextLook::foregroundChanged,   this, &Editor::updateKeyword);
	connect(m_keyword,  &TextLook::backgroundChanged,   this, &Editor::updateKeyword);

	connect(m_comment,  &CharFormat::undercolorChanged, this, &Editor::updateComment);
	connect(m_comment,  &CharFormat::underlineChanged,  this, &Editor::updateComment);
	connect(m_comment,  &CharFormatBase::boldChanged,   this, &Editor::updateComment);
	connect(m_comment,  &CharFormatBase::italicChanged, this, &Editor::updateComment);
	connect(m_comment,  &TextLook::foregroundChanged,   this, &Editor::updateComment);
	connect(m_comment,  &TextLook::backgroundChanged,   this, &Editor::updateComment);

	connect(m_system,   &CharFormat::undercolorChanged, this, &Editor::updateSystem);
	connect(m_system,   &CharFormat::underlineChanged,  this, &Editor::updateSystem);
	connect(m_system,   &CharFormatBase::boldChanged,   this, &Editor::updateSystem);
	connect(m_system,   &CharFormatBase::italicChanged, this, &Editor::updateSystem);
	connect(m_system,   &TextLook::foregroundChanged,   this, &Editor::updateSystem);
	connect(m_system,   &TextLook::backgroundChanged,   this, &Editor::updateSystem);

	// clang-format off
}

void Editor::bindHighlights() {
	// clang-format off
	connect(m_occurrence, &Highlight::backgroundChanged, this, &Editor::updateOccurrence);
	connect(m_occurrence, &Highlight::borderChanged,     this, &Editor::updateOccurrence);
	// clang-format on
}

void Editor::bindMessages() {
	// clang-format off
	connect(m_error,   &CharFormat::undercolorChanged, this, &Editor::updateError);
	connect(m_error,   &CharFormat::underlineChanged,  this, &Editor::updateError);
	connect(m_error,   &CharFormatBase::boldChanged,   this, &Editor::updateError);
	connect(m_error,   &CharFormatBase::italicChanged, this, &Editor::updateError);
	connect(m_error,   &TextLook::foregroundChanged,   this, &Editor::updateError);
	connect(m_error,   &TextLook::backgroundChanged,   this, &Editor::updateError);

	connect(m_warning, &CharFormat::undercolorChanged, this, &Editor::updateWarning);
	connect(m_warning, &CharFormat::underlineChanged,  this, &Editor::updateWarning);
	connect(m_warning, &CharFormatBase::boldChanged,   this, &Editor::updateWarning);
	connect(m_warning, &CharFormatBase::italicChanged, this, &Editor::updateWarning);
	connect(m_warning, &TextLook::foregroundChanged,   this, &Editor::updateWarning);
	connect(m_warning, &TextLook::backgroundChanged,   this, &Editor::updateWarning);
	// clang-format on
}

}  // namespace icL::look
