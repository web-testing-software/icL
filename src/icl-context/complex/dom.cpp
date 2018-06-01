#include "dom.h"

#include <icl-context/base/object/element.h>
#include <icl-context/base/object/object.h>
#include <icl-memory/structures/webelement.h>

#include <QStringBuilder>
#include <QVariant>

namespace icL::context::complex {

Dom::Dom(memory::InterLevel * il)
	: Complex(il) {}

memory::WebElement Dom::query(const QString & selector) {
	QString            newId = object::Element::getNewId();
	memory::WebElement web;

	web.count = il->server
				  ->runJS(
					newId % R"( = nm(")" % selector %
					R"(", false); )" % newId % ".length")
				  .toInt();
	web.selector = selector;
	web.variable = newId;

	newValue = QVariant::fromValue(web);

	return newValue.value<memory::WebElement>();
}

memory::WebElement Dom::queryAll(const QStringList & selectors) {
	QString newId     = object::Element::getNewId();
	QString selector  = selectors.join(R"(").add(")");
	QString selector2 = selectors.join(" (+) ");

	memory::WebElement web;

	web.count =
	  il->server
		->runJS(
		  newId % R"( = nm(")" % selector % R"(", true); )" % newId % ".length")
		.toInt();
	web.selector = selector2;
	web.variable = newId;

	newValue = QVariant::fromValue(web);

	return newValue.value<memory::WebElement>();
}

void Dom::runQuery(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {

		query(args[0].object->getValue().toString());
		newContext = new object::Element{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

void Dom::runQueryAll(memory::ArgList & args) {
	bool ok = true;

	if (args.length() > 0) {
		for (auto arg : args) {
			if (arg.object->type() != memory::Type::String) {
				ok = false;
			}
		}
	}
	else {
		ok = false;
	}

	if (ok) {
		QStringList selectors;

		for (auto arg : args) {
			selectors << arg.object->getValue().toString();
		}

		queryAll(selectors);
		newContext = new object::Element{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String ...>"));
	}
}

bool Dom::checkPrev(const Context * context) const {
	return context == nullptr || context->role() == Role::Assign ||
		   (context->role() != Role::Exists && context->isResultative());
}

bool Dom::canBeAtEnd() const {
	return false;
}

Context * Dom::runMethod(const QString & name, memory::ArgList & args) {
	if (name == QStringLiteral("query")) {
		runQuery(args);
	}
	else if (name == QStringLiteral("queryAll")) {
		runQueryAll(args);
	}
	else {
		Context::runMethod(name, args);
	}

	return newContext;
}

}  // namespace icL::context::complex
