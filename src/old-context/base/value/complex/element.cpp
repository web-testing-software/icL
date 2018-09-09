#include "element.h"

#include "../base/bool.h"
#include "../base/double.h"
#include "../base/int.h"
#include "../base/list.h"
#include "../base/string.h"
#include "../base/void.h"

#include <QDebug>
#include <QPoint>
#include <QStringBuilder>

namespace icL::context::value {



Element::Element(
  memory::InterLevel * il, memory::DataState * container,
  const QString & varName)
	: Value(il, container, varName) {}

Element::Element(
  memory::InterLevel * il, const QVariant & rvalue, bool readonly)
	: Value(il, rvalue, readonly) {}

Element::Element(memory::InterLevel * il, const Value * const object)
	: Value(il, object) {}

const QHash<QString, void (Element::*)()> Element::properties =
  Element::initProperties();
const QHash<QString, void (Element::*)(memory::ArgList &)> Element::methods =
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
			 {"Query", &Element::runQuery},
			 {"QueryAll", &Element::runQueryAll},
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

	return "window.icL.links[" % QString::number(idAsInt++) % "]";
}



int Element::length() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return web.count;
}

String * Element::html() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new String{il, web.variable % ".html()",
					  web.variable % ".html(%1, true)"};
}

String * Element::text() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new String{il, web.variable % ".text()",
					  web.variable % ".text(%1, true)"};
}

Int * Element::width() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new Int{il, web.variable % ".width()",
				   web.variable % ".width(%1, true)"};
}

Int * Element::height() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new Int{il, web.variable % ".height()",
				   web.variable % ".height(%1, true)"};
}

bool Element::visible() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	if (!isSingle(web)) {
		return false;
	}

	newValue = il->server->runJS(web.variable % ".visible()");

	return newValue.toBool();
}

bool Element::clickable() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	if (!isSingle(web)) {
		return false;
	}

	newValue = il->server->runJS(web.variable % ".clickable()");

	return newValue.toBool();
}

Value * Element::prop(const QString & name) {
	memory::WebElement web = getValue().value<memory::WebElement>();

	QString getter = web.variable % ".prop('" % name % "')";
	QString ser    = web.variable % ".prop('" % name % "', %1, true)";

	newValue = il->server->runJS(getter);

	switch (memory::variantTypeToType(newValue.type())) {
	case memory::Type::Bool:
		newContext = new Bool{il, getter, setter};
		break;

	case memory::Type::Int:
		newContext = new Int{il, getter, setter};
		break;

	case memory::Type::Double:
		newContext = new Double{il, getter, setter};
		break;

	case memory::Type::String:
		newContext = new String{il, getter, setter};
		break;

	case memory::Type::List:
		newContext = new List{il, getter, setter};
		break;

	default:
		newContext = new Void{il, getter, setter};
		break;
	}

	return dynamic_cast<Value *>(newContext);
}

String * Element::attr(const QString & name) {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new String{il, web.variable % ".attr('" % name % "')",
					  web.variable % ".attr('" % name % "', %1, true)"};
}

String * Element::data(const QString & name) {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new String{il, web.variable % ".data('" % name % "')",
					  web.variable % ".data('" % name % "', %1, true)"};
}

String * Element::css(const QString & name) {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return new String{il, web.variable % ".css('" % name % "')",
					  web.variable % ".css('" % name % "', %1, true)"};
}



void Element::runLength() {
	newValue   = length();
	newContext = new Int{il, newValue, true};
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
	newContext = new Bool{il, newValue, true};
}

void Element::runClickable() {
	newContext = new Bool{il, newValue, true};
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

	il->server->runJS(web.variable % ".scrollTo()");
}

void Element::click() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	if (!isSingle(web)) {
		return;
	}

	QVariant result;
	QPoint   point;

	result       = il->server->runJS(web.variable % ".clickNow()");

	if (result.isValid()) {
		point = result.toPoint();
	}

	int x = point.x();
	int y = point.y();

	if (!il->server->click(x, y)) {
		il->vm->exception(
		  {-9, "Point (" % QString::number(x) % ", " % QString::number(y) %
				 ") is out of screen bounds"});
	}
}

