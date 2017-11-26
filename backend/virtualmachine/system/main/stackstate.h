#ifndef STACKSTATE_H
#define STACKSTATE_H

#include "../../../functions/webelement.h"
#include "datastate.h"



namespace vm {
namespace main {

class StackState : public DataState
{
public:
	enum class StackType {
		COMMOM_STACK,
		IF_STACK
	};

	StackState (StackState *prev, int stackLevel);
	virtual ~StackState ();

	void setWebElement (const QString &name, WebElement &webElement);

	// Stack functions
	StackState* getPrev ();
	bool isLast ();
	QVariant getStackValue ();
	int getStackLevel ();

	virtual bool tryToDestroy ();
	virtual void releaseCondition ();

	// This function was designed for stats
	static int getMaxStackLevel ();

	// DataState interface
	Type getType (const QString &name) override;
	bool checkType (const QString &name, Type &type) override;
	bool contains (const QString &name) override;
	QVariant getValue (const QString &name) override;

private:
	QMap <QString, WebElement> webElementMap;
	StackState *prev_ss = nullptr;
	int stackLevel;

	static int maxStackLevel;
};

class StackStateIterator
{
public:
	StackStateIterator ();

	StackState* stack ();

	void openNewStack (StackState::StackType stackType);
	void closeStack ();

	// Mass effect functions, with automatic iterations
	bool contains (const QString &name);
	bool checkType (const QString &name, DataState::Type &type);
	QVariant getValue (const QString &name);

	void clear ();

private:
	StackState *m_stack;
};

}
}

#endif // STACKSTATE_H
