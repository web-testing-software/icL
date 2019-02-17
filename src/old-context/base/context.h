#ifndef icL_context_Context
#define icL_context_Context

#include <icl-memory/interlevel/node.h>
#include <icl-memory/structures/exception.h>
#include <icl-memory/structures/functioncontainer.h>
#include <icl-memory/structures/return.h>
#include <icl-memory/structures/steptype.h>

#include <functional>

/**
 * The icL.context namespace is dedicated for all semantic tokens
 */
namespace icL::context {

namespace object {
class Object;
}

/**
 * \~english @brief The Role enum defines the role of context
 */
enum class Role {
	NoRole,       ///< \~english Default role
	Object,       ///< \~english Variable or constant
	If,           ///< \~english `if` token
	Else,         ///< \~english `else` token
	Exists,       ///< \~english `exists` and `if exists` tokens
	Slot,         ///< \~english `slot` token
	Code,         ///< \~english `{}` token
	ForAny,       ///< \~english `()` and `for any()` tokens
	DOM,          ///< \~english `_dom` system variable
	Tab,          ///< \~english `_tab` system variable
	Property,     ///< \~english property token
	Method,       ///< \~english method token
	Alternative,  ///< \~english ~deprecated~ will be removed later
	Assign,       ///< \~english `=` token
	Function,     ///< \~english function token
	Argument,     ///< \~english ~deprecated~ the right name is Parameter
	JsValue,      ///< \~english `$value` token
	JsFile        ///< \~english `$file` token
};

/**
 * \~english @brief The Prefix enum defines the prefixes of web element
 * properties
 */
enum class Prefix {
	None,  ///< \~english no prefix
	Attr,  ///< \~english attr- prefix
	Data,  ///< \~english data- prefix
	Css,   ///< \~english css- prefix
	Js     ///< \~english js- prefix
};

/**
 * \~english @brief The Context class represents a semantic token in icL
 */
class Context : public memory::Node
{

public:
	/**
	 * \~english
	 * @brief Context calls the memory.Node constructor
	 * @param il is a memory.node constructor argument
	 */
	Context(memory::InterLevel * il);

	/**
	 * \~english @brief ~Context defines a virtual default contructor
	 */
	virtual ~Context() = default;

	/**
	 * \~english
	 * @brief checkPrev checks order of contexts
	 * @param context is the last context of current context list, or nullptr
	 * @return true if the order is right, false - the order is wrong
	 *
	 * Before adding a new node, need to check the compability with the last
	 * context in current context list, if the new context is not compatible
	 * will be generated a semantic error.
	 */
	virtual bool checkPrev(const Context * context) const = 0;

	/**
	 * \~english
	 * @brief canBeAtEnd check if the last context may be positioned like the
	 * last context
	 * @return true if any command may ends with this semantic token, otherwise
	 * false
	 *
	 * After colecting of semantic tokens, need to check if may exist a command
	 * which can be ended by the last semanitic token, e.g. the assign operator
	 * may not be at end of command.
	 */
	virtual bool canBeAtEnd() const = 0;

	/**
	 * \~english
	 * @brief isRightToLeft defines the right associations of operators
	 * @return true if operator has right association, otherwise false
	 */
	virtual bool isRightToLeft() const;

	/**
	 * \~english
	 * @brief isExecutable defines the ready state of semantic token
	 * @return true if the token is ready to be executed right now, otherwise
	 * false
	 */
	virtual bool isExecutable() const;

	/**
	 * \~english
	 * @brief execute executes a mini-step, a step-in or a step-out
	 * @return the type of executed step
	 */
	virtual memory::StepType::Value execute();


	/**
	 * \~english
	 * @brief getNewContext return the new context pointer
	 * @return a pointer the new created context
	 */
	Context * getNewContext() const;

	/**
	 * \~english
	 * @brief getBeginContext needs to be overrided in child classes
	 * @return the begin of context interval to remove
	 */
	virtual Context * getBeginContext();

	/**
	 * \~english
	 * @brief getEndContext needs to be overrided in child classes
	 * @return the end of context interval to remove
	 */
	virtual Context * getEndContext();


	/**
	 * \~english
	 * @deprecated will be removed in final release
	 * @brief hasValue was used for alternative
	 * @return a bool
	 */
	virtual bool hasValue() const;

	/**
	 * \~english
	 * @brief runProperty returns the value of property, a part of high-level
	 * interface
	 * @param prefix is the prefix of property, web elements has prefixed
	 * properties
	 * @param name is the name of requested property
	 * @return the property value like a context.object.* class
	 */
	virtual Context * runProperty(Prefix prefix, const QString & name);

	/**
	 * \~english
	 * @brief runMethod runs a method of object, a part of high-level interface
	 * @param name the name of property to run
	 * @param args is the arguments of method
	 * @return the returned value like a context.object.* class
	 */
	virtual Context * runMethod(const QString & name, memory::ArgList & args);


	/**
	 * \~english
	 * @brief role returns the role of semantic token
	 * @return the role of semantic token
	 */
	Role role() const;

