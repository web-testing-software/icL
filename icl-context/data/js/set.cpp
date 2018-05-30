#include "set.h"

#include <icl-context/base/object/void.h>

#include <QRegularExpression>

namespace icL::context::data::js {

Set::Set(memory::InterLevel * il)
	: Value(il) {}

memory::StepType::Value Set::execute() {
	QString code = getCode();

	if (code.isEmpty()) {
		il->vm->exception(
		  {-203,
		   "Wrong call of $get, the javascript code is missing or empty"});
		return memory::StepType::NONE;
	}

	QRegularExpression      regex{R"((?<type>[@#])\((?<name>\w+)\))"};
	QRegularExpressionMatch match;
	int                     last_pos = -1;

	while ((last_pos = code.lastIndexOf(regex, last_pos, &match)) > 0) {
		if (match.hasMatch()) {
			QString  name = match.captured(QStringLiteral("name"));
			QString  type = match.captured(QStringLiteral("type"));
			QVariant value;

			if (type == QStringLiteral("@")) {
				value = il->mem->stackIt().getContainer(name)->getValue(name);
			}
			else {
				value = il->mem->stateIt().state()->getValue(name);
			}

			code.replace(
			  last_pos, match.capturedLength(), varToJsString(value));
		}
	}

	QVariant ret = il->server->runJS(code);

	if (ret.isNull()) {
		newContext = new object::Void{il};
	}
	else {
		newContext = fromValue(ret);
	}

	return memory::StepType::MINI_STEP;
}

}  // namespace icL::context::data::js
