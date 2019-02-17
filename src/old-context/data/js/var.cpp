#include "var.h"

#include <icl-context/base/object/bool.h>
#include <icl-context/base/object/double.h>
#include <icl-context/base/object/int.h>
#include <icl-context/base/object/list.h>
#include <icl-context/base/object/string.h>
#include <icl-context/base/object/value.h>
#include <icl-context/base/object/void.h>

namespace icL::context::data::js {

Var::Var(memory::InterLevel * il)
    : Value(il) {}


std::pair<QString, QString> Var::getArguments() {
	QString a1, a2;

	if (
	  m_next->role() == Role::Object &&
	  dynamic_cast<value::Value *>(m_next)->type() == memory::Type::String) {
		Context * next2 = m_next->next();

		a1 = dynamic_cast<value::Value *>(m_next)->getValue().toString();

		if (next2 != nullptr && next2->role() == Role::Object) {
			Context * next3 = next2->next();

			if (
			  dynamic_cast<value::Value *>(next2)->type() ==
			    memory::Type::String &&
			  (next3 == nullptr || next3->role() != Role::Object)) {
				a2 = dynamic_cast<value::Value *>(next2)->getValue().toString();
			}
			else {
				a1.clear();
			}
		}
	}

	return {a1, a2};
}

memory::StepType::Value Var::execute() {
	auto [getter, setter] = getArguments();

	if (getter.isEmpty()) {
		il->vm->exception(
		  {-203,
		   "Wrong arguments for $var, expected <String, String> or <String>"});
		return memory::StepType::None;
	}

	QVariant value = il->server->runJS(getter);

	auto type = memory::variantTypeToType(value.type());

	switch (type) {
	case memory::Type::Bool:
		newContext = new object::Bool{il, getter, setter};
		break;

	case memory::Type::Int:
		newContext = new object::Int{il, getter, setter};
		break;

	case memory::Type::Double:
		newContext = new object::Double{il, getter, setter};
		break;

	case memory::Type::String:
		newContext = new object::String{il, getter, setter};
		break;

	case memory::Type::List:
		newContext = new object::List{il, getter, setter};
		break;

	default:
		newContext = new object::Void{il, getter, setter};
	}

	return memory::StepType::MiniStep;
}

}  // namespace icL::context::data::js