	/**
	 * \~english
	 * @brief prev returns the pointer to the previous token in liked list
	 * @return the pointer to the previous token in liked list
	 */
	Context * prev() const;

	/**
	 * \~english
	 * @brief next returns the pointer to the next token in liked list
	 * @return returns the pointer to the next token in liked list
	 */
	Context * next() const;


	/**
	 * \~english
	 * @brief replaceWith relace the token in liked with by "context"
	 * @param context is the new context to insert in liked list
	 */
	void replaceWith(Context * context);

	/**
	 * \~english
	 * @brief link links the new context with the last token in linked list
	 * @param context is the token which needs to be pasted at end of linked
	 * list
	 */
	void link(Context * context);

	/**
	 * \~english
	 * @brief link replaces an interval with a new context
	 * @param c0 is the begin of interval
	 * @param c1 is the new context
	 * @param c2 is the end of interval
	 */
	static void link(Context * c0, Context * c1, Context * c2);


	/**
	 * \~english
	 * @brief isResultative checks if the token returns a context.object.*
	 * object
	 * @return true if the token is resultative, otherwise false
	 */
	virtual bool isResultative() const;

	/**
	 * \~english
	 * @brief isComplex checks if the token is a system uncreatable complex
	 * object
	 * @return true if the token is complex, otherwise false
	 */
	virtual bool isComplex() const;


	/**
	 * \~english
	 * @brief fromValue creates a context from a variant value
	 * @param value is the value to copy in context object
	 * @return a pointer to created context object
	 */
	value::Value * fromValue(const QVariant & value);

	/**
	 * \~english
	 * @brief fromValue creates a context from a variant value
	 * @param il is requested to create new nodes/contexts
	 * @param value is the value to copy in context object
	 * @return a pointer to created context object
	 */
	static value::Value * fromValue(
	  memory::InterLevel * il, const QVariant & value);

	/**
	 * \~english
	 * @brief fromValue creates a context from a variant value
	 * @param il is requested to create new nodes/contexts
	 * @param ds is the data state from which the value will be extracted
	 * @param name is the name of variable to extract
	 * @return a pointer to created context object
	 */
	static value::Value * fromValue(
	  memory::InterLevel * il, memory::DataState * ds, const QString & name);

	/**
	 * \~english
	 * @brief getBeginCursorPosition gets the cursor position of the begin of
	 * semantic token in code
	 * @return the cursor position of the begin of semantic token in code
	 */
	int getBeginCursorPosition();

	/**
	 * \~english
	 * @brief getEndCursorPosition gets the cursor position of the end of
	 * semantic token in code
	 * @return the cursor position of the end of semantic token in code
	 */
	int getEndCursorPosition();

	/**
	 * \~english
	 * @brief setCursorPositions sets up the bounds of semantic token in code
	 * @param begin is the begin of semantic token
	 * @param end is the end of semantic token
	 * @warning to be called only from icL.cpu module
	 */
	void setCursorPositions(int begin, int end);

protected:
	/**
	 * \~english
	 * @brief getFirst gets the first token in linked list
	 * @return pointer to the first token in liken list
	 */
	Context * getFirst();

	/**
	 * \~english
	 * @brief getLast gets the last token in linked list
	 * @return pointer to the last token in linked list
	 */
	Context * getLast();

	/**
	 * \~english
	 * @brief sendWrongArglist sends "Wrong arg list <??> expected <??>"
	 * @param args is the getted arguments
	 * @param expected is the expected arguments
	 */
	void sendWrongArglist(memory::ArgList & args, const QString & expected);

	/**
	 * @deprecated will be removed in final release
	 * @brief varToJsString converts a variant to a string representation
	 * @param var is a variant
	 * @return a string
	 */
	QString varToJsString(const QVariant & var);

protected:
	/**
	 * \~english @brief m_role is the role of semantic token
	 */
	Role m_role = Role::NoRole;

	/**
	 * \~english @brief m_prev is a pointer to the previous token in linked list
	 */
	Context * m_prev = nullptr;

	/**
	 * \~english @brief m_next is a pointer to the next token in linked list
	 */
	Context * m_next = nullptr;

	/**
	 * \~english @brief newContext is a pointer the result token, usually
	 * nullptr
	 */
	Context * newContext = nullptr;

	/**
	 * \~english @brief newValue is the value of result like a variant
	 */
	QVariant newValue;

	/**
	 * \~english @brief beginCursorPosition is the begin position of token in
	 * code
	 */
	int beginCursorPosition;

	/**
	 * \~english @brief endCursorPostion is the end position of token in code
	 */
	int endCursorPostion;
};

#ifdef icL_debug

/**
 * \~english
 * @brief roleToString converts the role enum value to a string with the name
 * @param role is the role value
 * @return a string with the role name
 * @warning this function is aviable just in debug buils
 */
QString roleToString(Role role);

#endif

}  // namespace icL::context

#endif  // icL_context_Context
