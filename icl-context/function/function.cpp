#include "function.h"

#include <code/main/code.h>

#include <data/argument.h>

#include <object/object.h>

namespace vm::context::function {

Function::Function (memory::Memory *mem, const QString &name)
	: mem (mem)
	, name (name) {
	m_role		= Role::Function;
	newFunction = mem->functions ().contains (name);
}

bool Function::exNewFunction () {
	memory::Function	func;
	// checkPrev(Context*) and canBeTheLast ensure that the last block is code one
	auto				*codeBlock	= dynamic_cast <code::Code *> ( getLast () );
	Context				*it			= m_next->next ();

	while (it != nullptr && it->role () == Role::Argument) {
		memory::Argument	argument;
		auto				*dataArgument = dynamic_cast <data::Argument *> ( it );

		argument.name	= dataArgument->name ();
		argument.type	= dataArgument->type ();

		func.argList.append (argument);
	}

	func.source = codeBlock->source ();

	mem->functions ().registerFunction (name, func);

	return true;
}

bool Function::exCallFunction () {
	if (functionExecuted) {
		return true;
	}

	if (newFunction) {
		emit exception ({ -404, QStringLiteral ("Function %1 not found").arg (name) });
		return false;
	}

	memory::Function &func = mem->functions ().getFunction (name);

	if (!checkParamsNum (func) || !checkParamsTypes (func) ) {
		return false;
	}

	auto	fcall	= memory::FunctionCall{};
	auto	argIt	= func.argList.begin ();
	Context *it		= m_next;
	int		argsNum = func.argList.size ();

	fcall.params.reserve (argsNum);

	for (int i = 0; i < argsNum; i++, argIt++, it = it->next () ) {
		memory::Parameter param;

		param.name		= ( *argIt ).name;
		param.object	= it;

		fcall.params.append (param);
	}

	emit interrupt (fcall,
					[this] (memory::Return &ret) {
					if (ret.exception.code != 0) {
						emit exception (ret.exception);
					}
					else {
						this->newContext = fromValue (ret.returnValue);
					}
			});

	functionExecuted = true;

	return false;
}

bool Function::checkParamsNum (memory::Function &func) {
	int		argsNum = func.argList.size ();
	int		i		= 0;
	Context *it		= m_next;

	while (it != nullptr && it->role () == Role::Object && i < argsNum) {
		++i;
		it = it->next ();
	}

	if (i != argsNum || ( it != nullptr && it->role () == Role::Object ) ) {
		sendWrongArgs ();
		return false;
	}

	return true;
}

bool Function::checkParamsTypes (memory::Function &func) {
	auto	argIt		= func.argList.begin ();
	int		argsNum		= func.argList.size ();
	Context *paramIt	= m_next;
	bool	ok			= true;

	for (int i = 0; i < argsNum; i++) {
		auto *paramObj = dynamic_cast <object::Object *> ( paramIt );
		if ( ( *argIt ).type != paramObj->type () ) {
			ok = false;
		}

		++argIt;
		paramIt = paramIt->next ();
	}

	if (!ok) {
		sendWrongArgs ();
		return false;
	}

	return true;
}

void Function::sendWrongArgs () {
	QStringList getted;
	QStringList expected;

	Context		*it = m_next;

	while (it != nullptr && it->role () == Role::Object) {
		auto *obj = dynamic_cast <object::Object *> ( it );
		getted.append (memory::typeToString (obj->type () ) );
	}

	for (auto &arg : mem->functions ().getFunction (name).argList) {
		expected.append (memory::typeToString (arg.type) );
	}

	emit exception ({ -203,
					  QStringLiteral ("Wrong arguments for function %1: getted<%2>, expected<%3>")
					  .arg (name).arg (getted.join (", ") ).arg (expected.join (", ") ) });
}



bool Function::checkPrev (const Context *context) const {
	return
		context == nullptr ||
		(
		!newFunction &&
		(
			context->role () == Role::Alternative ||
			context->role () == Role::Assign      ||
			context->isResultative ()
		)
		);
}

bool Function::canBeAtEnd () const {
	return !newFunction;
}

bool Function::isExecuable () const {
	return true;
}

bool Function::execute () {
	return m_next->role () == Role::Assign ? exNewFunction () : exCallFunction ();
}

Context * Function::getBeginContext () {
	return this;
}

Context * Function::getEndContext () {
	if (newFunction) {
		return getLast ();
	}

	Context *it = m_next;

	if (it == nullptr || it->role () != Role::Object) {
		return this;
	}

	while (it->next () != nullptr && it->role () == Role::Object) {
		it = it->next ();
	}

	return it;
}

bool Function::isResultative () const {
	return !newFunction;
}

} // namespace