void Element::sendKeys(const QString & keys) {
	memory::WebElement web = getValue().value<memory::WebElement>();

	if (!isSingle(web)) {
		return;
	}

	click();

	il->server->runJS(web.variable % ".moveCursorToEnd()");
	il->server->keys(keys);
}

void Element::ctrlV(const QString & text) {
	memory::WebElement web     = getValue().value<memory::WebElement>();
	QString            escaped = text;

	if (!isSingle(web)) {
		return;
	}

	escaped.replace("'", "\\'");

	il->server->runJS(web.variable % "[0].value += '" % escaped % "'");
}

bool Element::isValid() {
	memory::WebElement web = getValue().value<memory::WebElement>();

	return web.count > 0;
}

void Element::add(memory::WebElement element) {
	memory::WebElement web = getValue().value<memory::WebElement>();

	web.count = il->server
				  ->runJS(
					web.variable % ".add(" % element.variable % "); " %
					web.variable % ".length")
				  .toInt();

	web.selector = web.selector % " (+) " % element.selector;

	setValue(QVariant::fromValue(web));
}

memory::WebElement Element::copy() {
	memory::WebElement web = getValue().value<memory::WebElement>();
	memory::WebElement ret;

	ret.variable = getNewId();
	ret.selector = web.selector;
	ret.count    = web.count;

	il->server->runJS(ret.variable % " = " % web.variable % ".copy()");

	return ret;
}

memory::WebElement Element::filter(const QString & selector) {
	memory::WebElement web = getValue().value<memory::WebElement>();
	memory::WebElement ret;
	QString            escaped = selector;

	escaped.replace("'", "\\'");
	ret.variable = getNewId();
	ret.selector = web.selector % " (filter) " % selector;

	ret.count = il->server
				  ->runJS(
					"(" % ret.variable % " = " % web.variable % ".filter('" %
					escaped % "')).length")
				  .toInt();

	return ret;
}

memory::WebElement Element::filter(const QString & context, bool asfragment) {
	memory::WebElement web = getValue().value<memory::WebElement>();
	memory::WebElement ret;
	QString            escaped = context;

	escaped.replace("'", "\\'");
	ret.variable = getNewId();
	ret.selector = web.selector % " (filtered by " %
				   (asfragment ? "fragment" : "content") % ") " % context;
	ret.count =
	  il->server
		->runJS(
		  "(" % ret.variable % " = " % web.variable % ".filterByContent('" %
		  escaped % "', " % (asfragment ? "true" : "false") % ")).length")
		.toInt();

	return ret;
}

memory::WebElement Element::get(int index) {
	memory::WebElement web = getValue().value<memory::WebElement>();
	memory::WebElement ret;
	QString            indexStr = QString::number(index);

	if (index < 0 || index >= web.count) {
		il->vm->exception({-8, "Index " % indexStr % " is out of bounds [0.." %
								 QString::number(web.count) % ")"});
		return ret;
	}

	ret.variable = getNewId();
	ret.selector = web.selector % "[" % indexStr % "]";
	ret.count    = 1;

	il->server->runJS(
	  ret.variable % " = nm(" % web.variable % "[" % indexStr % "])");

	return ret;
}

memory::WebElement Element::query(const QString & selector) {
	return queryBackEnd("qs", selector);
}

memory::WebElement Element::queryAll(const QString & selector) {
	return queryBackEnd("qsAll", selector);
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
	return domTrans(QStringLiteral("closest"), '"' % selector % '"');
}

void Element::addClass(const QString & className) {
	memory::WebElement web     = getValue().value<memory::WebElement>();
	QString            escaped = className;

	escaped.replace("'", "\\'");
	il->server->runJS(web.variable % ".add_class('" % escaped % "')");
}

void Element::removeClass(const QString & className) {
	memory::WebElement web     = getValue().value<memory::WebElement>();
	QString            escaped = className;

	escaped.replace("'", "\\'");
	il->server->runJS(web.variable % ".remove_class('" % escaped % "')");
}

