#ifndef OBJECT_H
#define OBJECT_H

#include <context.h>

#include <icl-memory/state/datastate.h>



namespace vm::context::object {

class Object : public Context
{
public:
	Object (memory::DataState *container, const QString &varName);
	Object (const QVariant &rvalue, bool readonly = false);
	Object (const Object *const object);

	memory::Type type () const;
	virtual bool isRValue () const;
	virtual bool isReadOnly () const;
	virtual bool isLValue () const;
	virtual bool isLink () const;
	virtual QVariant getValue () const;
	virtual void setValue (QVariant &value);

protected:
	// LValue
	memory::DataState *container = nullptr;
	QString varName;

	// RValue
	QVariant rvalue;
	bool readonly = false;

	enum class Value { L, R } value;

	// Context interface
public:
	bool checkPrev (const Context *context) const override;
	bool canBeAtEnd () const override;
};

} // namespace

#endif // OBJECT_H
