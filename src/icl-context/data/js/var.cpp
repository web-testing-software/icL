#include "var.h"

#include <icl-context/base/object/boolean.h>
#include <icl-context/base/object/double.h>
#include <icl-context/base/object/int.h>
#include <icl-context/base/object/list.h>
#include <icl-context/base/object/object.h>
#include <icl-context/base/object/string.h>
#include <icl-context/base/object/void.h>

namespace icL::context::data::js {

Var::Var(memory::InterLevel * il)
	: Value(il) {}


std::pair<QString, QString> Var::getArguments() {
	QString a1, a2;

	if (
	  m_next->role() == Role::Object &&
	  dynamic_cast<object::Object *>(m_next)->type() == memory::Type::String) {
		Context * next2 = m_next->next();

		a1 = dynamic_cast<object::Object *>(m_next)->getValue().toString();

		if (next2 != nullptr && next2->role() == Role::Object) {
			Context * next3 = next2->next();

			if (
			  dynamic_cast<object::Object *>(next2)->type() ==
				memory::Type::String &&
			  (next3 == nullptr || next3->role() != Role::Object)) {
				a2 =
				  dynamic_cast<object::Object *>(next2)->getValue().toString();
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
		return memory::StepType::NONE;
	}

	QVariant value = il->server->runJS(getter);

	auto type = memory::variantTypeToType(value.type());

	switch (type) {
	case memory::Type::Boolean:
		newContext = new object::Boolean{il, getter, setter};
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

	return memory::StepType::MINI_STEP;
}

}  // namespace icL::context::data::js
