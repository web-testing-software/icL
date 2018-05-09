#ifndef MEMORYSTATE_H
#define MEMORYSTATE_H

#include "datastate.h"


namespace vm::memory {

/**
 * @brief The MemoryState class - gloabal memory data unit
 */
class MemoryState : public DataState
{
public:
	MemoryState ();
	virtual ~MemoryState ();

//	bool hasPrev () const;
//	bool hasNext () const;

//	MemoryState* getPrev () const;
//	MemoryState* getNext () const;

//	void setPrev (MemoryState *state);
//	void setNext (MemoryState *state);

private:
//	MemoryState *prev_ms	= nullptr;
//	MemoryState *next_ms	= nullptr;
};

/**
 * @brief The MemoryStateIterator class - iterator releasing the data structore
 */
class MemoryStateIt
{
public:
	MemoryStateIt ();
	~MemoryStateIt ();

	MemoryState* state () const;

	/// Doesn't delete the commented code, it will be uncommented in the version 1.2

//	void iterateToFirst ();
//	void iterateToLast ();

//	void appendNewAfter ();
//	void appendNewAtEnd ();
//	void removeState ();

//	void clear ();

private:
	MemoryState *m_state = nullptr;
};

}

#endif // MEMORYSTATE_H