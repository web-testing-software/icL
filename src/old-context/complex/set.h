#ifndef icL_context_complex_Set
#define icL_context_complex_Set

#include "complex.h"

#include <icl-memory/structures/set.h>



namespace old::context::complex {

class Set : public Complex
{
public:
	Set();

	memory::SetPtr make(memory::ParamList & params);

	memory::SetPtr join(
	  const memory::SetPtr & set1, const memory::SetPtr & set2,
	  const QStringList & fields);
	memory::SetPtr left(
	  const memory::SetPtr & set1, const memory::SetPtr & set2,
	  const QStringList & fields);
	memory::SetPtr right(
	  const memory::SetPtr & set1, const memory::SetPtr & set2,
	  const QStringList & fields);
	memory::SetPtr center(
	  const memory::SetPtr & set1, const memory::SetPtr & set2,
	  const QStringList & fields);

private:
	void runMake(memory::ArgList & args);

	void runJoin(memory::ArgList & args);
	void runLeft(memory::ArgList & args);
	void runRight(memory::ArgList & args);
	void runCenter(memory::ArgList & args);

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool canBeAtEnd() const override;

	Context * runMethod(const QString & name, memory::ArgList & args) override;
};

}  // namespace old::context::complex

#endif  // icL_context_complex_Set
