#include "element.h"

#include "int.h"
#include "string.h"

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

Object * Element::html() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new String{web.variable % ".html()",
					  web.variable % ".html(%1, true)"};
}

Object * Element::text() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new String{web.variable % ".text()",
					  web.variable % ".text(%1, true)"};
}

Object * Element::width() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new Int{web.variable % ".width()",
				   web.variable % ".width(%1, true)"};
}

Object * Element::height() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new Int{web.variable % ".height()",
				   web.variable % ".height(%1, true)"};
}

bool Element::visible() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	if (!isSingle(web)) {
		return false;
	}

	emit requestJsExecution(web.variable % ".visible()", [this](const QVariant & var) {
		this->newValue = var;
	});

	return newValue.toBool();
}

bool Element::clickable() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	if (!isSingle(web)) {
		return false;
	}

	emit requestJsExecution(web.variable % ".clickable()", [this](const QVariant & var) {
		this->newValue = var;
	});

	return newValue.toBool();
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
