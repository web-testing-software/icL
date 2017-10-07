#ifndef STACKSTATE_H
#define STACKSTATE_H

#include "../../../functions/webelement.h"
#include "../logic/main/logicblock.h"
#include "datastate.h"



namespace vm {
namespace system {

struct CommandsToSearch {           // By default it search:
	int command1	= 0x00000000;   //  0 - EOF
	int command2	= 0x80000000;   // -1 - Stack out
};

class StackState : public DataState
{
public:
	StackState (StackState *prev, int stackLevel);
	virtual ~StackState();

	// Stack functions
	StackState* getPrev ();
	bool isLast ();
	QVariant getStackValue ();
	CommandsToSearch getSearchedCommands ();
	void search (const CommandsToSearch &commands);
	int getStackLevel ();

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
	CommandsToSearch searchedCommands;
	int stackLevel;

	static int maxStackLevel;
};

class StackStateIterator
{
public:
	StackStateIterator ();

	StackState* stack ();

	void openNewStack ();
	void closeStack ();

	// Mass effect functions, with automatic iterations
	bool contains (const QString &name);
	bool checkType (const QString &name, StackState::Type &type);

private:
	StackState *m_stack;
};

}
}

#endif // STACKSTATE_H
