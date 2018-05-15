#include "element.h"

#include "boolean.h"
#include "double.h"
#include "int.h"
#include "list.h"
#include "string.h"
#include "void.h"

namespace icL::context::object {



Element::Element(memory::DataState * container, const QString & varName)
	: Object(container, varName) {}

Element::Element(const QVariant & rvalue, bool readonly)
	: Object(rvalue, readonly) {}

Element::Element(const Object * const object)
	: Object(object) {}



int Element::length() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return web.count;
}

String * Element::html() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new String{web.variable % ".html()",
					  web.variable % ".html(%1, true)"};
}

String * Element::text() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new String{web.variable % ".text()",
					  web.variable % ".text(%1, true)"};
}

Int * Element::width() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new Int{web.variable % ".width()",
				   web.variable % ".width(%1, true)"};
}

Int * Element::height() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new Int{web.variable % ".height()",
				   web.variable % ".height(%1, true)"};
}

bool Element::visible() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	if (!isSingle(web)) {
		return false;
	}

	emit requestJsExecution(
	  web.variable % ".visible()",
	  [this](const QVariant & var) { this->newValue = var; });

	return newValue.toBool();
}

bool Element::clickable() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	if (!isSingle(web)) {
		return false;
	}

	emit requestJsExecution(
	  web.variable % ".clickable()",
	  [this](const QVariant & var) { this->newValue = var; });

	return newValue.toBool();
}

Object * Element::prop(const QString & name) {
	memory::WebElement web = getValue().value<memory::WebElement>();

	QString getter = web.variable % ".prop('" % name % "')";
	QString setter = web.variable % ".prop('" % name % "', %1, true)";

	emit requestJsExecution(
	  getter, [this](const QVariant & var) { this->newValue = var; });

	switch (memory::variantTypeToType(newValue.type())) {
	case memory::Type::Boolean:
		newContext = new Boolean{getter, setter};
		break;

	case memory::Type::Int:
		newContext = new Int{getter, setter};
		break;

	case memory::Type::Double:
		newContext = new Double{getter, setter};
		break;

	case memory::Type::String:
		newContext = new String{getter, setter};
		break;

	case memory::Type::List:
		newContext = new List{getter, setter};
		break;

	default:
		newContext = new Void{getter, setter};
		break;
	}

	return dynamic_cast<Object *>(newContext);
}

String * Element::attr(const QString & name) {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new String{web.variable % ".attr('" % name % "')",
					  web.variable % ".attr('" % name % "', %1, true)"};
}

String * Element::data(const QString & name) {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new String{web.variable % ".data('" % name % "')",
					  web.variable % ".data('" % name % "', %1, true)"};
}

String * Element::css(const QString & name) {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new String{web.variable % ".css('" % name % "')",
					  web.variable % ".css('" % name % "', %1, true)"};
}



void Element::runLength() {
	newValue   = length();
	newContext = new Int{newValue, true};
}

void Element::runHTML() {
	newContext = html();
}

void Element::runText() {
	newContext = text();
}

void Element::runWidth() {
	newContext = width();
}

void Element::runHeight() {
	newContext = height();
}

void Element::runVisible() {
	newContext = new Boolean{newValue, true};
}

void Element::runClickable() {
	newContext = new Boolean{newValue, true};
}

void Element::runProp(const QString & name) {
	prop(name);
}

void Element::runAttr(const QString & name) {
	newContext = attr(name);
}

void Element::runData(const QString & name) {
	newContext = data(name);
}

void Element::runCSS(const QString & name) {
	newContext = css(name);
}



bool Element::isSingle(memory::WebElement & web) {
	if (web.count != 1) {
		if (web.count == 0) {
			emit exception(
			  {-5, QStringLiteral("Element collection `%1` is null")
					 .arg(web.selector)});
		}
		else {
			emit exception(
			  {-4,
			   QStringLiteral("Element collection `%1` contains several items")
				 .arg(web.selector)});
		}
		return false;
	}

	return true;
}



Context * Element::runProperty(Prefix prefix, const QString & name) {
	if (prefix == Prefix::None) {
		if (name[0].isLower()) {
			runProp(name);
		}
		else if (name == "HTML") {
			runHTML();
		}
		else if (name == "Text") {
			runText();
		}
		else if (name == "Width") {
			runWidth();
		}
		else if (name == "Height") {
			runHeight();
		}
		else if (name == "Visible") {
			runVisible();
		}
		else if (name == "Clickable") {
			runClickable();
		}
		else {
			Object::runProperty(prefix, name);
		}
	}
	else if (prefix == Prefix::Attr) {
		runAttr(name);
	}
	else if (prefix == Prefix::Data) {
		runData(name);
	}
	else /* prefix == Prefix.CSS */ {
		runCSS(name);
	}

	return newContext;
}



memory::Type Element::type() const {
	return memory::Type::Element;
}


bool Element::toBoolean() {
	return false;
}

int Element::toInt() {
	return 0;
}

double Element::toDouble() {
	return 0.0;
}

const QString Element::toString() {
	return QString{};
}

const QStringList Element::toList() {
	return QStringList{};
}

}  // namespace icL::context::object
