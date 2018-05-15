#ifndef ELEMENT_H
#define ELEMENT_H

#include "object.h"

#include <icl-memory/structures/webelement.h>


/**
 *  icL
 *  |- app
 *	|- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- @namespace object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::context::object {

class String;
class Int;

class Element : public Object
{
public:
	Element(memory::DataState * container, const QString & varName);
	Element(const QVariant & rvalue, bool readonly = false);
	Element(const Object * const object);

	// Id generator
private:
	static int idAsInt;

	// Use by _dom:query and _dom:queryAll
public:
	static QString getNewId();

	// properties
public:
	// R/W properties will return a r/w object
	int length();

	String * html();
	String * text();
	Int *    width();
	Int *    height();

	// Read only properties
	bool visible();
	bool clickable();

	// Prefixed properties
	Object * prop(const QString & name);
	String * attr(const QString & name);
	String * data(const QString & name);
	String * css(const QString & name);

private:
	void runLength();

	void runHTML();
	void runText();
	void runWidth();
	void runHeight();

	void runVisible();
	void runClickable();

	void runProp(const QString & name);
	void runAttr(const QString & name);
	void runData(const QString & name);
	void runCSS(const QString & name);

	// methods
public:
	void scrollTo();
	void click();
	void sendKeys(const QString & keys);
	void CtrlV(const QString & text);
	bool isValid();

	void add(memory::WebElement element);

	memory::WebElement copy();
	memory::WebElement filter(const QString & selector);
	memory::WebElement filter(const QString & context, bool asfragment);
	memory::WebElement get(int index);

	memory::WebElement next();
	memory::WebElement prev();
	memory::WebElement parent();
	memory::WebElement child(int index);
	memory::WebElement closest(const QString & selector);

	void addClass(const QString & className);
	void removeClass(const QString & className);
	bool hasClass(const QString & className);

private:
	void runScrollTo(memory::ArgList & args);
	void runClick(memory::ArgList & args);
	void runSendKeys(memory::ArgList & args);
	void runCtrlV(memory::ArgList & args);
	void runIsValid(memory::ArgList & args);

	void runAdd(memory::ArgList & args);

	void runCopy(memory::ArgList & args);
	// both C++ filter functions are closed by this one
	void runFilter(memory::ArgList & args);
	void runGet(memory::ArgList & args);

	void runNext(memory::ArgList & args);
	void runPrev(memory::ArgList & args);
	void runParent(memory::ArgList & args);
	void runChild(memory::ArgList & args);
	void runClosest(memory::ArgList & args);

	void runAddClass(memory::ArgList & args);
	void runRemoveClass(memory::ArgList & args);
	void runHasClass(memory::ArgList & args);

private:
	bool isSingle(memory::WebElement & web);
	memory::WebElement domTrans (const QString &method, const QString &arg);

signals:
	void requestClick(int x, int y);
	void requestKeys(QString keys);

	// Context interface
public:
	Context * runProperty(Prefix prefix, const QString & name) override;
	Context * runMethod(const QString & name, memory::ArgList & args) override;

	// Object interface
public:
	memory::Type type() const override;

	bool              toBoolean() override;
	int               toInt() override;
	double            toDouble() override;
	const QString     toString() override;
	const QStringList toList() override;
};

}  // namespace icL::context::object

#endif  // ELEMENT_H
