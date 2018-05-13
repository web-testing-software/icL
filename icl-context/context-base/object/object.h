#ifndef OBJECT_H
#define OBJECT_H

#include <context-base/context.h>

#include <icl-memory/state/datastate.h>



namespace vm::context::object {

class Object : public Context
{
public:
	Object(memory::DataState* container, const QString& varName);
	Object(const QVariant& rvalue, bool readonly = false);
	Object(const Object* const object);

	memory::Type type() const;

	virtual bool isRValue() const;
	virtual bool isReadOnly() const;
	virtual bool isLValue() const;
	virtual bool isLink() const;

	virtual QVariant getValue() const;
	virtual void     setValue(const QVariant& value);

	const QString& getVarName() const;

public:
	// Cast functions
	virtual bool              toBoolean() = 0;
	virtual int               toInt()     = 0;
	virtual double            toDouble()  = 0;
	virtual const QString     toString()  = 0;
	virtual const QStringList toList()    = 0;

private:
	void runToBoolean(memory::ArgList& args);
	void runToInt(memory::ArgList& args);
	void runToDouble(memory::ArgList& args);
	void runToString(memory::ArgList& args);
	void runToList(memory::ArgList& args);

protected:
	void sendWrongCast(const QString& to);
	void sendCastFailed(const QString& value, const QString& type);
	void runCast(const QString& name, memory::ArgList& args);

protected:
	// LValue
	memory::DataState* container = nullptr;
	QString            varName;

	// RValue
	QVariant rvalue;
	bool     readonly = false;

	enum class Value { L, R } value;

	// Context interface
public:
	bool checkPrev(const Context* context) const override;
	bool canBeAtEnd() const override;

	bool isResultative() const override;
};

}  // namespace vm::context::object

#endif  // OBJECT_H
