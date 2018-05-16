#include "element.h"

#include "boolean.h"
#include "double.h"
#include "int.h"
#include "list.h"
#include "string.h"
#include "void.h"

namespace icL::context::object {



Element::Element(
  memory::InterLevel * il, memory::DataState * container,
  const QString & varName)
	: Object(il, container, varName) {}

Element::Element(
  memory::InterLevel * il, const QVariant & rvalue, bool readonly)
	: Object(il, rvalue, readonly) {}

Element::Element(memory::InterLevel * il, const Object * const object)
	: Object(il, object) {}

const QHash<QString, void (Element::*)()> properties =
  Element::initProperties();
const QHash<QString, void (Element::*)(memory::ArgList &)> methods =
  Element::initMethods();

const QHash<QString, void (Element::*)()> Element::initProperties() {
	return {{{"Length", &Element::runLength},
			 {"HTML", &Element::runHTML},
			 {"Text", &Element::runText},
			 {"Width", &Element::runWidth},
			 {"Height", &Element::runHeight},
			 {"Visible", &Element::runVisible},
			 {"Clickable", &Element::runClickable}}};
}

const QHash<QString, void (Element::*)(memory::ArgList &)>
Element::initMethods() {
	return {{{"ScrollTo", &Element::runScrollTo},
			 {"Click", &Element::runClick},
			 {"SendKeys", &Element::runSendKeys},
			 {"CtrlV", &Element::runCtrlV},
			 {"IsValid", &Element::runIsValid},
			 {"Add", &Element::runAdd},
			 {"Copy", &Element::runCopy},
			 {"Filter", &Element::runFilter},
			 {"Get", &Element::runGet},
			 {"Next", &Element::runNext},
			 {"Prev", &Element::runPrev},
			 {"Parent", &Element::runParent},
			 {"Child", &Element::runChild},
			 {"Closest", &Element::runClosest},
			 {"AddClass", &Element::runAddClass},
			 {"RemoveClass", &Element::runRemoveClass},
			 {"HasClass", &Element::runHasClass}}};
}



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

void Element::ctrlV(const QString & text) {
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
	memory::WebElement web     = getValue().value<memory::WebElement>();
	QString            escaped = className;

	escaped.replace("'", "\\'");
	emit requestJsExecution(
	  web.variable % ".add_class('" % escaped % "')", nullptr);
}

void Element::removeClass(const QString & className) {
	memory::WebElement web     = getValue().value<memory::WebElement>();
	QString            escaped = className;

	escaped.replace("'", "\\'");
	emit requestJsExecution(
	  web.variable % ".remove_class('" % escaped % "')", nullptr);
}

bool Element::hasClass(const QString & className) {
	memory::WebElement web     = getValue().value<memory::WebElement>();
	QString            escaped = className;

	if (!isSingle(web)) {
		return false;
	}

	escaped.replace("'", "\\'");
	emit requestJsExecution(
	  web.variable % ".has_class('" % escaped % "')",
	  [this](const QVariant & var) { this->newValue = var; });

	return newValue.toBool();
}

void Element::runScrollTo(memory::ArgList & args) {
	if (args.length() == 0) {
		scrollTo();
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Element::runClick(memory::ArgList & args) {
	if (args.length() == 0) {
		click();
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Element::runSendKeys(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		sendKeys(args[0].object->getValue().toString());
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

void Element::runCtrlV(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		ctrlV(args[0].object->getValue().toString());
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

void Element::runIsValid(memory::ArgList & args) {
	newValue   = isValid();
	newContext = new Boolean{newValue, true};
}

void Element::runAdd(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::Element) {
		add(args[0].object->getValue().value<memory::WebElement>());
	}
	else {
		sendWrongArglist(args, QStringLiteral("<Element>"));
	}
}

void Element::runCopy(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = QVariant::fromValue(copy());
		newContext = new Element{newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Element::runFilter(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		newValue =
		  QVariant::fromValue(filter(args[0].object->getValue().toString()));
		newContext = new Element{newValue, true};
	}
	if (
	  args.length() == 2 && args[0].object->type() == memory::Type::String &&
	  args[1].object->type() == memory::Type::Boolean) {
		newValue   = QVariant::fromValue(filter(
		  args[0].object->getValue().toString(),
		  args[1].object->getValue().toInt()));
		newContext = new Element{newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String> or <String, Boolean>"));
	}
}

void Element::runGet(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		newValue = QVariant::fromValue(get(args[0].object->getValue().toInt()));
		newContext = new Element{newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

void Element::runNext(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = QVariant::fromValue(next());
		newContext = new Element{newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Element::runPrev(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = QVariant::fromValue(prev());
		newContext = new Element{newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Element::runParent(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = QVariant::fromValue(parent());
		newContext = new Element{newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Element::runChild(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::Int) {
		newValue =
		  QVariant::fromValue(child(args[0].object->getValue().toInt()));
		newContext = new Element{newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<Int>"));
	}
}

void Element::runClosest(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		newValue =
		  QVariant::fromValue(closest(args[0].object->getValue().toString()));
		newContext = new Element{newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

void Element::runAddClass(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		addClass(args[0].object->getValue().toString());
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

void Element::runRemoveClass(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		addClass(args[0].object->getValue().toString());
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

void Element::runHasClass(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		newValue   = hasClass(args[0].object->getValue().toString());
		newContext = new Boolean{newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
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
		auto it = properties.find(name);

		if (it != properties.end()) {
			(this->*it.value())();
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
	else { /* prefix == Prefix.CSS */
		runCSS(name);
	}

	return newContext;
}

Context * Element::runMethod(const QString & name, memory::ArgList & args) {

	auto it = methods.find(name);

	if (it != methods.end()) {
		(this->*it.value())(args);
	}
	else {
		Object::runMethod(name, args);
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
