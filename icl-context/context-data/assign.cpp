#include "assign.h"

#include <object/boolean.h>
#include <object/double.h>
#include <object/element.h>
#include <object/int.h>
#include <object/list.h>
#include <object/string.h>

#include <context-base/object/object.h>


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

bool Assign::isExecuable() const {
	return m_prev->role() == Role::Object;
}

bool Assign::execute() {
	if (m_next->role() != Role::Object) {
		emit exception(
		  {-204, "The right operand of assign operation must be an `Object`"});
		return false;
	}

	auto left  = dynamic_cast<object::Object *>(m_prev);
	auto right = dynamic_cast<object::Object *>(m_next);

	if (left->isReadOnly()) {
		emit exception(
		  {-205, "The left operand of assign operation must be muttable"});
		return false;
	}

	if (right->type() == memory::Type::Void) {
		if (left->type() == memory::Type::Void) {
			if (right->isLValue()) {
				emit exception(
				  {-404,
				   QString("Variable %1 not found").arg(right->getVarName())});
			}
			else {
				emit exception(
				  {-400, "Variables of type Void cannot be created"});
			}
		}
		else {
			emit exception(
			  {-206, QString("Void cannot be assigned to variable of type %1")
					   .arg(memory::typeToString(left->type()))});
		}
		return false;
	}

	if (left->type() != memory::Type::Void && left->type() != right->type()) {
		emit exception({-200, "Automatic casting is missing in icL"});
		return false;
	}

	left->setValue(right->getValue());

	if (left->type() == memory::Type::Void) {
		Context * new_left = nullptr;

		switch (right->type()) {
		case memory::Type::Boolean:
			new_left = new object::Boolean{left};
			break;

		case memory::Type::Int:
			new_left = new object::Int{left};
			break;

		case memory::Type::Double:
			new_left = new object::Double{left};
			break;

		case memory::Type::String:
			new_left = new object::String{left};
			break;

		case memory::Type::List:
			new_left = new object::List{left};
			break;

		case memory::Type::Element:
			new_left = new object::Element{left};
			break;

		default:
			// Elude clang warning, never triggered
			break;
		}

		left->replaceWith(new_left);

		delete left;
	}

	return true;
}

Context * Assign::getBeginContext() {
	return this;
}

Context * Assign::getEndContext() {
	return m_next;
}

}  // namespace icL::context::data
