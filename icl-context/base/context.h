#ifndef VM_CONTEXT_CONTEXT_H
#define VM_CONTEXT_CONTEXT_H

#include <icl-memory/structures/exception.h>
#include <icl-memory/structures/functioncontainer.h>
#include <icl-memory/structures/return.h>

#include <functional>

#include <icl-memory/interlevel/node.h>

/**
 *  icL
 *  |- app
 *	|- @namespace context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::context {

namespace object {
class Object;
}

enum class Role {
	NoRole,
	Object,
	If,
	Else,
	Exists,
	Slot,
	Code,
	ForAny,
	DOM,
	Tab,
	Property,
	Method,
	Alternative,
	Assign,
	Function,
	Argument,
	JsValue,
	JsFile
};

enum class Prefix { None, Attr, Data, Css };

class Context : public memory::Node
{

public:
	Context(memory::InterLevel * il);

	virtual bool checkPrev(const Context * context) const = 0;
	virtual bool canBeAtEnd() const                       = 0;
	virtual bool isRightToLeft() const;
	virtual bool isExecuable() const;
	virtual bool execute();

	Context *         getNewContext() const;
	virtual Context * getBeginContext();
	virtual Context * getEndContext();

	virtual bool      hasValue() const;
	virtual Context * runProperty(Prefix prefix, const QString & name);
	virtual Context * runMethod(const QString & name, memory::ArgList & args);

	Role      role() const;
	Context * prev() const;
	Context * next() const;
	void      replaceWith(Context * context);

	virtual bool isResultative() const;
	virtual bool isComplex() const;

	object::Object * fromValue(const QVariant & value);

protected:
	Context * getFirst();
	Context * getLast();

	void sendWrongArglist(memory::ArgList & args, const QString & expected);

	QString varToJsString(const QVariant & var);

protected:
	Role m_role = Role::NoRole;

	Context * m_prev = nullptr;
	Context * m_next = nullptr;

	Context * newContext = nullptr;
	QVariant  newValue;
};


}  // namespace icL::context

#endif  // VM_CONTEXT_CONTEXT_H
