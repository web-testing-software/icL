#include "function.h"

#include "parameter.h"

#include <context-base/object/object.h>
#include <context-control/main/code.h>



namespace vm::context::function {

Function::Function(memory::Memory* mem, const QString& name)
	: mem(mem)
	, name(name) {
	m_role      = Role::Function;
	newFunction = mem->functions().contains(name);
}

bool Function::exNewFunction() {
	memory::Function func;
	// checkPrev(Context*) and canBeTheLast ensure that the last block is code
	// one
	auto*    codeBlock = dynamic_cast<code::Code*>(getLast());
	Context* it        = m_next->next();

	while (it != nullptr && it->role() == Role::Argument) {
		memory::Parameter parameter;
		auto*             dataParameter = dynamic_cast<data::Parameter*>(it);

		parameter.name = dataParameter->name();
		parameter.type = dataParameter->type();

		func.paramList.append(parameter);
	}

	func.source = codeBlock->source();

	mem->functions().registerFunction(name, func);

	return true;
}

bool Function::exCallFunction() {
	if (functionExecuted) {
		return true;
	}

	if (newFunction) {
		emit exception(
		  {-404, QStringLiteral("Function %1 not found").arg(name)});
		return false;
	}

	memory::Function& func = mem->functions().getFunction(name);

	if (!checkParamsNum(func) || !checkParamsTypes(func)) {
		return false;
	}

	auto     fcall   = memory::FunctionCall{};
	auto     argIt   = func.paramList.begin();
	Context* it      = m_next;
	int      argsNum = func.paramList.size();

	fcall.args.reserve(argsNum);

	for (int i = 0; i < argsNum; i++, argIt++, it = it->next()) {
		memory::Argument arg;

		arg.name   = (*argIt).name;
		arg.object = dynamic_cast<object::Object*>(it);

		fcall.args.append(arg);
	}

	emit interrupt(fcall, [this](memory::Return& ret) {
		if (ret.exception.code != 0) {
			emit exception(ret.exception);
		}
		else {
			this->newContext = fromValue(ret.returnValue);
		}
	});

	functionExecuted = true;

	return false;
}

bool Function::checkParamsNum(memory::Function& func) {
	int      paramsNum = func.paramList.size();
	int      i         = 0;
	Context* it        = m_next;

	while (it != nullptr && it->role() == Role::Object && i < paramsNum) {
		++i;
		it = it->next();
	}

	if (i != paramsNum || (it != nullptr && it->role() == Role::Object)) {
		sendWrongArgs();
		return false;
	}

	return true;
}

bool Function::checkParamsTypes(memory::Function& func) {
	auto     paramIt  = func.paramList.begin();
	int      paramNum = func.paramList.size();
	Context* argIt    = m_next;
	bool     ok       = true;

	for (int i = 0; i < paramNum; i++) {
		auto* argObj = dynamic_cast<object::Object*>(argIt);
		if ((*paramIt).type != argObj->type()) {
			ok = false;
		}

		++paramIt;
		argIt = argIt->next();
	}

	if (!ok) {
		sendWrongArgs();
		return false;
	}

	return true;
}

void Function::sendWrongArgs() {
	QStringList getted;
	QStringList expected;

	Context* it = m_next;

	while (it != nullptr && it->role() == Role::Object) {
		auto* obj = dynamic_cast<object::Object*>(it);
		getted.append(memory::typeToString(obj->type()));
	}

	for (auto& arg : mem->functions().getFunction(name).paramList) {
		expected.append(memory::typeToString(arg.type));
	}

	emit exception(
	  {-203, QStringLiteral(
			   "Wrong arguments for function %1: getted<%2>, expected<%3>")
			   .arg(name)
			   .arg(getted.join(", "))
			   .arg(expected.join(", "))});
}



bool Function::checkPrev(const Context* context) const {
	return context == nullptr ||
		   (!newFunction &&
			(context->role() == Role::Alternative ||
			 context->role() == Role::Assign || context->isResultative()));
}

bool Function::canBeAtEnd() const {
	return !newFunction;
}

bool Function::isExecuable() const {
	return true;
}

bool Function::execute() {
	return m_next->role() == Role::Assign ? exNewFunction() : exCallFunction();
}

Context* Function::getBeginContext() {
	return this;
}

Context* Function::getEndContext() {
	if (newFunction) {
		return getLast();
	}

	Context* it = m_next;

	if (it == nullptr || it->role() != Role::Object) {
		return this;
	}

	while (it->next() != nullptr && it->role() == Role::Object) {
		it = it->next();
	}

	return it;
}

bool Function::isResultative() const {
	return !newFunction;
}

}  // namespace vm::context::function