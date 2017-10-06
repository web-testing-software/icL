#ifndef MEMORYSTATE_H
#define MEMORYSTATE_H

#include "datastate.h"


namespace vm {
namespace system {

class MemoryState : public DataState
{
public:
	MemoryState ();

	bool hasPrev () const;
	bool hasNext () const;

	MemoryState* getPrev () const;
	MemoryState* getNext () const;

private:
	MemoryState *prev_ms	= nullptr;
	MemoryState *next_ms	= nullptr;
};

class MemoryStateIterator
{
public:
	MemoryStateIterator ();

	MemoryState* state () const;

	void appendNewAfter ();
	void appendNewAtEnd ();
	void removeState ();

private:
	MemoryState *m_state = nullptr;
};

}
}

#endif // MEMORYSTATE_H
