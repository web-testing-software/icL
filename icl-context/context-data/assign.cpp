#include "assign.h"

#include <object/object.h>

namespace vm::context::data {

Assign::Assign() {
	m_role = Role::Assign;
};



bool Assign::checkPrev(const Context* context) const {
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

	auto left  = dynamic_cast<object::Object*>(m_prev);
	auto right = dynamic_cast<object::Object*>(m_next);

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
	return true;
}

Context* Assign::getBeginContext() {
	return this;
}

Context* Assign::getEndContext() {
	return m_next;
}

}  // namespace vm::context::data
