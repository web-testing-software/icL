#ifndef icL_memory_StackState
#define icL_memory_StackState

#include "../structures/webelement.h"
#include "datastate.h"


/**
 *  icL
 *  |- app
 *  |- context
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
 *  '-> memory
 */
namespace icL::memory {

/**
 * @brief The StackState class
 */
class StackState : public DataState
{
public:
	StackState(StackState * prev);
	virtual ~StackState();

	void setWebElement(const QString & name, WebElement & webElement);

	// Stack functions
	StackState * getPrev();
	bool         isLast();
	QVariant     getStackValue();
	//	int getStackLevel ();

	// This function was designed for stats
	//	static int getMaxStackLevel ();

private:
	StackState * prev_ss = nullptr;
	//	int stackLevel;

	//	static int maxStackLevel;
};

class StackStateIt
{
public:
	StackStateIt();
	~StackStateIt();

	StackState * stack();

	void openNewStack();
	void closeStack();

	StackState * getContainer(const QString & name);

	/// Mass effect despercated, to be removed later
	// Mass effect functions, with automatic iterations
	//	bool contains (const QString &name);
	//	bool checkType (const QString &name, DataState::Type &type);
	//	QVariant getValue (const QString &name);

	void clear();

private:
	StackState * m_stack = nullptr;
};

}  // namespace icL::memory

#endif  // icL_memory_StackState