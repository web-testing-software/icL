#include "functioncontainer.h"

namespace vm::memory {

FunctionContainer::FunctionContainer () {

}

Function& FunctionContainer::getFunction (const QString &name) {
	return fmap [name];
}

bool FunctionContainer::contains (const QString &name) {
	return fmap.contains (name);
}

void FunctionContainer::registerFunction (const QString &name, Function &func) {
	fmap.insert (name, func);
}

}
