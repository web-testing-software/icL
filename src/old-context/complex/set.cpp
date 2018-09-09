#include "set.h"

namespace icL::context::complex {

Set::Set() {}

memory::SetPtr Set::make(memory::ParamList & params) {}

memory::SetPtr Set::join(
  const memory::SetPtr & set1, const memory::SetPtr & set2,
  const QStringList & fields) {}

memory::SetPtr Set::left(
  const memory::SetPtr & set1, const memory::SetPtr & set2,
  const QStringList & fields) {}

memory::SetPtr Set::right(
  const memory::SetPtr & set1, const memory::SetPtr & set2,
  const QStringList & fields) {}

memory::SetPtr Set::center(
  const memory::SetPtr & set1, const memory::SetPtr & set2,
  const QStringList & fields) {}

void Set::runMake(memory::ArgList & args) {}

void Set::runJoin(memory::ArgList & args) {}

void Set::runLeft(memory::ArgList & args) {}

void Set::runRight(memory::ArgList & args) {}

void Set::runCenter(memory::ArgList & args) {}

bool Set::checkPrev(const Context * context) const {}

bool Set::canBeAtEnd() const {}

Context * Set::runMethod(const QString & name, memory::ArgList & args) {}

}  // namespace icL::context::complex
