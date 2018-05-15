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

class Element : public Object
{
public:
	Element(memory::DataState* container, const QString& varName);
	Element(const QVariant& rvalue, bool readonly = false);
	Element(const Object* const object);

	// properties
public:
	// R/W properties will return a r/w object
	int length();

	Object* html();
	Object* text();
	Object* width();
	Object* height();

	// Read only properties
	bool visible();
	bool clickable();

private:
	void runLength();

	void runHTML();
	void runText();
	void runWidth();
	void runHeight();

	void runVisible();
	void runClickable();

	// methods
public:
	void scrollTo();
	void click();
	void sendKeys(const QString& keys);
	void CtrlV(const QString& text);
	bool isValid();

	void add(memory::WebElement element);

	memory::WebElement copy();
	memory::WebElement filter(const QString& selector);
	memory::WebElement filter(const QString& context, bool asfragment);
	memory::WebElement get(int index);

	memory::WebElement next();
	memory::WebElement prev();
	memory::WebElement parent();
	memory::WebElement child(int index);
	memory::WebElement closest(const QString& selector);

	void addClass(const QString& className);
	void removeClass(const QString& className);
	bool hasClass(const QString& className);

private:
	void runScrollTo(memory::ArgList& args);
	void runClick(memory::ArgList& args);
	void runSendKeys(memory::ArgList& args);
	void runCtrlV(memory::ArgList& args);
	void runIsValid(memory::ArgList& args);

	void runAdd(memory::ArgList& args);

	void runCopy(memory::ArgList& args);
	// both C++ filter functions are closed by this one
	void runFilter(memory::ArgList& args);
	void runGet(memory::ArgList& args);

	void runNext(memory::ArgList& args);
	void runPrev(memory::ArgList& args);
	void runParent(memory::ArgList& args);
	void runChild(memory::ArgList& args);
	void runClosest(memory::ArgList& args);

	void runAddClass(memory::ArgList& args);
	void runRemoveClass(memory::ArgList& args);
	void runHasClass(memory::ArgList& args);

private:
	bool isSingle(memory::WebElement &web);

	// Context interface
public:
	Context* runProperty(Prefix prefix, const QString& name) override;
	Context* runMethod(const QString& name, memory::ArgList& args) override;

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
