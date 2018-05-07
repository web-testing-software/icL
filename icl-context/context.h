#ifndef VM_CONTEXT_CONTEXT_H
#define VM_CONTEXT_CONTEXT_H

#include <QObject>
#include <functional>

namespace vm::context {

enum class Role {
	If, Else,
	Exists, Slot,
	Code, Isolated,
	Object,
	DOM, Tab,
	Property, Method,
	Alternative, Assign,
	Function, Argument
};

class Context : public QObject
{

public:
	Context ();

	virtual Context* getNewContext ();
	virtual Context* getBeginContext ();
	virtual Context* getEndContext ();

	virtual bool isRightToLeft ();
	virtual bool isExecuable ();
	virtual bool execute ();

	virtual bool hasValue ();
	virtual void runProperty (const QString &name);
	virtual void runMethod (const QString &name);

protected:
	bool isResultative ();


signals:
	void exception (int code, const QString &message);
	void interrupt (QString *, int, int, std::function <void ( QVariant& )> );

public slots:
	void repeat (QString *str, int begin, int end, std::function <void ( QVariant& )> func);


protected:
	Role role;
};


} // namespace

#endif // VM_CONTEXT_CONTEXT_H
