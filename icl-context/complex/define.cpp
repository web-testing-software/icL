#include "define.h"

namespace vm::context::complex {

Define::Define () {

}

bool Define::checkPrev (const Context *context) const {
	return context == nullptr;
}

bool Define::canBeAtEnd () const {
	return false;
}

bool Define::isRightToLeft () const {
	return true;
}

bool Define::isExecuable () const {
	return true;
}

bool Define::execute () {

}

Context * Define::getBeginContext () {
	return getFirst ();
}

Context * Define::getEndContext () {
	return getLast ();
}

Context * Define::runMethod (const QString &name, memory::ParamList &params) {

}

} // namespace