bool Element::hasClass(const QString & className) {
	memory::WebElement web     = getValue().value<memory::WebElement>();
	QString            escaped = className;

	if (!isSingle(web)) {
		return false;
	}

	escaped.replace("'", "\\'");
	newValue =
	  il->server->runJS(web.variable % ".has_class('" % escaped % "')");

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
	if (args.length() == 0) {
		newValue   = isValid();
		newContext = new Bool{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
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
		newContext = new Element{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Element::runFilter(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		newValue =
		  QVariant::fromValue(filter(args[0].object->getValue().toString()));
		newContext = new Element{il, newValue, true};
	}
	if (
	  args.length() == 2 && args[0].object->type() == memory::Type::String &&
	  args[1].object->type() == memory::Type::Bool) {
		newValue   = QVariant::fromValue(filter(
		  args[0].object->getValue().toString(),
		  args[1].object->getValue().toInt()));
		newContext = new Element{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String> or <String, bool>"));
	}
}

void Element::runGet(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::Int) {
		newValue = QVariant::fromValue(get(args[0].object->getValue().toInt()));
		newContext = new Element{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

void Element::runQuery(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		newValue =
		  QVariant::fromValue(query(args[0].object->getValue().toString()));
		newContext = new Element{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

void Element::runQueryAll(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		newValue =
		  QVariant::fromValue(queryAll(args[0].object->getValue().toString()));
		newContext = new Element{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

void Element::runNext(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = QVariant::fromValue(next());
		newContext = new Element{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Element::runPrev(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = QVariant::fromValue(prev());
		newContext = new Element{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Element::runParent(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = QVariant::fromValue(parent());
		newContext = new Element{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Element::runChild(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::Int) {
		newValue =
		  QVariant::fromValue(child(args[0].object->getValue().toInt()));
		newContext = new Element{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<Int>"));
	}
}

void Element::runClosest(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		newValue =
		  QVariant::fromValue(closest(args[0].object->getValue().toString()));
		newContext = new Element{il, newValue, true};
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
		newContext = new Bool{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}



bool Element::isSingle(memory::WebElement & web) {
	if (web.count != 1) {
		if (web.count == 0) {
			il->vm->exception(
			  {-5, QStringLiteral("Element collection `%1` is null")
					 .arg(web.selector)});
		}
		else {
			il->vm->exception(
			  {-4,
			   QStringLiteral("Element collection `%1` contains several items")
				 .arg(web.selector)});
		}
		return false;
	}

	return true;
}

memory::WebElement Element::queryBackEnd(
  const QString & qsFunc, const QString & selector) {

	memory::WebElement web = getValue().value<memory::WebElement>();
	memory::WebElement ret;

	ret.variable = getNewId();
	ret.selector = web.selector % " " % selector;

	ret.count = il->server
				  ->runJS(
					"(" % ret.variable % " = " % web.variable % "." % qsFunc %
					"(\"" % selector % "\")).length")
				  .toInt();

	return ret;
}

memory::WebElement Element::domTrans(
  const QString & method, const QString & arg) {

	memory::WebElement web = getValue().value<memory::WebElement>();
	memory::WebElement ret;

	ret.variable = getNewId();
	ret.selector = web.selector % " -> " % method % "(" % arg % ")";

	ret.count = il->server
				  ->runJS(
					"(" % ret.variable % " = " % web.variable % "." % method %
					"(" % arg % ")).length")
				  .toInt();

	return ret;
}



Context * Element::runProperty(Prefix prefix, const QString & name) {
	if (prefix == Prefix::None) {
		auto it = properties.find(name);

		if (it != properties.end()) {
			(this->*it.value())();
		}
		else {
			Value::runProperty(prefix, name);
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
		Value::runMethod(name, args);
	}

	return newContext;
}



memory::Type Element::type() const {
	return memory::Type::Element;
}


bool Element::toBool() {
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

}  // namespace icL::context::value
