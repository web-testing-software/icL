#ifndef MEMORYSTATE_H
#define MEMORYSTATE_H

#include "datastate.h"


namespace vm {
namespace system {

class MemoryState : public DataState
{
public:
	MemoryState ();
	virtual ~MemoryState ();

	bool hasPrev () const;
	bool hasNext () const;

	MemoryState* getPrev () const;
	MemoryState* getNext () const;

	void setPrev (MemoryState *state);
	void setNext (MemoryState *state);

private:
	MemoryState *prev_ms	= nullptr;
	MemoryState *next_ms	= nullptr;
};

class MemoryStateIterator
{
public:
	MemoryStateIterator ();

	MemoryState* state () const;

	void iterateToFirst ();
	void iterateToLast ();

	void appendNewAfter ();
	void appendNewAtEnd ();
	void removeState ();

	void clear ();

private:
	MemoryState *m_state = nullptr;
};

}
}

#endif // MEMORYSTATE_H
