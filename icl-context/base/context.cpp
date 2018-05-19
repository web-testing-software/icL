#include "context.h"

#include "object/boolean.h"
#include "object/double.h"
#include "object/element.h"
#include "object/int.h"
#include "object/List.h"
#include "object/object.h"
#include "object/string.h"
#include "object/void.h"

#include <icl-memory/structures/webelement.h>

#include <utility>

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

bool Context::isExecuable() const {
	return false;
}

bool Context::execute() {
	return true;
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

object::Object * Context::fromValue(const QVariant & value) {
	object::Object * ret;
	memory::Type     type = memory::variantTypeToType(value.type());

	switch (type) {
	case memory::Type::Boolean:
		ret = new object::Boolean{il, value, true};
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
	QStringList List = var.toStringList();

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
		for (QString & str : List) {
			str.replace(R"(")", R"(\")");
		}
		ret = R"([")" % List.join(R"(",")") % R"("])";
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

Context * Context::prev() const {
	return m_prev;
}

Role Context::role() const {
	return m_role;
}

}  // namespace icL::context
