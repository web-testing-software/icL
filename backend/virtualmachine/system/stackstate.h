#ifndef STACKSTATE_H
#define STACKSTATE_H

#include "../../functions/webelement.h"
#include "logic/logicblock.h"
#include "datastate.h"



namespace vm {
namespace system {

class StackState : public DataState
{
public:
	StackState (int stackLevel);

	// Additional functions to work with web elements
	void setWebElement (const QString &name, WebElement webElement);
	WebElement getWebElement (const QString &name);
	bool isWebElement (const QString &name);

	// Stack functions
	StackState* getPrev ();
	bool isLast ();
	QVariant getStackValue ();
	int getSearchedCommand ();
	LogicBlock* getLogicBlock ();
	int getStackLevel ();

	// This function was designed for stats
	static int getMaxStackLevel ();

private:
	QMap <QString, WebElement> webElementMap;
	StackState *prev_ss = nullptr;
	int searchedCommand = 0;
};

class StackStateIterator
{
public:
	StackStateIterator ();

	StackState* stack ();

	void openNewStack ();
	void closeStack ();

	// Mass effect functions, with automatic iterations
	bool checkType (const QString &name, StackState::Type &type);
	bool isWebElement (const QString &name);
	WebElement getWebElement (const QString &name);
	QVariant getValue (const QString &name);

private:
	StackState *m_stack;
};

}
}

#endif // STACKSTATE_H
