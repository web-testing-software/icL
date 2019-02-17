#include "value.h"

#include <icl-context/base/object/value.h>
#include <icl-context/control/main/code.h>

namespace icL::context::data::js {

Value::Value(memory::InterLevel * il)
    : Js(il) {
	m_role = Role::JsValue;
}

QString Value::getCode() {
	QString ret;

	if (m_next->role() == Role::Code) {
		auto *               code = dynamic_cast<code::Code *>(m_next);
		memory::CodeFragment frag = code->source();

		ret = frag.source->mid(frag.begin, frag.end - frag.begin);
	}
	else if (
	  m_next->role() == Role::Object &&
	  dynamic_cast<value::Value *>(m_next)->type() == memory::Type::String) {
		ret = dynamic_cast<value::Value *>(m_next)->getValue().toString();
	}

	return ret;
}

bool Value::checkPrev(const Context * context) const {
	return context == nullptr || context->role() == Role::Assign ||
	       (context->role() != Role::Exists && context->isResultative());
}

Context * Value::getBeginContext() {
	return this;
}

Context * Value::getEndContext() {
	return m_next;
}

bool Value::isResultative() const {
	return true;
}

}  // namespace icL::context::data::js
