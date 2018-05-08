#ifndef VM_CONTEXT_CONTEXT_H
#define VM_CONTEXT_CONTEXT_H

#include <QObject>
#include <functional>

namespace vm::context {

enum class Role {
	NoRole, Object,
	If, Else,
	Exists, Slot,
	Code, ForAny,
	DOM, Tab,
	Property, Method,
	Alternative, Assign,
	Function, Argument
};

class Context : public QObject
{

public:
	Context ();

	virtual Context* getNewContext () const;
	virtual Context* getBeginContext () const;
	virtual Context* getEndContext () const;

	virtual bool checkPrev (const Context *context) const = 0;
	virtual bool isRightToLeft () const;
	virtual bool isExecuable () const;
	virtual bool execute () const;

	virtual bool hasValue () const;
	virtual void runProperty (const QString &name);
	virtual void runMethod (const QString &name);

	Role role () const;
	Context* prev () const;
	Context* next () const;

	bool isResultative () const;

signals:
	void exception (int code, const QString &message) const;
	void interrupt (QString *, int, int, std::function <void ( QVariant& )> ) const;

public slots:
	void repeatException (int code, const QString &message);
	void repeat (QString *str, int begin, int end, std::function <void ( QVariant& )> func);


protected:
	Role m_role = Role::NoRole;

	Context *m_prev = nullptr;
	Context *m_next = nullptr;

	Context *newContext = nullptr;
};


} // namespace

#endif // VM_CONTEXT_CONTEXT_H
