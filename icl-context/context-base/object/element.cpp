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



int Element::idAsInt = 0;

QString Element::getNewId() {
	if (idAsInt >= 10000) {
		idAsInt = 0;
	}

	return "windows.icL.links[" % QString::number(idAsInt++) % "]";
}



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



void Element::scrollTo() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	if (!isSingle(web)) {
		return;
	}

	emit requestJsExecution(web.variable % ".scrollTo()", nullptr);
}

void Element::click() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	if (!isSingle(web)) {
		return;
	}

	emit requestJsExecution(
	  web.variable % ".clickNow()", [this](const QVariant & var) {
		  // {x: 0, y: 0}
		  auto map = var.toMap();
		  int  x   = map["x"].toInt();
		  int  y   = map["y"].toInt();

		  emit this->requestClick(x, y);
	  });
}

void Element::sendKeys(const QString & keys) {
	memory::WebElement web = getValue().value<memory::WebElement>();

	if (!isSingle(web)) {
		return;
	}

	click();

	emit requestJsExecution(web.variable % ".moveCursorToEnd()", nullptr);
	emit requestKeys(keys);
}

void Element::CtrlV(const QString & text) {
	memory::WebElement web     = getValue().value<memory::WebElement>();
	QString            escaped = text;

	if (!isSingle(web)) {
		return;
	}

	escaped.replace("'", "\\'");

	emit requestJsExecution(
	  web.variable % "[0].value += '" % escaped % "'", nullptr);
}

bool Element::isValid() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return web.count > 0;
}

void Element::add(memory::WebElement element) {
	memory::WebElement web = getValue().value<memory::WebElement>();

	emit requestJsExecution(
	  web.variable % ".add(" % element.variable % ")", nullptr);
}

memory::WebElement Element::copy() {
	memory::WebElement web = getValue().value<memory::WebElement>();
	memory::WebElement ret;

	ret.variable = getNewId();
	ret.selector = web.selector;
	ret.count    = web.count;

	emit requestJsExecution(
	  ret.variable % " = " % web.variable % ".copy()", nullptr);

	return ret;
}

memory::WebElement Element::filter(const QString & selector) {
	memory::WebElement web = getValue().value<memory::WebElement>();
	memory::WebElement ret;
	QString            escaped = selector;

	escaped.replace("'", "\\'");
	ret.variable = getNewId();
	ret.selector = web.selector;
	ret.count    = web.count;

	emit requestJsExecution(
	  ret.variable % " = " % web.variable % ".filter('" % escaped % "')",
	  nullptr);

	return ret;
}

memory::WebElement Element::filter(const QString & context, bool asfragment) {
	memory::WebElement web = getValue().value<memory::WebElement>();
	memory::WebElement ret;
	QString            escaped = context;

	escaped.replace("'", "\\'");
	ret.variable = getNewId();
	ret.selector = web.selector;
	ret.count    = web.count;

	emit requestJsExecution(
	  ret.variable % " = " % web.variable % ".filterByContent('" % escaped %
		"', " % (asfragment ? "true" : "false") % ")",
	  nullptr);

	return ret;
}

memory::WebElement Element::get(int index) {
	memory::WebElement web = getValue().value<memory::WebElement>();
	memory::WebElement ret;
	QString            indexStr = QString::number(index);

	if (index < 0 || index >= web.count) {
		emit exception({-8, "Index " % indexStr % " is out of bounds [0.." %
							  QString::number(web.count) % ")"});
		return ret;
	}

	ret.variable = getNewId();
	ret.selector = web.selector % "[" % indexStr % "]";
	ret.count    = 1;

	emit requestJsExecution(
	  ret.variable % " = nm(" % web.variable % "[" % indexStr % "])", nullptr);

	return ret;
}

memory::WebElement Element::next() {
	return domTrans(QStringLiteral("next"), QString());
}

memory::WebElement Element::prev() {
	return domTrans(QStringLiteral("prev"), QString());
}

memory::WebElement Element::parent() {
	return domTrans(QStringLiteral("parent"), QString());
}

memory::WebElement Element::child(int index) {
	return domTrans(QStringLiteral("child"), QString::number(index));
}

memory::WebElement Element::closest(const QString & selector) {
	return domTrans(QStringLiteral("closest"), selector);
}

void Element::addClass(const QString & className) {
	memory::WebElement web = getValue().value<memory::WebElement>();
	QString            escaped = className;

	escaped.replace("'", "\\'");
	emit requestJsExecution(
	  web.variable % ".add_class('" % escaped % "')",
	  nullptr);
}

void Element::removeClass(const QString & className) {
	memory::WebElement web = getValue().value<memory::WebElement>();
	QString            escaped = className;

	escaped.replace("'", "\\'");
	emit requestJsExecution(
	  web.variable % ".remove_class('" % escaped % "')",
	  nullptr);
}

bool Element::hasClass(const QString & className) {
	memory::WebElement web = getValue().value<memory::WebElement>();
	QString            escaped = className;

	if (!isSingle(web)) {
		return false;
	}

	escaped.replace("'", "\\'");
	emit requestJsExecution(
	  web.variable % ".has_class('" % escaped % "')",
				[this](const QVariant&var){
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

memory::WebElement Element::domTrans(
  const QString & method, const QString & arg) {

	memory::WebElement web = getValue().value<memory::WebElement>();
	memory::WebElement ret;

	ret.variable = getNewId();
	ret.selector = web.selector % " -> " % method % "(" % arg % ")";

	emit requestJsExecution(
	  "(" % ret.variable % " = " % web.variable % "." % method % "(" % arg %
		")).length",
	  [&ret](const QVariant & res) { ret.count = res.toInt(); });

	return ret;
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
