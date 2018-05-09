#ifndef CODE_H
#define CODE_H

#include <context.h>

#include <icl-memory/structures/functioncontainer.h>



namespace vm::context::code {

class Code : public Context
{
public:
	Code ();

	const memory::CodeFragment& source() const;

protected:
	memory::CodeFragment m_source;

	// Context interface
public:
	bool checkPrev (const Context *context) const override;
	bool canBeAtEnd () const override;
	bool isExecuable () const override;

	Context* getBeginContext () override;
	Context* getEndContext () override;
};

} // namespace

#endif // CODE_H
