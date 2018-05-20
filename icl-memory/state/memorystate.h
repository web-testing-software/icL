#ifndef icL_memory_MemoryState
#define icL_memory_MemoryState

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
 *  '- @namespace memory
 */
namespace icL::memory {

/**
 * @brief The MemoryState class - gloabal memory data unit
 */
class MemoryState : public DataState
{
public:
	MemoryState();
	virtual ~MemoryState();

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
	MemoryStateIt();
	~MemoryStateIt();

	MemoryState * state() const;

	/// Doesn't delete the commented code, it will be uncommented in the
	/// version 1.2

	//	void iterateToFirst ();
	//	void iterateToLast ();

	//	void appendNewAfter ();
	//	void appendNewAtEnd ();
	//	void removeState ();

	//	void clear ();

private:
	MemoryState * m_state = nullptr;
};

}  // namespace icL::memory

#endif  // icL_memory_MemoryState
