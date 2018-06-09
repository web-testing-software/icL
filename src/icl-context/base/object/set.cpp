#include "set.h"

namespace icL::context::object {

Set::Set(
  memory::InterLevel * il, memory::DataState * container,
  const QString & varName) {}

Set::Set(memory::InterLevel * il, const QVariant & rvalue, bool readonly) {}

const QHash<QString, void (Set::*)()> Set::properties = Set::initProperties();

const QHash<QString, void (Set::*)(memory::ArgList &)> Set::methods =
  Set::initMethods();

const QHash<QString, void (Set::*)()> Set::initProperties() {}

const QHash<QString, void (Set::*)(memory::ArgList &)> Set::initMethods() {}

int Set::length() {}

bool Set::empty() {}

void Set::runLength() {}

void Set::runEmpty() {}

void Set::prepend(const Row & row) {}

void Set::append(const Row & row) {}

void Set::insert(const Row & row) {}

void Set::merge(const Table & table) {}

void Set::popFront() {}

void Set::popBack() {}

void Set::removeAt(int index) {}

void Set::remove(const Row & row) {}

Row Set::get(int index) {}

int Set::ref(const Row & value) {}

void Set::runPrepend(memory::ArgList & args) {}

void Set::runAppend(memory::ArgList & args) {}

void Set::runInsert(memory::ArgList & args) {}

void Set::runMerge(memory::ArgList & args) {}

void Set::runPopFront(memory::ArgList & args) {}

void Set::runPopBack(memory::ArgList & args) {}

void Set::runRemoveAt(memory::ArgList & args) {}

void Set::runRemove(memory::ArgList & args) {}

void Set::runGet(memory::ArgList & args) {}

void Set::runRef(memory::ArgList & args) {}

Context * Set::runProperty(Prefix prefix, const QString & name) {}

Context * Set::runMethod(const QString & name, memory::ArgList & args) {}

memory::Type Set::type() const {}

bool Set::toBoolean() {}

int Set::toInt() {}

double Set::toDouble() {}

const QString Set::toString() {}

const QStringList Set::toList() {}

}  // namespace icL::context::object
