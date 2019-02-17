#include "assign.h"

#include <icl-context/base/object/bool.h>
#include <icl-context/base/object/double.h>
#include <icl-context/base/object/element.h>
#include <icl-context/base/object/int.h>
#include <icl-context/base/object/list.h>
#include <icl-context/base/object/string.h>
#include <icl-context/base/object/value.h>


namespace icL::context::data {

Assign::Assign(memory::InterLevel * il)
    : Data(il) {
	m_role = Role::Assign;
};



bool Assign::checkPrev(const Context * context) const {
	return context != nullptr &&
	       (context->role() == Role::Object ||
	        context->role() == Role::Function) &&
	       (context->prev() == nullptr ||
	        context->prev()->role() == Role::Assign);
}

bool Assign::isExecutable() const {
	return m_prev->role() == Role::Object;
}

memory::StepType::Value Assign::execute() {
	if (m_next->role() != Role::Object) {
		il->vm->exception(
		  {-204, "The right operand of assign operation must be an `Object`"});
		return memory::StepType::None;
	}

	auto left  = dynamic_cast<value::Value *>(m_prev);
	auto right = dynamic_cast<value::Value *>(m_next);

	if (left->isReadOnly()) {
		il->vm->exception(
		  {-205, "The left operand of assign operation must be muttable"});
		return memory::StepType::None;
	}

	if (right->type() == memory::Type::Void) {
		if (left->type() == memory::Type::Void) {
			if (right->isLValue()) {
				il->vm->exception(
				  {-404,
				   QString("Variable %1 not found").arg(right->getVarName())});
			}
			else {
				il->vm->exception(
				  {-400, "Variables of type Void cannot be created"});
			}
		}
		else {
			il->vm->exception(
			  {-206, QString("Void cannot be assigned to variable of type %1")
			           .arg(memory::typeToString(left->type()))});
		}
		return memory::StepType::None;
	}

	if (left->type() != memory::Type::Void && left->type() != right->type()) {
		il->vm->exception({-200, "Automatic casting is missing in icL"});
		return memory::StepType::None;
	}

	left->setValue(right->getValue());

	if (left->type() == memory::Type::Void) {
		Context * new_left = nullptr;

		switch (right->type()) {
		case memory::Type::Bool:
			new_left = new object::Bool{il, left};
			break;

		case memory::Type::Int:
			new_left = new object::Int{il, left};
			break;

		case memory::Type::Double:
			new_left = new object::Double{il, left};
			break;

		case memory::Type::String:
			new_left = new object::String{il, left};
			break;

		case memory::Type::List:
			new_left = new object::List{il, left};
			break;

		case memory::Type::Element:
			new_left = new object::Element{il, left};
			break;

		default:
			// Elude clang warning, never triggered
			break;
		}

		left->replaceWith(new_left);

		delete left;
	}

	return memory::StepType::MiniStep;
}

Context * Assign::getBeginContext() {
	return this;
}

Context * Assign::getEndContext() {
	return m_next;
}

}  // namespace icL::context::data
