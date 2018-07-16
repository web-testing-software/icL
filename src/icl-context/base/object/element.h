#ifndef icl_context_object_Element
#define icl_context_object_Element


#include "object.h"

#include <icl-memory/structures/webelement.h>


namespace icL::context::object {

class String;
class Int;

/**
 * \~english @brief The Element class contains a web element reference.
 */
class Element : public Value
{
public:
	/**
	 * @brief Element calls the contructor of class Object
	 * @param il is a base contructor argument
	 * @param container is a base contructor argument
	 * @param varName is a base contructor argument
	 */
	Element(
	  memory::InterLevel * il, memory::DataState * container,
	  const QString & varName);

	/**
	 * @brief Element calls the contructor of class Object
	 * @param il is a base contructor argument
	 * @param rvalue is a base contructor argument
	 * @param readonly is a base contructor argument
	 */
	Element(
	  memory::InterLevel * il, const QVariant & rvalue, bool readonly = false);

	/**
	 * @brief Element calls the contructor of class Object
	 * @param il is a base contructor argument
	 * @param object is a base contructor argument
	 */
	Element(memory::InterLevel * il, const Value * const object);

	// Id generator
private:
	/**
	 * @deprecated will be replaced lated with a GUID generator
	 * @brief idAsInt - id generator for web elements
	 */
	static int idAsInt;

	// static
private:
	/**
	 * @brief non-prefixed properties list of <element>
	 */
	static const QHash<QString, void (Element::*)()> properties;

	/**
	 * @brief methods list of <element>
	 */
	static const QHash<QString, void (Element::*)(memory::ArgList &)> methods;

public:
	/**
	 * @brief initProperties is the initial list of icL properties
	 * @return a list of pairs (name of property, pointer to Element.*)
	 */
	static const QHash<QString, void (Element::*)()> initProperties();

	/**
	 * @brief initMethods is the initial list of icL methods
	 * @return a list of pairs (name of property, pointer to Element.*)
	 */
	static const QHash<QString, void (Element::*)(memory::ArgList &)>
	initMethods();

public:
	/**
	 * @deprecated will be replaced later with a GUID generator
	 * @brief getNewId is used by _dom:query and _dom:queryAll
	 * @return a new id
	 */
	static QString getNewId();

	// properties
	// R/W properties will return a r/w object
public:

	/**
	 * @brief length represents the number of element in container
	 * @return elements count
	 */
	int length();

	/**
	 * @brief html - nm().html()
	 * @return a r/w object
	 */
	String * html();

	/**
	 * @brief text - nm().text()
	 * @return a r/w object
	 */
	String * text();

	/**
	 * @brief width - nm().width()
	 * @return a r/w object
	 */
	Int *    width();

	/**
	 * @brief height - nm().width()
	 * @return a r/w object
	 */
	Int *    height();

	// Read only properties

	/**
	 * @brief visible - nm().visible()
	 * @return a r/o object
	 */
	bool visible();

	/**
	 * @brief clickable - nm().clickable()
	 * @return a r/o object
	 */
	bool clickable();

	// Prefixed properties
	/**
	 * @brief prop - nm().prop()
	 * @param name is the name of property
	 * @return a r/w object
	 */
	Value * prop(const QString & name);

	/**
	 * @brief attr - nm().attr()
	 * @param name is the name of attribute
	 * @return a r/w object
	 */
	String * attr(const QString & name);

	/**
	 * @brief data - nm().data()
	 * @param name is name of data-attribute
	 * @return a r/w object
	 * @warning aviable only in automation mode
	 */
	String * data(const QString & name);

	/**
	 * @brief css - nm().css()
	 * @param name is the name of css atributte
	 * @return a r/w object
	 */
	String * css(const QString & name);

private:
	/**
	 * @brief property middle level function
	 * @see length
	 */
	void runLength();

	/**
	 * @brief property middle level function
	 * @see html
	 */
	void runHTML();

	/**
	 * @brief property middle level function
	 * @see text
	 */
	void runText();

	/**
	 * @brief property middle level function
	 * @see width
	 */
	void runWidth();

	/**
	 * @brief property middle level function
	 * @see height
	 */
	void runHeight();

	/**
	 * @brief property middle level function
	 * @see visible
	 */
	void runVisible();

	/**
	 * @brief property middle level function
	 * @see clickable
	 */
	void runClickable();


	/**
	 * @brief property middle level function
	 * @param name is the name of property
	 * @see prop
	 */
	void runProp(const QString & name);

	/**
	 * @brief property middle level function
	 * @param name is the name of property
	 * @see attr
	 */
	void runAttr(const QString & name);

	/**
	 * @brief property middle level function
	 * @param name is the name of property
	 * @see data
	 */
	void runData(const QString & name);

	/**
	 * @brief property middle level function
	 * @param name is the name of property
	 * @see css
	 */
	void runCSS(const QString & name);

	// methods
public:
	void scrollTo();
	void click();
	void sendKeys(const QString & keys);
	void ctrlV(const QString & text);
	bool isValid();

	void add(memory::WebElement element);

	memory::WebElement copy();
	memory::WebElement filter(const QString & selector);
	memory::WebElement filter(const QString & context, bool asfragment);
	memory::WebElement get(int index);

	memory::WebElement query(const QString & selector);
	memory::WebElement queryAll(const QString & selector);
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

	void runQuery(memory::ArgList & args);
	void runQueryAll(memory::ArgList & args);
	void runNext(memory::ArgList & args);
	void runPrev(memory::ArgList & args);
	void runParent(memory::ArgList & args);
	void runChild(memory::ArgList & args);
	void runClosest(memory::ArgList & args);

	void runAddClass(memory::ArgList & args);
	void runRemoveClass(memory::ArgList & args);
	void runHasClass(memory::ArgList & args);

private:
	bool               isSingle(memory::WebElement & web);
	memory::WebElement queryBackEnd(
	  const QString & qsFunc, const QString & selector);
	memory::WebElement domTrans(const QString & method, const QString & arg);

	// Context interface
public:
	Context * runProperty(Prefix prefix, const QString & name) override;
	Context * runMethod(const QString & name, memory::ArgList & args) override;

	// Object interface
public:
	memory::Type type() const override;

	bool              toBool() override;
	int               toInt() override;
	double            toDouble() override;
	const QString     toString() override;
	const QStringList toList() override;
};

}  // namespace icL::context::object

#endif  // icl_context_object_Element
