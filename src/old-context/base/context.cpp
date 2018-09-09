#include "context.h"

#include "object/bool.h"
#include "object/double.h"
#include "object/element.h"
#include "object/int.h"
#include "object/list.h"
#include "object/value.h"
#include "object/string.h"
#include "object/void.h"

#include <icl-memory/structures/webelement.h>

#include <utility>

#include <QDebug>
#include <QStringBuilder>
#include <QVariant>


namespace icL::context {

Context::Context(memory::InterLevel * il)
	: memory::Node(il){};

Context * Context::getNewContext() const {
	return newContext;
}

Context * Context::getBeginContext() {
	return nullptr;
}

Context * Context::getEndContext() {
	return nullptr;
}

bool Context::isRightToLeft() const {
	return true;
}

bool Context::isExecutable() const {
	return false;
}

memory::StepType::Value Context::execute() {
	return memory::StepType::None;
}

bool Context::hasValue() const {
	return false;
}

Context * Context::runProperty(Prefix prefix, const QString & name) {
	if (prefix != Prefix::None) {
		il->vm->exception(
		  {-405, "This object does not support prefixed properties"});
	}
	else {
		il->vm->exception({-7, "No such property: " + name});
	}

	return nullptr;
}

Context * Context::runMethod(
  const QString & name, [[maybe_unused]] memory::ArgList & args) {
	il->vm->exception({-7, "No such method: " + name});

	return nullptr;
}

bool Context::isResultative() const {
	return false;
}

bool Context::isComplex() const {
	return false;
}

value::Value * Context::fromValue(const QVariant & value) {
	return fromValue(il, value);
}

value::Value * Context::fromValue(
  memory::InterLevel * il, const QVariant & value) {
	value::Value * ret;
	memory::Type     type = memory::variantTypeToType(value.type());

	switch (type) {
	case memory::Type::Bool:
		ret = new object::Bool{il, value, true};
		break;

	case memory::Type::Int:
		ret = new object::Int{il, value, true};
		break;

	case memory::Type::Double:
		ret = new object::Double{il, value, true};
		break;

	case memory::Type::String:
		ret = new object::String{il, value, true};
		break;

	case memory::Type::List:
		ret = new object::List{il, value, true};
		break;

	case memory::Type::Element:
		ret = new object::Element{il, value, true};
		break;

	case memory::Type::Void:
		ret = new object::Void{il};
		break;
	}

	return ret;
}

value::Value * Context::fromValue(
  memory::InterLevel * il, memory::DataState * ds, const QString & name) {
	value::Value * ret;
	memory::Type     type = ds->getType(name);

	switch (type) {
	case memory::Type::Bool:
		ret = new object::Bool{il, ds, name};
		break;

	case memory::Type::Int:
		ret = new object::Int{il, ds, name};
		break;

	case memory::Type::Double:
		ret = new object::Double{il, ds, name};
		break;

	case memory::Type::String:
		ret = new object::String{il, ds, name};
		break;

	case memory::Type::List:
		ret = new object::List{il, ds, name};
		break;

	case memory::Type::Element:
		ret = new object::Element{il, ds, name};
		break;

	case memory::Type::Void:
		ret = new object::Void{il, ds, name};
		break;
	}

	return ret;
}

int Context::getBeginCursorPosition() {
	return beginCursorPosition;
}

int Context::getEndCursorPosition() {
	return endCursorPostion;
}

void Context::setCursorPositions(int begin, int end) {
	beginCursorPosition = begin;
	endCursorPostion    = end;
}

Context * Context::getFirst() {
	Context * it = this;

	while (it->m_prev != nullptr) {
		it = it->m_prev;
	}

	return it;
}

Context * Context::getLast() {
	Context * it = this;

	while (it->m_next != nullptr) {
		it = it->m_next;
	}

	return it;
}

void Context::sendWrongArglist(
  memory::ArgList & args, const QString & expected) {
	QStringList types;

	for (auto arg : args) {
		types.append(memory::typeToString(arg.object->type()));
	}

	il->vm->exception({-203, "Wrong arglist: <" % types.join(", ") %
							   ">, expected " % expected});
}

QString Context::varToJsString(const QVariant & var) {
	QString     ret;
	QStringList list = var.toStringList();

	memory::WebElement web = var.value<memory::WebElement>();

	switch (var.type()) {
	case QVariant::Bool:
		ret = var.toBool() ? "true" : "false";
		break;

	case QVariant::Int:
		ret = QString::number(var.toInt());
		break;

	case QVariant::Double:
		ret = QString::number(var.toDouble());
		break;

	case QVariant::String:
		ret = '"' % var.toString() % '"';
		break;

	case QVariant::StringList:
		for (QString & str : list) {
			str.replace(R"(")", R"(\")");
		}
		ret = R"([")" % list.join(R"(",")") % R"("])";
		break;

	case QVariant::Type::UserType:
		ret = web.variable;
		break;

	default:
		// Elude clang error
		break;
	}

	return ret;
}

Context * Context::next() const {
	return m_next;
}

void Context::replaceWith(Context * context) {
	context->m_prev = m_prev;
	context->m_next = m_next;
	if (m_prev != nullptr) {
		m_prev->m_next = context;
	}
	if (m_next != nullptr) {
		m_next->m_prev = context;
	}
}

void Context::link(Context * context) {
	context->m_next = nullptr;
	context->m_prev = this;

	m_next = context;

	if (role() == context->role()) {
		qDebug() << "stop here";
	}

	qDebug() << static_cast<int>(role()) << context
			 << static_cast<int>(context->role());
}

void Context::link(Context * c0, Context * c1, Context * c2) {
	if (c0 != nullptr) {
		c0->m_next = c1 != nullptr ? c1 : c2;
	}

	if (c1 != nullptr) {
		c1->m_next = c2;
		c1->m_prev = c0;
	}

	if (c2 != nullptr) {
		c2->m_prev = c1 != nullptr ? c1 : c0;
	}
}

Context * Context::prev() const {
	return m_prev;
}

Role Context::role() const {
	return m_role;
}

#ifdef icL_debug

QString roleToString(Role role) {
	QString ret;

	switch (role) {
	case Role::NoRole:
		ret = "NoRole";
		break;
	case Role::Object:
		ret = "Object";
		break;
	case Role::If:
		ret = "If";
		break;
	case Role::Else:
		ret = "Else";
		break;
	case Role::Exists:
		ret = "Exists";
		break;
	case Role::Slot:
		ret = "Slot";
		break;
	case Role::Code:
		ret = "Code";
		break;
	case Role::ForAny:
		ret = "ForAny";
		break;
	case Role::DOM:
		ret = "DOM";
		break;
	case Role::Tab:
		ret = "Tab";
		break;
	case Role::Property:
		ret = "Property";
		break;
	case Role::Method:
		ret = "Method";
		break;
	case Role::Alternative:
		ret = "Alternative";
		break;
	case Role::Assign:
		ret = "Assign";
		break;
	case Role::Function:
		ret = "Function";
		break;
	case Role::Argument:
		ret = "Argument";
		break;
	case Role::JsValue:
		ret = "JsValue";
		break;

	case Role::JsFile:
		ret = "JsFile";
		break;
	}

	return ret;
}

#endif

}  // namespace icL::context
